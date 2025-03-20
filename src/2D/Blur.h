/******************************************************************************
 * @file Blur.h
 * @brief Header file for the Blur filter class.
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
#ifndef IMAGE_BLUR_H
#define IMAGE_BLUR_H

#include "../Image.h"
#include "../Filter.h"

enum class BlurType {
    Box,
    Gaussian,
    Median
};

struct BlurParameters {
    int blurSize;   // For Box blur
    double sigma;   // For Gaussian blur
    int kernelSize; // For Gaussian and Median blur
};

/**
 * @class Blur
 * @brief A filter class for applying different types of blur effects on images.
 *
 * The Blur class supports box blur, Gaussian blur, and median blur.
 */
class Blur : public Filter {
    public:
        /**
         * @brief Constructs a Blur filter with the specified type and parameters.
         * @param type The type of blur to apply (Box, Gaussian, Median).
         * @param params The parameters for the blur effect.
         */
        Blur(BlurType type, const BlurParameters& params)
        : type(type), params(params) {}

        /**
         * @brief Applies the blur effect to an image.
         * @param img The image to which the blur effect is applied.
         * @throws std::invalid_argument If an unknown blur type is provided.
         */
        void apply(Image& img) override {
            switch (type) {
                case BlurType::Box:
                    applyBoxBlur(img, params.blurSize);
                    break;
                case BlurType::Gaussian:
                    applyGaussianBlur(img, params.sigma, params.kernelSize);
                    break;
                case BlurType::Median:
                    applyMedianBlur(img, params.kernelSize);
                    break;
                default:
                    throw std::invalid_argument("Unknown blur type");
            }
        }

        /**
         * @brief Throws an exception, as 3D volume blurring is not supported.
         * @param vol The volume to which the blur effect cannot be applied.
         * @throws std::runtime_error Always throws since 3D blur is not supported.
         */
        void apply(Volume& vol) override {
            throw std::runtime_error("Blur filter does not support 3D volumes.");
        }

    private:
        BlurType type;  ///< The type of blur effect to apply.
        BlurParameters params; ///< The parameters defining the blur effect.

        /**
         * @brief Applies a box blur to an image.
         * @param img The image to be blurred.
         * @param blurSize The size of the blur kernel.
         */
        void applyBoxBlur(Image& img, int blurSize);

        /**
         * @brief Applies a Gaussian blur to an image.
         * @param img The image to be blurred.
         * @param sigma The standard deviation of the Gaussian kernel.
         * @param kernelSize The size of the Gaussian kernel.
         */
        void applyGaussianBlur(Image& img, double sigma, int kernelSize);

        /**
         * @brief Applies a median blur to an image.
         * @param img The image to be blurred.
         * @param kernelSize The size of the kernel used for median filtering.
         */
        void applyMedianBlur(Image& img, int kernelSize);
};

#endif
