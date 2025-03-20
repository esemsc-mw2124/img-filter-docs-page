/******************************************************************************
 * @file simpleFilter.h
 * @brief Header file for simple image filtering techniques.
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

#ifndef SIMPLEFILTER_H
#define SIMPLEFILTER_H
#include "../Image.h"
#include "../Filter.h"
#include <stdexcept>

enum class SimpleFilterType {
    GrayScale,
    BrightnessDullness,
    HistogramEqualization,
    Threshold,
    SaltPepperNoise
};

struct SimpleFilterParameters {
    float brightness;
    std::string colorSpace;
    float threshold;
    int percentage;
};


/**
 * @class SimpleFilter
 * @brief A filter class for applying various simple image processing operations.
 *
 * Supports grayscale conversion, brightness adjustment, histogram equalization, thresholding,
 * and adding salt-and-pepper noise.
 */
class SimpleFilter : public Filter {
    public:
        /**
         * @brief Constructs a SimpleFilter with the specified type and parameters.
         * @param type The type of simple filter to apply.
         * @param params The parameters for the filter effect.
         */
        SimpleFilter(SimpleFilterType type, const SimpleFilterParameters& params) 
        : type(type), params(params) {}

        /**
         * @brief Constructs a SimpleFilter with default parameters.
         * @param type The type of simple filter to apply.
         */
        SimpleFilter(SimpleFilterType type) 
        : type(type), params({0.0f, "", 0.0f, 0}) {}

        /**
         * @brief Applies the selected filter effect to an image.
         * @param img The image to process.
         * @throws std::invalid_argument If an unknown filter type is provided.
         */
        void apply(Image& img) override {
            switch (type){
                case SimpleFilterType::GrayScale:
                    applyGrayScale(img);
                    break;
                case SimpleFilterType::BrightnessDullness:
                    applyBrightnessDullness(img, params.brightness);
                    break;
                case SimpleFilterType::HistogramEqualization:
                    applyHistogramEqualization(img, params.colorSpace);
                    break;
                case SimpleFilterType::Threshold:
                    applyThreshold(img, params.threshold, params.colorSpace);
                    break;
                case SimpleFilterType::SaltPepperNoise:
                    applySaltPepperNoise(img, params.percentage);
                    break;
                default:
                    throw std::invalid_argument("Unknown edge detection type");
            }
        }

        /**
         * @brief Throws an exception, as 3D volume processing is not supported.
         * @param vol The volume to which the filter cannot be applied.
         * @throws std::runtime_error Always throws since 3D filtering is not supported.
         */
        void apply(Volume& vol) override {
            throw std::runtime_error("SimpleFilter does not support 3D volumes.");
        }

        /**
         * @brief Calculates the mean brightness of an image.
         * @param img The image to analyze.
         * @return The mean brightness value.
         */
        float calculateMeanBrightness(Image& img);

    private:
        SimpleFilterType type; ///< The type of filter to apply.
        SimpleFilterParameters params; ///< The parameters defining the filter effect.

        /**
         * @brief Converts an image to grayscale.
         * @param img The image to process.
         */
        void applyGrayScale(Image& img);

        /**
         * @brief Adjusts the brightness or dullness of an image.
         * @param img The image to process.
         * @param brightness The brightness adjustment value (default: 1000).
         */
        void applyBrightnessDullness(Image& img, float brightness = 1000);

        /**
         * @brief Applies histogram equalization to an image.
         * @param img The image to process.
         * @param colorSpace The color space to use for equalization (default: "HSV").
         */
        void applyHistogramEqualization(Image& img, const std::string& colorSpace = "HSV");

        /**
         * @brief Applies thresholding to an image.
         * @param img The image to process.
         * @param threshold The threshold value.
         * @param colorSpace The color space to use for thresholding (default: "HSV").
         */
        void applyThreshold(Image& img, float threshold, const std::string &colorSpace = "HSV");

        /**
         * @brief Adds salt-and-pepper noise to an image.
         * @param img The image to process.
         * @param percentage The percentage of pixels to be affected by noise.
         */
        void applySaltPepperNoise(Image& img, int percentage);

        // Helper functions

        /**
         * @brief Applies histogram equalization to a specific channel of an image.
         * @param img The image to process.
         * @param width The width of the image.
         * @param height The height of the image.
         * @param pixelSize The size of a pixel in bytes.
         * @param channelIndex The index of the color channel to process.
         */
        void applyHistogramEqualizationForChannel(Image& img, int width, int height, int pixelSize, int channelIndex);
};

#endif // SIMPLEFILTER_H
