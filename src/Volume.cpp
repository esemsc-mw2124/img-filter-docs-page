/******************************************************************************
 * @file Volume.cpp
 * @brief Implementation file for volume data handling and processing.
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

#include "Volume.h"
#include "stb_image.h"
#include "stb_image_write.h"

#include <filesystem>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include <regex>

namespace fs = std::filesystem;

// Default constructor
Volume::Volume() : data(nullptr), width(0), height(0), depth(0), channels(0), state(VolumeState::UNKNOWN) {}

// Constructor to load volume based on image name prefix, extension, and optional index range
Volume::Volume(const std::string& folderPath, const std::string& filePrefix, int startIdx, int endIdx, const std::string& fileExtension)
    : data(nullptr), width(0), height(0), depth(0), channels(0), state(VolumeState::UNKNOWN) {
    loadVolume(folderPath, filePrefix, startIdx, endIdx, fileExtension);
}

// Destructor to free allocated memory
Volume::~Volume() {
    if (data) {
        delete[] data;
    }
}

// Returns the current state of the volume
VolumeState Volume::getState() const {
    return state;
}

// Loads a volume by searching for images matching the given prefix, extension, and optional index range
void Volume::loadVolume(const std::string& folderPath, const std::string& filePrefix, int startIdx, int endIdx, const std::string& fileExtension) {
    if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
        throw std::runtime_error("Invalid folder path: " + folderPath);
    }

    std::vector<std::string> imageFiles;
    std::string extension = fileExtension.empty() ? "png" : fileExtension; // Default to "png" if no extension is provided
    std::regex pattern("^" + filePrefix + R"(\d+\.)" + extension + "$"); // Regex to match "prefix123.png"

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();
            if (std::regex_match(filename, pattern)) {
                imageFiles.push_back(entry.path().string());
            }
        }
    }

    if (imageFiles.empty()) {
        throw std::runtime_error("No images found with prefix: " + filePrefix);
    }

    // Sort filenames numerically
    std::sort(imageFiles.begin(), imageFiles.end(), compareFileNames);

    if (startIdx > 0 || endIdx > 0) {
        std::vector<std::string> filteredImages;
        
        // Convert indices to 0-based if they're 1-based
        size_t startPos = startIdx > 0 ? startIdx - 1 : 0;
        size_t endPos = endIdx > 0 ? endIdx - 1 : imageFiles.size() - 1;
        
        // Ensure endPos is not out of bounds
        endPos = std::min(endPos, imageFiles.size() - 1);
        
        // If startPos is valid, extract the slice
        if (startPos < imageFiles.size()) {
            filteredImages.assign(
                imageFiles.begin() + startPos,
                imageFiles.begin() + std::min(endPos + 1, imageFiles.size())
            );
        }
        
        imageFiles = filteredImages;
    }

    if (imageFiles.empty()) {
        throw std::runtime_error("No images found in the specified range.");
    }

    // Load first image to get dimensions
    int imgWidth, imgHeight, imgChannels;
    unsigned char* firstImage = stbi_load(imageFiles[0].c_str(), &imgWidth, &imgHeight, &imgChannels, 0);
    if (!firstImage) {
        throw std::runtime_error("Failed to load first image: " + imageFiles[0]);
    }

    width = imgWidth;
    height = imgHeight;
    channels = imgChannels;
    depth = static_cast<int>(imageFiles.size());

    // Allocate memory for 3D volume data
    data = new unsigned char[width * height * depth * channels];

    // Load all image slices into volume data
    for (int d = 0; d < depth; ++d) {
        int w, h, c;
        unsigned char* imgData = stbi_load(imageFiles[d].c_str(), &w, &h, &c, 0);
        if (!imgData) {
            throw std::runtime_error("Failed to load image: " + imageFiles[d]);
        }

        if (w != width || h != height || c != channels) {
            stbi_image_free(imgData);
            throw std::runtime_error("Image dimensions or channels mismatch in: " + imageFiles[d]);
        }

        std::memcpy(data + d * width * height * channels, imgData, width * height * channels);
        stbi_image_free(imgData);
    }

    state = VolumeState::RAW;
}

// Compares filenames for sorting (numerical order)
bool Volume::compareFileNames(const std::string& a, const std::string& b) {
    std::smatch matchA, matchB;
    std::regex numberPattern(R"(\d+)");

    std::string numA = std::regex_search(a, matchA, numberPattern) ? matchA.str() : "";
    std::string numB = std::regex_search(b, matchB, numberPattern) ? matchB.str() : "";

    return std::stoi(numA) < std::stoi(numB);
}

// Saves each slice of the volume as a separate image with the specified extension
void Volume::saveSlices(const std::string& outputFolder, int quality, const std::string& fileExtension) const {
    if (!data) {
        throw std::runtime_error("No volume data available to save.");
    }

    if (!fs::exists(outputFolder)) {
        fs::create_directory(outputFolder);
    }

    std::string ext = fileExtension.empty() ? "png" : fileExtension; // Default to "png" if no extension is provided

    for (int d = 0; d < depth; ++d) {
        std::string filename = outputFolder + "/slice_" + std::to_string(d + 1) + "." + ext;

        // Save as PNG by default
        if (ext == "png") {
            int success = stbi_write_png(filename.c_str(), width, height, channels, data + d * width * height * channels, width * channels);
            if (!success) {
                throw std::runtime_error("Failed to save slice as PNG: " + filename);
            }
        }
        // Save as JPG if the extension is "jpg" or "jpeg"
        else if (ext == "jpg" || ext == "jpeg") {
            int success = stbi_write_jpg(filename.c_str(), width, height, channels, data + d * width * height * channels, quality);
            if (!success) {
                throw std::runtime_error("Failed to save slice as JPG: " + filename);
            }
        }
        // Handle other formats here (optional, depending on the extensions you want to support)
        else {
            throw std::runtime_error("Unsupported file extension: " + ext);
        }
    }
}


// Getter functions
int Volume::getWidth() const { return width; }
int Volume::getHeight() const { return height; }
int Volume::getDepth() const { return depth; }
int Volume::getChannels() const { return channels; }
const unsigned char* Volume::getData() const { return data; }
