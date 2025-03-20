/******************************************************************************
 * @file BlurFilter3D.cpp
 * @brief Implementation file for 3D volume blurring techniques.
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

#include "BlurFilter3D.h"
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <cstring>
#include <cmath>

// Applies Gaussian blur to a 3D volume
void BlurFilter3D::gaussianBlur(Volume& volume, int kernelSize, float sigma) {
    if (kernelSize % 2 == 0) {
        throw std::invalid_argument("Kernel size must be odd.");
    }
    applyGaussianKernel(volume, kernelSize, sigma);
}
// Applies median blur to a 3D volume
void BlurFilter3D::medianBlur(Volume& volume, int kernelSize) {
    if (kernelSize % 2 == 0) {
        throw std::invalid_argument("Kernel size must be odd.");
    }
    applyMedianKernel(volume, kernelSize);
}

// Applies Gaussian blur kernel to the volume
void BlurFilter3D::applyGaussianKernel(Volume& volume, int kernelSize, float sigma) {
    int width = volume.getWidth();
    int height = volume.getHeight();
    int depth = volume.getDepth();
    int channels = volume.getChannels();

    std::vector<unsigned char> modifiedData(width * height * depth * channels);

    int halfKernel = kernelSize / 2;
    std::vector<float> kernel(kernelSize * kernelSize * kernelSize);

    float weightSum = 0.0f;
    for (int z = -halfKernel; z <= halfKernel; ++z) {
        for (int y = -halfKernel; y <= halfKernel; ++y) {
            for (int x = -halfKernel; x <= halfKernel; ++x) {
                float weight = gaussianKernel(x, y, z, sigma);
                kernel[(z + halfKernel) * kernelSize * kernelSize + (y + halfKernel) * kernelSize + (x + halfKernel)] = weight;
                weightSum += weight;
            }
        }
    }

    for (auto& w : kernel) w /= weightSum;

    const unsigned char* data = volume.getData();
    for (int z = 0; z < depth; ++z) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                float sum = 0.0f;

                for (int kz = -halfKernel; kz <= halfKernel; ++kz) {
                    for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                        for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
                            int nx = std::clamp(x + kx, 0, width - 1);
                            int ny = std::clamp(y + ky, 0, height - 1);
                            int nz = std::clamp(z + kz, 0, depth - 1);
                            int kernelIdx = (kz + halfKernel) * kernelSize * kernelSize + (ky + halfKernel) * kernelSize + (kx + halfKernel);
                            int dataIdx = (nz * height + ny) * width + nx;

                            sum += data[dataIdx] * kernel[kernelIdx];
                        }
                    }
                }

                modifiedData[(z * height + y) * width + x] = static_cast<unsigned char>(sum);
            }
        }
    }

    std::memcpy(const_cast<unsigned char*>(volume.getData()), modifiedData.data(), width * height * depth * channels);
}

// Applies median blur kernel to the volume
void BlurFilter3D::applyMedianKernel(Volume& volume, int kernelSize) {
    int width = volume.getWidth();
    int height = volume.getHeight();
    int depth = volume.getDepth();
    int channels = volume.getChannels();

    std::vector<unsigned char> modifiedData(width * height * depth * channels);

    int halfKernel = kernelSize / 2;
    std::vector<unsigned char> neighbourhood(kernelSize * kernelSize * kernelSize);

    for (int z = 0; z < depth; ++z) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                getNeighbouringVoxels(volume, x, y, z, kernelSize, neighbourhood);
                std::nth_element(neighbourhood.begin(), neighbourhood.begin() + neighbourhood.size() / 2, neighbourhood.end());
                modifiedData[(z * height + y) * width + x] = neighbourhood[neighbourhood.size() / 2];
            }
        }
    }


    std::memcpy(const_cast<unsigned char*>(volume.getData()), modifiedData.data(), width * height * depth * channels);
}

// Computes the Gaussian kernel weight for a voxel offset
float BlurFilter3D::gaussianKernel(int x, int y, int z, float sigma) {
    float exponent = -(x * x + y * y + z * z) / (2 * sigma * sigma);
    return std::exp(exponent) / (std::sqrt(2 * M_PI) * sigma);
}

// Retrieves neighboring voxels within the kernel size
void BlurFilter3D::getNeighbouringVoxels(const Volume& volume, int x, int y, int z, int kernelSize, std::vector<unsigned char>& neighbourhood) {
    int halfKernel = kernelSize / 2;
    int width = volume.getWidth();
    int height = volume.getHeight();
    int depth = volume.getDepth();

    neighbourhood.clear();
    for (int kz = -halfKernel; kz <= halfKernel; ++kz) {
        for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
            for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
                int nx = std::clamp(x + kx, 0, width - 1);
                int ny = std::clamp(y + ky, 0, height - 1);
                int nz = std::clamp(z + kz, 0, depth - 1);
                int index = (nz * height + ny) * width + nx;
                neighbourhood.push_back(volume.getData()[index]);
            }
        }
    }
}
