/******************************************************************************
 * @file TestSimpleFilter.h
 * @brief Header file for testing simple image filter techniques.
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

#ifndef TEST_SIMPLE_FILTER_H
#define TEST_SIMPLE_FILTER_H

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "../../src/Image.h"   
#include "../../src/Filter.h" 

// Declaration of the TEST_SIMPLE_FILTER class
class TEST_SIMPLE_FILTER {
public:
    // Test method declarations
    void runAllTests();  // Run all the tests
    void testGrayScale();  // Test the grayscale conversion
    void testBrightness();
    void testThreshold();
    void testHistogramEqualization(const std::string& colorSpace);
    void testSaltPepperNoise(int percentage);
private:
};

#endif // TEST_SIMPLE_FILTER_H
