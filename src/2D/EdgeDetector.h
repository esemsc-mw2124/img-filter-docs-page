/******************************************************************************
 * @file EdgeDetector.h
 * @brief Header file for edge detection techniques.
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

#ifndef EDGE_DETECTOR_H
#define EDGE_DETECTOR_H

#include "../Filter.h"
#include "../Image.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

enum class EdgeDetectionType {
    Sobel,
    Prewitt,
    Scharr,
    RobertsCross
};


/**
 * @class EdgeDetector
 * @brief A filter class for applying various edge detection techniques on images.
 *
 * Supports multiple edge detection algorithms, including Sobel, Prewitt, Scharr, and Roberts Cross.
 */
class EdgeDetector : public Filter {
    public:
        /**
         * @brief Constructs an EdgeDetector filter with the specified type.
         * @param type The type of edge detection to apply.
         */
        EdgeDetector(EdgeDetectionType type) : type(type) {}
    
        /**
         * @brief Applies the edge detection filter to an image.
         * @param img The image to process.
         * @throws std::invalid_argument If an unknown edge detection type is provided.
         */
        void apply(Image& img) override {
            switch (type) {
                case EdgeDetectionType::Sobel:
                    applySobelEdgeDetection(img);
                    break;
                case EdgeDetectionType::Prewitt:
                    applyPrewittEdgeDetection(img);
                    break;
                case EdgeDetectionType::Scharr:
                    applyScharrEdgeDetection(img);
                    break;
                case EdgeDetectionType::RobertsCross:
                    applyRobertsCrossEdgeDetection(img);
                    break;
                default:
                    throw std::invalid_argument("Unknown edge detection type");
            }
        }
        
        /**
         * @brief Throws an exception, as 3D volume edge detection is not supported.
         * @param vol The volume to which the edge detection cannot be applied.
         * @throws std::runtime_error Always throws since 3D edge detection is not supported.
         */
        void apply(Volume& vol) override {
            throw std::runtime_error("EdgeDetector does not support 3D volumes");
        }
    
    private:
        EdgeDetectionType type; ///< The type of edge detection algorithm.
    
        /**
         * @brief Applies Sobel edge detection to an image.
         * @param img The image to process.
         */
        void applySobelEdgeDetection(Image& img);
    
        /**
         * @brief Applies Prewitt edge detection to an image.
         * @param img The image to process.
         */
        void applyPrewittEdgeDetection(Image& img);
    
        /**
         * @brief Applies Scharr edge detection to an image.
         * @param img The image to process.
         */
        void applyScharrEdgeDetection(Image& img);
    
        /**
         * @brief Applies Roberts Cross edge detection to an image.
         * @param img The image to process.
         */
        void applyRobertsCrossEdgeDetection(Image& img);
    
        // Helper functions
    
        /**
         * @brief Applies convolution using a floating-point kernel.
         * @param input The input image.
         * @param kernel The kernel used for convolution.
         * @param kernelSize The size of the kernel.
         * @return A matrix of convolved values.
         */
        std::vector<std::vector<float>> applyConvolutionFloat(Image& input, const float* kernel, int kernelSize);
    
        /**
         * @brief Applies edge detection using the given horizontal and vertical kernels.
         * @param img The image to process.
         * @param kernel_x The horizontal edge detection kernel.
         * @param kernel_y The vertical edge detection kernel.
         * @param kernelSize The size of the kernels.
         * @return The processed image with edge detection applied.
         */
        Image ApplyEdgeDetection(Image& img, const float* kernel_x, const float* kernel_y, int kernelSize);
};
    
    #endif // EDGE_DETECTOR_H
