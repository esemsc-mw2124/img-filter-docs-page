/******************************************************************************
 * @file TestVolume.cpp
 * @brief Test file for the Volume class and its functionalities.
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
#include <cassert>  // Include assertion library
#include "../../src/Volume.h"  // Include the Volume class

// Test 1: Check if Volume can load images from the directory
void testVolumeLoading() {
    std::cout << "[Test 1] Volume Loading: ";
    try {
        Volume volume("../Scans/TestVolume", "vol", 0, 0, "");
        assert(volume.getDepth() > 0 && "Test 1 Failed: Volume depth must be greater than 0.");
        std::cout << "Passed\n";
    } catch (const std::exception& e) {
        std::cerr << "Test 1 Failed: Volume loading error -> " << e.what() << "\n";
        assert(false && "Test 1 Failed: Volume loading exception.");
    }
}

// Test 2: Verify Volume dimensions are valid
void testVolumeGetters() {
    std::cout << "[Test 2] Volume Getters: ";
    try {
        Volume volume("../Scans/TestVolume", "vol", 0, 0, "");
        assert(volume.getWidth() > 0 && "Test 2 Failed: Invalid width.");
        assert(volume.getHeight() > 0 && "Test 2 Failed: Invalid height.");
        assert(volume.getDepth() > 0 && "Test 2 Failed: Invalid depth.");
        assert(volume.getChannels() > 0 && "Test 2 Failed: Invalid channel count.");

        std::cout << "Passed\n";
        std::cout << "   - Width: " << volume.getWidth() << "\n";
        std::cout << "   - Height: " << volume.getHeight() << "\n";
        std::cout << "   - Depth: " << volume.getDepth() << "\n";
        std::cout << "   - Channels: " << volume.getChannels() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Test 2 Failed: Exception occurred while testing getters -> " << e.what() << "\n";
        assert(false && "Test 2 Failed: Volume getters exception.");
    }
}

// Test 3: Verify slab extraction from Volume
void testVolumeSlabExtraction() {
    std::cout << "[Test 1] Volume Slab Loading: ";
    try {
        Volume volume("../Scans/TestVolume", "vol", 4, 10, "");
        assert(volume.getDepth() > 0 && "Test 1 Failed: Volume depth must be greater than 0.");
        std::cout << "Passed\n";
        assert(volume.getDepth() == 7 && "Test 3 Failed: Invalid slab depth.");
    } catch (const std::exception& e) {
        std::cerr << "Test 1 Failed: Volume loading error -> " << e.what() << "\n";
        assert(false && "Test 1 Failed: Volume loading exception.");
    }
}


// Main function to run the tests
int main() {
    std::cout << "Running Volume Tests...\n";
    testVolumeLoading();  // Test 1: Load Volume
    testVolumeGetters();  // Test 2: Check Volume Properties
    testVolumeSlabExtraction();  // Test 3: Extract Slab from Volume
    std::cout << "All Volume Tests Completed.\n";
    return 0;
}
