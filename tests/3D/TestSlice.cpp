/******************************************************************************
 * @file TestSlice.cpp
 * @brief Test file for slice extraction functionality in 3D volumes.
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

#include <iostream>
#include <cassert>
#include "../src/Slice.h"

void testExtractAllXZSlices(const Volume& volume, const std::string& outputFolder) {
    std::cout << "[Test 1] Extracting All XZ Slices...\n";
    int height = volume.getHeight();

    for (int y = 0; y < height; ++y) {
        try {
            Slice::extractXZSlice(volume, y, outputFolder);
            std::cout << "  XZ Slice " << y << " saved.\n";
        } catch (const std::exception& e) {
            std::cerr << "  Failed to extract XZ slice at y=" << y << " -> " << e.what() << "\n";
        }
    }
}

void testExtractAllYZSlices(const Volume& volume, const std::string& outputFolder) {
    std::cout << "[Test 2] Extracting All YZ Slices...\n";
    int width = volume.getWidth();

    for (int x = 0; x < width; ++x) {
        try {
            Slice::extractYZSlice(volume, x, outputFolder);
            std::cout << "  YZ Slice " << x << " saved.\n";
        } catch (const std::exception& e) {
            std::cerr << "  Failed to extract YZ slice at x=" << x << " -> " << e.what() << "\n";
        }
    }
}

int main() {
    // Provide all required parameters to match the Volume constructor
    std::string folderPath = "../Scans/TestVolume";
    std::string filePrefix = "vol";
    int startIdx = 000;
    int endIdx = 031;
    std::string fileExtension = "png"; // Adjust based on image type

    std::string outputFolder = "../Outputs";

    std::cout << "🔍 Running Full Slice Extraction Tests...\n";

    try {
        Volume volume(folderPath, filePrefix, startIdx, endIdx, fileExtension);

        testExtractAllXZSlices(volume, outputFolder);
        testExtractAllYZSlices(volume, outputFolder);

        std::cout << "✅ All Slices Extracted Successfully!\n";
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: Failed to load volume -> " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
