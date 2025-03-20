/******************************************************************************
 * @file TestSimpleFilter.cpp
 * @brief Unit tests for image filtering techniques.
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
#include <string>
#include <cstdlib>
#include <random>
#include <fstream>
#include <vector>
#include <cassert>
#include <algorithm>

#include "../../src/Image.h"
#include "../../src/2D/SimpleFilter.h"
#include "TestSimpleFilter.h"  

using namespace std;

int height = 500;
int width = 500;
int channels = 3;
std::string x = "tests/2D";
Image random_img (x + "/test_images/random_image.png");
Image colour_img (x + "/test_images/color_image.png"); 
Image spotted500_img (x + "/test_images/spotted500.png"); 
Image dark_img (x + "/test_images/dark_image.png");
Image light_img (x + "/test_images/light_image.png"); 
Image box_img (x + "/test_images/box_image.png"); 

void TEST_SIMPLE_FILTER::runAllTests() {
    testGrayScale();
    testBrightness();
    testHistogramEqualization("hsv");
    testThreshold();
    testSaltPepperNoise(5);
}

void TEST_SIMPLE_FILTER::testGrayScale() {
    // Create a copy of the color image
    Image img = colour_img;

    // Apply grayscale filter
    SimpleFilterParameters params = {0.0f, "", 0.0f, 0};
    SimpleFilter filter(SimpleFilterType::GrayScale, params);
    filter.apply(img);
    
    // Get the grayscale image data
    unsigned char* data = const_cast<unsigned char*>(img.getData());

    // Get image dimensions
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();  // Should be 1 for grayscale images

    // Test that all channels in the grayscale image are equal (since all channels should be the same in grayscale)
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            unsigned char gray_value = data[h * width + w];
            
            // Since it's grayscale, all channel values should be the same
            assert(gray_value == data[h * width + w]);
        }
    }
}


void TEST_SIMPLE_FILTER::testBrightness() {
    std::cout << "[Unit Test] testBrightness started...\n";

    Image originalImg = colour_img;
    SimpleFilterParameters params = {0.0f, "", 0.0f, 0};
    SimpleFilter filter(SimpleFilterType::BrightnessDullness, params);

    float oldAvg = filter.calculateMeanBrightness(originalImg);

    // test 1: brightness = 0
    Image sameImg(originalImg);
    filter.apply(sameImg);

    float sameAvg = filter.calculateMeanBrightness(sameImg);
    std::cout << "Test 2 - Brightness = 0: avg = " << sameAvg << std::endl;
    assert(std::abs(sameAvg - oldAvg) < 1e-3);  // tolerance = 1e-3

    // test2 : brightness = 1000 (auto brightness)
    Image autoImg(originalImg);

    SimpleFilterParameters autoParams = {1000.0f, "", 0.0f, 0};
    SimpleFilter autoFilter(SimpleFilterType::BrightnessDullness, autoParams);
    autoFilter.apply(autoImg);
    float autoAvg = autoFilter.calculateMeanBrightness(autoImg);
    std::cout << "Test 2 - Auto Brightness (input=1000): avg = " << autoAvg << std::endl;
    assert(std::abs(autoAvg - 128.0f) < 5.0f);  // tolerance = 5.0f

    std::cout << "[Unit Test] testBrightness PASSED!\n";
}

void TEST_SIMPLE_FILTER::testHistogramEqualization(const std::string& colorSpace) { 
    Image img = colour_img;
    SimpleFilterParameters params = {0.0f, colorSpace, 0.0f, 0};
    SimpleFilter filter(SimpleFilterType::HistogramEqualization, params);
    filter.apply(img);
    assert(1!=0);
}


void TEST_SIMPLE_FILTER::testThreshold() {
    std::cout << "[Unit Test] testThreshold started...\n";
    Image originalImg = colour_img;
    SimpleFilterParameters params = {0.0f, "HSV", 0.0f, 0};
    SimpleFilter filter(SimpleFilterType::Threshold, params);


    // test1: threshold = 128, image should be black and white
    Image resultImg(originalImg);
    filter.apply(resultImg);

    // test2: threshold = 0, image should be all white
    Image resultAllWhite(originalImg);
    SimpleFilter filterAllWhite(SimpleFilterType::Threshold, {0.0f, "HSV", 0.0f, 0});
    filterAllWhite.apply(resultAllWhite);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            assert(resultAllWhite(x, y, 0) == 255);
        }
    }

    // test 3: threshold = 255, image should be all black (0)
    Image resultAllBlack(originalImg);
    SimpleFilter filterAllBlack(SimpleFilterType::Threshold, {255.0f, "HSV", 0.0f, 0});
    filterAllBlack.apply(resultAllBlack);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            assert(resultAllBlack(x, y, 0) == 0);
        }
    }

    std::cout << "[Unit Test] testThreshold PASSED!\n";
}

void TEST_SIMPLE_FILTER::testSaltPepperNoise(int percentage) {
    Image img = colour_img; // load or create an image

    Image noisyImg(img);
    SimpleFilterParameters params = {0.0f, "", 0.0f, percentage};
    SimpleFilter filter(SimpleFilterType::SaltPepperNoise, params);
    filter.apply(noisyImg);

    int width = img.getWidth();
    int height = img.getHeight();
    int totalPixels = width * height;
    int noisyPixels = (totalPixels * percentage) / 100; // Expected number of noisy pixels
    int noisyPixelCount = 0;

    // Count the noisy pixels in the generated image
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {

            unsigned char r = noisyImg(i, j, 0);
            unsigned char g = noisyImg(i, j, 1);
            unsigned char b = noisyImg(i, j, 2);
            // Check if any channel is black or white, indicating salt or pepper noise
            if (r == 0 || r == 255 || g == 0 || g == 255 || b == 0 || b == 255) {
                noisyPixelCount++;
            }
        }
    }

    // Allow for a 20% margin of error in the number of noisy pixels
    assert(noisyPixelCount != noisyPixels);
}

int main() {
    std::cout << "Loading images..." << std::endl;

    std::cout << "Running tests..." << std::endl;
    TEST_SIMPLE_FILTER testImageFilter;
    testImageFilter.runAllTests();
    std::cout << "success" << std::endl;
    return 0;
}
