/******************************************************************************
 * @file TestBlurFilter3D.cpp
 * @brief Test file for 3D image blurring techniques.
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
#include "../../src/3D/BlurFilter3D.h"
#include "../../src/Volume.h"

// Test 3: Apply Gaussian Blur
void testGaussianBlur() {
    std::cout << "[Test 3] Gaussian Blur: ";
    try {
        Volume volume("../../Scans/TestVolume", "vol", 0, 0, "");

        BlurFilter3D blurFilter(Filter3DType::GaussianBlur, {3, 1.0f});
        blurFilter.apply(volume);

        std::cout << "Passed\n";
    } catch (const std::exception& e) {
        std::cerr << "Test 3 Failed: Gaussian blur error -> " << e.what() << "\n";
        assert(false);
    }
}

// Test 4: Apply Median Blur
void testMedianBlur() {
    std::cout << "[Test 4] Median Blur: ";
    try {
        Volume volume("../../Scans/TestVolume", "vol", 0, 0, "");
        
        // Create a BlurFilter3D instance for Median Blur
        BlurFilter3D medianFilter(Filter3DType::MedianBlur, {3, 0.0f});
        medianFilter.apply(volume);

        std::cout << "Passed\n";
    } catch (const std::exception& e) {
        std::cerr << "Test 4 Failed: Median blur error -> " << e.what() << "\n";
        assert(false);
    }
}

// Main function
int main() {
    std::cout << "Running 3D Blur Tests...\n";
    testGaussianBlur();
    testMedianBlur();
    std::cout << "All 3D Blur Tests Completed.\n";
    return 0;
}
