/******************************************************************************
 * @file Blur.cpp
 * @brief Implementation file for image blurring techniques.
 *
 * Group name: Bisection
 * 
 * @authors
 * - Vera Fan (esemsc-3f9bc883)
 * - Jiawei Zhan (esemsc-jz1224)
 * - Simranjeet Singh (esemsc-ss2524)
 * - George Sokolik (esemsc-gts124)
 * - Qihan Zhang (esemsc-qz624)
 * - Yixiao Zheng (esemsc-yz1824)
 * - Miles Weberman (esemsc-mw2124)
 ******************************************************************************/
#include "Blur.h"
#include "../utils/MedianUtils.h"  // Include the custom median utility
#include <vector>        // For std::vector (used in kernel calculations and storing pixel values)
#include <cmath>         // For mathematical functions like std::exp (used in Gaussian blur)
#include <algorithm>     // For std::clamp
#include <stdexcept>     // For std::runtime_error (used for error handling)
#include <cstring>       // For std::memcpy (used for copying image data)


void Blur::applyBoxBlur(Image& img, int blurSize) {
    if (!img.getData()) throw std::runtime_error("Image data is null");
    int width = img.getWidth(), height = img.getHeight(), channels = img.getChannels();
    Image tempData(img);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::vector<int> sum(channels, 0);
            int count = 0;

            for (int ky = -blurSize; ky <= blurSize; ++ky) {
                for (int kx = -blurSize; kx <= blurSize; ++kx) {
                    // Clamp coordinates to stay within bounds
                    int nx = std::clamp(x + kx, 0, width - 1);
                    int ny = std::clamp(y + ky, 0, height - 1);

                    for (int ch = 0; ch < channels; ++ch) {
                        sum[ch] += img(nx, ny, ch);
                    }
                    ++count;
                }
            }

            for (int ch = 0; ch < channels; ++ch) {
                tempData(x,y,ch) = static_cast<unsigned char>(sum[ch] / count);
            }
        }
    }
    unsigned char* tempBuffer = new unsigned char[width * height * channels];
    std::memcpy(tempBuffer, tempData.getData(), width * height * channels);
    img.setData(tempBuffer, width, height, channels, img.getState());
}

void Blur::applyGaussianBlur(Image& img, double sigma, int kernelSize) {\
    if (!img.getData()) throw std::runtime_error("Image data is null");
    if (kernelSize % 2 == 0) ++kernelSize;  // Ensure kernel size is odd
    int radius = kernelSize / 2;
    Image tempData(img);
    
    // Compute Gaussian kernel (use 1D vector for better memory access)
    std::vector<double> kernel(kernelSize * kernelSize);
    
    // Compute Gaussian kernel
    double sum = 0.0, sigma2 = 2.0 * sigma * sigma;
    for (int y = -radius; y <= radius; ++y) {
        for (int x = -radius; x <= radius; ++x) {
            double weight = std::exp(-(x * x + y * y) / sigma2) / (2.0 * M_PI * sigma2);
            kernel[(y + radius) * kernelSize + (x + radius)] = weight;
            sum += weight;
        }
    }

    // Normalize the kernel
    for (double &k : kernel) k /= sum;

    // Apply Gaussian blur
    int width = img.getWidth(), height = img.getHeight(), channels = img.getChannels();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::vector<double> sum(channels, 0.0);
            for (int ky = -radius; ky <= radius; ++ky) {
                for (int kx = -radius; kx <= radius; ++kx) {
                    // Boundary pixels are extended:
                    // If the kernel tries to access a pixel outside the image,
                    // it will simply re-use the nearest edge pixel instead.
                    int ny = std::clamp(y + ky, 0, height - 1);
                    int nx = std::clamp(x + kx, 0, width - 1);
                    for (int ch = 0; ch < channels; ++ch) {
                        sum[ch] += img(nx,ny,ch) * kernel[(ky + radius) * kernelSize + (kx + radius)];
                    }
                }
            }
            for (int ch = 0; ch < channels; ++ch) {
                tempData(x,y,ch) = static_cast<unsigned char>(std::clamp<int>(sum[ch], 0.0, 255.0));
            }
        }
    }
    unsigned char* tempBuffer = new unsigned char[width * height * channels];
    std::memcpy(tempBuffer, tempData.getData(), width * height * channels);
    img.setData(tempBuffer, width, height, channels, img.getState());
}


void Blur::applyMedianBlur(Image& img, int kernelSize) {
    if (!img.getData()) throw std::runtime_error("Image data is null");
    if (kernelSize % 2 == 0) ++kernelSize;
    int radius = kernelSize / 2;
    Image tempData(img);
    
    int width = img.getWidth(), height = img.getHeight(), channels = img.getChannels();

    std::vector<unsigned char> window;
    window.reserve(kernelSize * kernelSize);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int ch = 0; ch < channels; ++ch) {
                window.clear();
                
                for (int ky = -radius; ky <= radius; ++ky) {
                    for (int kx = -radius; kx <= radius; ++kx) {
                        // use bounds checking to avoid skewed results.
                        int nx = x + kx;
                        int ny = y + ky;
                        // int ny = std::clamp(y + ky, 0, height - 1);
                        // int nx = std::clamp(x + kx, 0, width - 1);
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                            window.push_back(img(nx,ny,ch));
                        }
                    }
                }

                // Use the custom median function
                tempData(x,y,ch) = findMedian(window.begin(), window.end());
            }
        }
    }
    unsigned char* tempBuffer = new unsigned char[width * height * channels];
    std::memcpy(tempBuffer, tempData.getData(), width * height * channels);
    img.setData(tempBuffer, width, height, channels, img.getState());
}
