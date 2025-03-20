/******************************************************************************
 * @file TestEdgeDetector.h
 * @brief Header file for testing edge detection techniques.
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

#ifndef TEST_EDGE_DETECTOR_H
#define TEST_EDGE_DETECTOR_H

#include "../src/2D/EdgeDetector.h"
#include "Image.h"

class TestEdgeDetector {
public:
    // Run all edge detection tests.
    static void runTests();

private:
    // Helper to create a simple grayscale test image.
    static Image createTestImage(int width, int height);

    // Individual test functions for each edge detection method.
    static void testSobelEdgeDetection();
    static void testPrewittEdgeDetection();
    static void testScharrEdgeDetection();
    static void testRobertsCrossEdgeDetection();
    
    // Test for detecting trivial edges (like a square).
    static void testShapeDetection(const std::string& shape);
};

#endif // TEST_EDGE_DETECTOR_H
