/******************************************************************************
 * @file TestSharpener.cpp
 * @brief Test file for image sharpening techniques.
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
#include <cassert>
#include <iostream>
#include "Image.h"
#include "../src/2D/Sharpener.h"

// Test 1: Uniform image should remain unchanged.
// A uniform image has no edges, so applying a Laplacian sharpening filter should result in no change.
void testUniformImage() {
    const int width = 3, height = 3, channels = 1;
    Image img(width, height, channels);
    
    // Fill the image with a uniform value (50)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            img(x, y, 0) = 50;
        }
    }
    
    // Apply the sharpening filter.
    Sharpener sharpener;
    sharpener.apply(img);
    
    // Verify that every pixel remains 50.
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            assert(img(x, y, 0) == 50);
        }
    }
    
    std::cout << "testUniformImage passed." << std::endl;
}

// Test 2: Image with a brighter center.
// In this test the center pixel is brighter than its surroundings.
// After applying the Laplacian sharpening filter, we expect the center pixel to be enhanced (and clamped to 255)
// while border pixels should remain near their original values.
void testCenterEnhancement() {
    const int width = 3, height = 3, channels = 1;
    Image img(width, height, channels);
    
    // Fill the image with a baseline value (100).
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            img(x, y, 0) = 100;
        }
    }
    // Set the center pixel to 150.
    img(1, 1, 0) = 150;
    
    // Apply the sharpening filter.
    Sharpener sharpener;
    sharpener.apply(img);
    
    // Let's compute the expected new center value:
    // For the center pixel (1,1), the convolution with the Laplacian kernel is:
    // convSum = 4 * 150 - (100 (up) + 100 (down) + 100 (left) + 100 (right))
    //         = 600 - 400 = 200.
    // The new value = original value + convSum = 150 + 200 = 350, clamped to 255.
    assert(img(1, 1, 0) == 255);
    
    std::cout << "testCenterEnhancement passed." << std::endl;
}

int main() {
    testUniformImage();
    testCenterEnhancement();
    std::cout << "All sharpening tests passed!" << std::endl;
    return 0;
}
