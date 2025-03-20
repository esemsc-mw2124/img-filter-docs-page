/******************************************************************************
 * @file TestBlur.h
 * @brief Header file for testing image blurring techniques.
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
#ifndef TEST_BLUR_H
#define TEST_BLUR_H

#include "../src/2D/Blur.h"

class TestImageBlur {
public:
    static void runAllTests();
    static void testBoxBlur(int blur_size);
    static void testMedianBlur(int blur_size);
    static void testGaussianBlur(int blur_size);
};

#endif // TEST_BLUR_H
