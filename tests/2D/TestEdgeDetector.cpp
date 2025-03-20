/******************************************************************************
 * @file TestEdgeDetector.cpp
 * @brief Implementation file for edge detection tests.
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

#include "TestEdgeDetector.h"
#include <iostream>
#include <cassert>

// Creates a simple grayscale image with a gradient pattern.
Image TestEdgeDetector::createTestImage(int width, int height) {
    Image img(width, height, 1); // Grayscale image (1 channel)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Create a simple gradient pattern.
            img(x, y) = static_cast<unsigned char>((x + y) % 256);
        }
    }
    return img;
}

// Helper function to create a test image with different shapes.
Image createShapeTestImage(int width, int height, const std::string& shape) {
    // Create a blank image (all pixels set to 0).
    Image testImage(width, height, 1);
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            testImage(x, y) = 0;

    if (shape == "circle") {
        // Draw a white circle in the center.
        int radius = 50;
        int centerX = width / 2;
        int centerY = height / 2;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                int dx = x - centerX;
                int dy = y - centerY;
                if (dx * dx + dy * dy <= radius * radius) {
                    testImage(x, y) = 255;
                }
            }
        }
    } else if (shape == "square") {
        // Draw a white square in the center.
        int squareSize = 100;
        int offsetX = (width - squareSize) / 2;
        int offsetY = (height - squareSize) / 2;
        for (int y = offsetY; y < offsetY + squareSize; ++y)
            for (int x = offsetX; x < offsetX + squareSize; ++x)
                testImage(x, y) = 255;
    } 
    else if (shape == "triangle") {
        // Draw a white triangle in the center.
        int triangleHeight = 100;
        int offsetX = (width - triangleHeight) / 2;
        int offsetY = (height - triangleHeight) / 2;
        for (int y = 0; y < triangleHeight; ++y) {
            int startX = offsetX + (triangleHeight - y) / 2;
            int endX = offsetX + (triangleHeight + y) / 2;
            for (int x = startX; x <= endX; ++x) {
                testImage(x, offsetY + y) = 255;
            }
        }
    }

    return testImage;
}

void TestEdgeDetector::testSobelEdgeDetection() {
    std::cout << "Running Sobel Edge Detection Test..." << std::endl;
    Image testImage = createTestImage(256, 256);
    EdgeDetector edgeDetector(EdgeDetectionType::Sobel);
    edgeDetector.apply(testImage);
    std::cout << "Sobel Test Completed. Edge image dimensions: "
              << testImage.getWidth() << " x " << testImage.getHeight() << std::endl;
}

void TestEdgeDetector::testPrewittEdgeDetection() {
    std::cout << "Running Prewitt Edge Detection Test..." << std::endl;
    Image testImage = createTestImage(256, 256);
    EdgeDetector edgeDetector(EdgeDetectionType::Prewitt);
    edgeDetector.apply(testImage);
    std::cout << "Prewitt Test Completed. Edge image dimensions: "
              << testImage.getWidth() << " x " << testImage.getHeight() << std::endl;
}

void TestEdgeDetector::testScharrEdgeDetection() {
    std::cout << "Running Scharr Edge Detection Test..." << std::endl;
    Image testImage = createTestImage(256, 256);
    EdgeDetector edgeDetector(EdgeDetectionType::Scharr);
    edgeDetector.apply(testImage);
    std::cout << "Scharr Test Completed. Edge image dimensions: "
              << testImage.getWidth() << " x " << testImage.getHeight() << std::endl;
}

void TestEdgeDetector::testRobertsCrossEdgeDetection() {
    std::cout << "Running Roberts Cross Edge Detection Test..." << std::endl;
    Image testImage = createTestImage(256, 256);
    EdgeDetector edgeDetector(EdgeDetectionType::RobertsCross);
    edgeDetector.apply(testImage);
    std::cout << "Roberts Cross Test Completed. Edge image dimensions: "
              << testImage.getWidth() << " x " << testImage.getHeight() << std::endl;
}

void TestEdgeDetector::testShapeDetection(const std::string& shape) {
    std::cout << "Running Shape Edge Detection Test for all detectors..." << std::endl;
    

    // Use the helper function to create a test image with a shape
    int width = 256;
    int height = 256;
    Image testImage = createShapeTestImage(width, height, "triangle");
    testImage.save("../Outputs/testImage.png");
    
    
    // Helper lambda to count non-zero pixels in an image.
    auto countNonZero = [&](Image &img) -> int {
        int count = 0;
        for (int y = 0; y < height; ++y)
            for (int x = 0; x < width; ++x)
                if (img(x, y) > 0)
                    count++;
        return count;
    };

    // Apply each edge detection method.
    EdgeDetector edgeDetector_sobel(EdgeDetectionType::Sobel);
    edgeDetector_sobel.apply(testImage);
    testImage.save("../Outputs/sobel.png");
    int sobelCount   = countNonZero(testImage);

    testImage = createShapeTestImage(width, height, "triangle");
    EdgeDetector edgeDetector_prewitt(EdgeDetectionType::Prewitt);
    edgeDetector_prewitt.apply(testImage);
    testImage.save("../Outputs/prewitt.png");
    int prewittCount = countNonZero(testImage);

    testImage = createShapeTestImage(width, height, "triangle");
    EdgeDetector edgeDetector_scharr(EdgeDetectionType::Scharr);
    edgeDetector_scharr.apply(testImage);
    testImage.save("../Outputs/scharr.png");
    int scharrCount  = countNonZero(testImage);

    testImage = createShapeTestImage(width, height, "triangle");
    EdgeDetector edgeDetector_rc(EdgeDetectionType::RobertsCross);
    edgeDetector_rc.apply(testImage);
    testImage.save("../Outputs/roberts.png");
    int robertsCount = countNonZero(testImage);
    


    std::cout << "Sobel non-zero pixels: "   << sobelCount   << std::endl;
    std::cout << "Prewitt non-zero pixels: " << prewittCount << std::endl;
    std::cout << "Scharr non-zero pixels: "  << scharrCount  << std::endl;
    std::cout << "Roberts non-zero pixels: " << robertsCount << std::endl;

    std::cout << "Shape Edge Detection Test for all detectors completed successfully." << std::endl;
}

void TestEdgeDetector::runTests() {
    testSobelEdgeDetection();
    testPrewittEdgeDetection();
    testScharrEdgeDetection();
    testRobertsCrossEdgeDetection();
    testShapeDetection("square");
}


int main() {
    TestEdgeDetector::runTests();
    return 0;
}