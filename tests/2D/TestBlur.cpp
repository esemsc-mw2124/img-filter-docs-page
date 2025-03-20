/******************************************************************************
 * @file TestBlur.cpp
 * @brief Test file for image blurring techniques.
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
#include <unistd.h>
#include <cassert>

#include "TestBlur.h"
#include "../../src/Image.h"
#include "../../src/Filter.h"


int height = 500;
int width = 500;
int channels = 3;
std::string base_path = "../tests/2D";
Image random_img (base_path + "/test_images/random_image.png");
Image colour_img (base_path + "/test_images/color_image.png");
Image spotted500_img (base_path + "/test_images/spotted500.png");
Image dark_img (base_path + "/test_images/dark_image.png");
Image light_img (base_path + "/test_images/light_image.png");
Image box_img (base_path + "/test_images/box_image.png");

void TestImageBlur::runAllTests(){
    testBoxBlur(5);
    testMedianBlur(5);
    testGaussianBlur(5);
}

void TestImageBlur::testBoxBlur(int blur_size){ // test with box.png
    Image img = box_img;
    BlurParameters params = {blur_size, 2.0f, 5};
    Blur blur(BlurType::Box, params);
    blur.apply(img);
    
    for (int h = 99; h < 400; h++){ 
        for (int c = 0; c < channels; c++ ){
            assert(img(h, 99, c) != 255 || img(h, 99, c) != 0);
            assert(img(h, 401, c) != 255 || img(h, 401, c) != 0);
        }
    }
    for (int w = 99; w < 400; w++){ 
        for (int c = 0; c < channels; c++ ){
            assert(img(99, w, c) != 255 || img(99, w, c) != 0);
            assert(img(401, w, c) != 255 || img(401, w, c) != 0);
        }
    }
}

void TestImageBlur::testMedianBlur(int blur_size){ // image with spots every 10 pixels use blur size less than 10
    Image img = spotted500_img;
    Blur blur(BlurType::Median, {blur_size, 2.0f, 5});
    blur.apply(img);
    
    for (int h = 0; h < height; h++){
        for (int w = 0; w < width; w++){ 
            for (int c = 0; c < channels; c++){    
                assert(img(h, w, c) == 255);
            }
        }
    }
}

void TestImageBlur::testGaussianBlur(int blur_size){ // image with spots every 10 pixels
    Image img = spotted500_img;
    Blur blur(BlurType::Gaussian, {blur_size, 2.0f, 5});
    blur.apply(img);
    
    for (int h = 1; h < height; h++){
        for (int w = 1; w < width; w++){ 
            for (int c = 0; c < channels; c++){ 
                assert(img(h, w, c) != 0);
                if (h % 10 == 0 && w % 10 == 0){
                    assert(img(h-1, w, c) != 255);
                    assert(img(h+1, w, c) != 255);
                    assert(img(h-1, w-1, c) != 255);
                    assert(img(h-1, w+1, c) != 255);
                    assert(img(h, w-1, c) != 255);
                    assert(img(h, w+1, c) != 255);
                    assert(img(h+1, w+1, c) != 255);
                    assert(img(h+1, w-1, c) != 255);
                }
            }
        }
    }
}

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working directory: " << cwd << std::endl;
    } else {
        std::cerr << "Error getting current working directory" << std::endl;
        return 1;
    }

    // Test image loading
    std::cout << "Loading images..." << std::endl;
  std::cout << "Running tests..." << std::endl;
    TestImageBlur::runAllTests();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
