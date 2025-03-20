/******************************************************************************
 * @file TestProjection.cpp
 * @brief Test file for projection techniques in 3D imaging.
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
#include "../../src/Projection.h"

// Test 1: Maximum Intensity Projection (MIP)
void testMaxIntensityProjection() {
    std::cout << "[Test 1] Maximum Intensity Projection: ";
    try {
        Volume volume("../../Scans/TestVolume", "vol", 0, 0, "");
        Image output;
        Projection::maxIntensityProjection(volume, output);
        std::cout << "Passed\n";
    } catch (const std::exception& e) {
        std::cerr << "Test 1 Failed: MIP error -> " << e.what() << "\n";
        assert(false);
    }
}

// Test 2: Minimum Intensity Projection (MinIP)
void testMinIntensityProjection() {
    std::cout << "[Test 2] Minimum Intensity Projection: ";
    try {
        Volume volume("../../Scans/TestVolume", "vol", 0, 0, "");
        Image output;
        Projection::minIntensityProjection(volume, output);
        std::cout << "Passed\n";
    } catch (const std::exception& e) {
        std::cerr << "Test 2 Failed: MinIP error -> " << e.what() << "\n";
        assert(false);
    }
}

// Test 3: Average Intensity Projection (AIP)
void testMeanIntensityProjection() {
    std::cout << "[Test 3] Mean Intensity Projection: ";
    try {
        Volume volume("../../Scans/TestVolume", "vol", 0, 0, "");
        Image output;
        Projection::meanIntensityProjection(volume, output);
        std::cout << "Passed\n";
    } catch (const std::exception& e) {
        std::cerr << "Test 3 Failed: AIP error -> " << e.what() << "\n";
        assert(false);
    }
}

// Test 4: Median Intensity Projection (MedianIP)
void testMedianIntensityProjection() {
    std::cout << "[Test 4] Median Intensity Projection: ";
    try {
        Volume volume("../../Scans/TestVolume", "vol", 0, 0, "");
        Image output;
        Projection::medianIntensityProjection(volume, output);
        std::cout << "Passed\n";
    } catch (const std::exception& e) {
        std::cerr << "Test 4 Failed: MedianIP error -> " << e.what() << "\n";
        assert(false);
    }
}

int main() {
    std::cout << "Running Projection Tests...\n";
    testMaxIntensityProjection();
    testMinIntensityProjection();
    testMeanIntensityProjection();
    testMedianIntensityProjection();
    std::cout << "All Projection Tests Completed.\n";
    return 0;
}
