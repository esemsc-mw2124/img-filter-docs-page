/******************************************************************************
 * @file Projection.cpp
 * @brief Implementation file for volume projection techniques.
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

#include "Projection.h"
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <vector>
#include <cstring>
#include "utils/MedianUtils.h"

// Maximum Intensity Projection (MIP)
void Projection::maxIntensityProjection(const Volume& volume, Image& output) {
    int width = volume.getWidth();
    int height = volume.getHeight();
    int depth = volume.getDepth();

    unsigned char* result = new unsigned char[width * height];  // Allocate memory

    const unsigned char* data = volume.getData();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char maxVal = 0;
            for (int z = 0; z < depth; ++z) {
                maxVal = std::max(maxVal, data[(z * height + y) * width + x]);
            }
            result[y * width + x] = maxVal;
        }
    }

    Image temp(width, height, 1);  // Pass ownership
    temp.setData(result, width, height, 1, ImageState::GRAY);  // Pass ownership
    output.setData(temp);  // Pass ownership
}

// Minimum Intensity Projection (MinIP)
void Projection::minIntensityProjection(const Volume& volume, Image& output) {
    int width = volume.getWidth();
    int height = volume.getHeight();
    int depth = volume.getDepth();

    unsigned char* result = new unsigned char[width * height];  // Allocate memory
    // std::fill(result, result + (width * height), 255);  // Initialize to 255

    const unsigned char* data = volume.getData();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char minVal = 255;
            for (int z = 0; z < depth; ++z) {
                minVal = std::min(minVal, data[(z * height + y) * width + x]);
            }
            result[y * width + x] = minVal;
        }
    }

    Image temp(width, height, 1);  // Pass ownership
    temp.setData(result, width, height, 1, ImageState::GRAY);  // Pass ownership
    output.setData(temp);  // Pass ownership
}



// Average Intensity Projection (AIP)
void Projection::meanIntensityProjection(const Volume& volume, Image& output) {
    int width = volume.getWidth();
    int height = volume.getHeight();
    int depth = volume.getDepth();

    unsigned char* result = new unsigned char[width * height];  // Allocate memory

    const unsigned char* data = volume.getData();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int sum = 0;
            for (int z = 0; z < depth; ++z) {
                sum += data[(z * height + y) * width + x];
            }
            result[y * width + x] = static_cast<unsigned char>(sum / depth);
        }
    }
    
    Image temp(width, height, 1);  // Pass ownership
    temp.setData(result, width, height, 1, ImageState::GRAY);  // Pass ownership
    output.setData(temp);  // Pass ownership
}

// Median Intensity Projection
void Projection::medianIntensityProjection(const Volume& volume, Image& output) {
    int width = volume.getWidth();
    int height = volume.getHeight();
    int depth = volume.getDepth();

    unsigned char* result = new unsigned char[width * height];  // Allocate memory

    std::vector<unsigned char> values(depth);
    const unsigned char* data = volume.getData();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int z = 0; z < depth; ++z) {
                values[z] = data[(z * height + y) * width + x];
            }
            int median = findMedian(values.begin(), values.end());
            result[y * width + x] = median;
            // std::nth_element(values.begin(), values.begin() + depth / 2, values.end());
            // result[y * width + x] = values[depth / 2];
        }
    }
    
    Image temp(width, height, 1);  // Pass ownership
    temp.setData(result, width, height, 1, ImageState::GRAY);  // Pass ownership
    output.setData(temp);  // Pass ownership
}