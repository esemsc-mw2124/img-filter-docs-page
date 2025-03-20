/******************************************************************************
 * @file EdgeDetector.cpp
 * @brief Implementation file for edge detection techniques.
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

#include "EdgeDetector.h"

// Apply convolution on the input image using the given kernel.
std::vector<std::vector<float>> EdgeDetector::applyConvolutionFloat(Image& input, const float* kernel, int kernelSize)
{
    int width = input.getWidth();
    int height = input.getHeight();
    int kHalf = kernelSize / 2;

    // 2D float buffer to store the convolution results
    std::vector<std::vector<float>> results(width, std::vector<float>(height, 0.0f));

    // Convolve with replicate padding
    if (kernelSize % 2 != 0) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                float sum = 0.0f;
                for (int ky = -kHalf; ky <= kHalf; ++ky) {
                    for (int kx = -kHalf; kx <= kHalf; ++kx) {
                        int nx = std::clamp(x + kx, 0, width - 1);
                        int ny = std::clamp(y + ky, 0, height - 1);

                        int kernelIndex = (ky + kHalf) * kernelSize + (kx + kHalf);
                        sum += input(nx, ny) * kernel[kernelIndex];
                    }
                }
                results[x][y] = sum; // Keep float
            }
        }
    } else { // Do Robert's cross Edge detection
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int nx = std::clamp(x + 1, 0, width - 1);
                int ny = std::clamp(y + 1, 0, height - 1);

                float a = input(x, y);   // I(x, y)
                float b = input(nx, y);  // I(x+1, y)
                float c = input(x, ny);  // I(x, y+1)
                float d = input(nx, ny); // I(x+1, y+1)

                // Robert's Cross differences
                float gx = d - a;
                float gy = b - c;

                results[x][y] = std::sqrt(gx * gx + gy * gy); // Gradient magnitude
            }
        }
    }

    return results;
}


// Combine edge detection for the X and Y directions using the gradient magnitude.
Image EdgeDetector::ApplyEdgeDetection(Image& img, const float* kernel_x, const float* kernel_y, int kernelSize)
{
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();

    // 1) Convert to grayscale if needed
    Image gray_img(width, height, 1);
    if (img.getChannels() == 1) {
        gray_img = img;
    } else {
        for (int i = 0; i < width; ++i) {
            for(int j = 0; j < height; ++j){
                // Get the RGB values
                float r = img(i,j,0);
                float g = img(i,j,1);
                float b = img(i,j,2);

                // Calculate luminance using the formula
                gray_img(i,j) = static_cast<unsigned char>(0.2126 * r + 0.7152 * g + 0.0722 * b);
            }
        }
    }

    // 2) Get float convolution results for X and Y
    std::vector<std::vector<float>> convX = applyConvolutionFloat(gray_img, kernel_x, kernelSize);
    std::vector<std::vector<float>> convY = applyConvolutionFloat(gray_img, kernel_y, kernelSize);

    // 3) Compute the gradient magnitude in float
    std::vector<std::vector<float>> magnitude(width, std::vector<float>(height, 0.0f));
    float minVal = std::numeric_limits<float>::max();
    float maxVal = std::numeric_limits<float>::lowest();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float gx = convX[x][y];
            float gy = convY[x][y];
            float mag = std::sqrt(gx * gx + gy * gy);
            // float mag = std::abs(gx) + std::abs(gy); // Faster approximation
            magnitude[x][y] = mag;

            // Track global min and max for normalization
            if (mag < minVal) minVal = mag;
            if (mag > maxVal) maxVal = mag;
        }
    }

    // 4) Convert the float magnitude to an 8-bit Image with normalization
    Image edge_image(width, height, 1);  // single-channel output

    if (minVal == maxVal) {
        // Degenerate case: everything is the same
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                edge_image(x, y) = 0; 
            }
        }
    } else {
        float range = maxVal - minVal;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                float val = (magnitude[x][y] - minVal) / range; // [0..1]
                float scaled = val * 255.0f;                    // [0..255]
                // Round and clamp
                unsigned char pix = static_cast<unsigned char>(
                    std::round(std::clamp(scaled, 0.0f, 255.0f))
                );
                edge_image(x, y) = pix;
            }
        }
    }

    return edge_image;
}


// Sobel Edge Detection.
void EdgeDetector::applySobelEdgeDetection(Image& img) {
    const float sobelX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    const float sobelY[3][3] = {
        {-1, -2, -1},
        {0,  0,  0},
        {1,  2,  1}
    };

    Image edge_image = ApplyEdgeDetection(img, &sobelX[0][0], &sobelY[0][0], 3);
    img.setData(edge_image);
}

// Prewitt Edge Detection.
void EdgeDetector::applyPrewittEdgeDetection(Image& img) {
    const float prewittX[3][3] = {
        {-1, 0, 1},
        {-1, 0, 1},
        {-1, 0, 1}
    };
    const float prewittY[3][3] = {
        {-1, -1, -1},
        {0,  0,  0},
        {1,  1,  1}
    };

    Image edge_image = ApplyEdgeDetection(img, &prewittX[0][0], &prewittY[0][0], 3);
    img.setData(edge_image);
}

// Scharr Edge Detection.
void EdgeDetector::applyScharrEdgeDetection(Image& img) {
    const float scharrX[3][3] = {
        {-3, 0, 3},
        {-10, 0, 10},
        {-3, 0, 3}
    };
    const float scharrY[3][3] = {
        {-3, -10, -3},
        {0,  0,  0},
        {3,  10,  3}
    };

    Image edge_image = ApplyEdgeDetection(img, &scharrX[0][0], &scharrY[0][0], 3);
    img.setData(edge_image);
}

// Roberts Cross Edge Detection.
void EdgeDetector::applyRobertsCrossEdgeDetection(Image& img) {
    const float robertsX[2][2] = {
        {1, 0},
        {0, -1}
    };
    const float robertsY[2][2] = {
        {0, 1},
        {-1, 0}
    };

    Image edge_image = ApplyEdgeDetection(img, &robertsX[0][0], &robertsY[0][0], 2);
    img.setData(edge_image);
}