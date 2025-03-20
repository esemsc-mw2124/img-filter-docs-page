/******************************************************************************
 * @file Sharpener.cpp
 * @brief Implementation file for image sharpening techniques.
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

#include "Sharpener.h"
#include <algorithm>    // std::clamp
#include <vector>

// REFERENCE: ChatGPT 03-mini-high utilised to improve algorithm design and efficiency
void Sharpener::SharpenImage(Image& img, const float kernel[3][3]) {
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();

    // Retrieve image data - VERA'S SUGGESTION
    const unsigned char* data = img.getData();
    
    // Correctly initialize a vector with all image data.
    std::vector<unsigned char> originalData(data, data + width * height * channels);

    // Loop over every pixel (row-major order)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Process each channel separately
            for (int c = 0; c < channels; ++c) {
                float convSum = 0.0f;
                // Convolve with the 3x3 kernel (offset indices from -1 to 1)
                for (int ky = -1; ky <= 1; ++ky) {
                    for (int kx = -1; kx <= 1; ++kx) {
                        int ix = std::clamp(x + kx, 0, width - 1);
                        int iy = std::clamp(y + ky, 0, height - 1);
                        int index = (iy * width + ix) * channels + c;
                        convSum += kernel[ky + 1][kx + 1] * originalData[index];
                    }
                }
                int origVal = originalData[(y * width + x) * channels + c];
                // int newVal = origVal + static_cast<int>(convSum);

                // Mitigate any potential overflow errors - VERA'S SUGGESTION
                int64_t newVal = static_cast<int64_t>(origVal) + static_cast<int64_t>(convSum);
                newVal = std::clamp(newVal, static_cast<int64_t>(0), static_cast<int64_t>(255));

                // Set the pixel value to be the new value from the kernel operation
                img(x, y, c) = static_cast<unsigned char>(newVal);
            }
        }
    }
}
