/******************************************************************************
 * @file Slice.cpp
 * @brief Implementation file for extracting slices from volume data.
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

#include "Slice.h"
#include "stb_image_write.h"
#include <filesystem>
#include <stdexcept>
#include <iostream>

namespace fs = std::filesystem;

// Define a macro for enabling/disabling debug messages
#ifndef NDEBUG
    #define LOG(msg) std::cerr << msg << std::endl;
#else
    #define LOG(msg)
#endif

// ========== XZ slices（Y depth） ==========
bool Slice::extractXZSlice(const Volume& volume, int yIndex, Image& outputImage) {
    int width = volume.getWidth();
    int depth = volume.getDepth();
    int channels = volume.getChannels();

    if (yIndex < 0 || yIndex >= volume.getHeight()) {
        LOG("Error: Invalid yIndex for XZ slice.");
        return false;
    }

    unsigned char* sliceData = new unsigned char[width * depth * channels];
    const unsigned char* volumeData = volume.getData();

    for (int z = 0; z < depth; ++z) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channels; ++c) {
                sliceData[(z * width + x) * channels + c] = 
                    volumeData[(z * width * volume.getHeight() + yIndex * width + x) * channels + c];
            }
        }
    }

    Image temp(width, depth, channels);
    temp.setData(sliceData, width, depth, channels, ImageState::GRAY);
    outputImage.setData(temp);
    return true;
}

// ========== YZ slices（X depth） ==========
bool Slice::extractYZSlice(const Volume& volume, int xIndex, Image& outputImage) {
    int height = volume.getHeight();
    int depth = volume.getDepth();
    int channels = volume.getChannels();

    if (xIndex < 0 || xIndex >= volume.getWidth()) {
        LOG("Error: Invalid xIndex for YZ slice.");
        return false;
    }

    unsigned char* sliceData = new unsigned char[height * depth * channels];
    const unsigned char* volumeData = volume.getData();

    for (int z = 0; z < depth; ++z) {
        for (int y = 0; y < height; ++y) {
            for (int c = 0; c < channels; ++c) {
                sliceData[(z * height + y) * channels + c] = 
                    volumeData[(z * volume.getWidth() * height + y * volume.getWidth() + xIndex) * channels + c];
            }
        }
    }

    Image temp(height, depth, channels);
    temp.setData(sliceData, height, depth, channels, ImageState::GRAY);
    outputImage.setData(temp);
    return true;
}
