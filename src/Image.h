/******************************************************************************
 * @file Image.h
 * @brief Header file for the Image class and related image processing utilities.
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

#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cstring>  // For std::memcpy

enum class ImageState {
    GRAY,
    GRAYA,
    RGB,
    RGBA,
    HSV,
    HSL,
    HSVA,
    HSLA,
    UNKNOWN
};

/**
 * @class Image
 * @brief A class for representing and manipulating images.
 *
 * Supports image loading, saving, format conversion, and basic operations.
 */
class Image {
    public:
        /**
         * @brief Default constructor.
         */
        Image();
        
        /**
         * @brief Constructs an image from a file.
         * @param filename The file path to load the image from.
         */
        Image(const std::string &filename);
        
        /**
         * @brief Constructs an empty image with specified dimensions and channels.
         * @param width Image width.
         * @param height Image height.
         * @param channels Number of color channels.
         */
        Image(int width, int height, int channels);
        
        /**
         * @brief Constructs an image from raw data.
         * @param data Pointer to image data.
         * @param width Image width.
         * @param height Image height.
         * @param channels Number of color channels.
         * @param state The current state of the image.
         */
        Image(unsigned char* data, int width, int height, int channels, ImageState state);
        
        /**
         * @brief Copy constructor.
         * @param other The image to copy from.
         */
        Image(const Image& other);
        
        /**
         * @brief Destructor to free allocated resources.
         */
        ~Image();
        
        /**
         * @brief Gets the current state of the image.
         * @return The image state.
         */
        ImageState getState() const;
        
        /**
         * @brief Converts the image to the HSL color space.
         */
        void convertToHSL();
        
        /**
         * @brief Converts the image to the HSV color space.
         */
        void convertToHSV();
        
        /**
         * @brief Converts the image to the RGB color space.
         */
        void convertToRGB();
        
        /**
         * @brief Gets the image width.
         * @return The width of the image.
         */
        int getWidth() const;
        
        /**
         * @brief Gets the image height.
         * @return The height of the image.
         */
        int getHeight() const;
        
        /**
         * @brief Gets the number of channels in the image.
         * @return The number of channels.
         */
        int getChannels() const;
        
        /**
         * @brief Gets the raw image data.
         * @return A pointer to the image data.
         */
        const unsigned char* getData() const;
        
        /**
         * @brief Saves the image to a file.
         * @param filename The file path to save the image.
         * @param quality The quality level for image compression (default: 100).
         */
        void save(const std::string &filename, int quality = 100) const;
        
        /**
         * @brief Sets the image data from raw data.
         * @param data Pointer to new image data.
         * @param width Image width.
         * @param height Image height.
         * @param channels Number of color channels.
         * @param state The new state of the image.
         */
        void setData(unsigned char* data, int width, int height, int channels, ImageState state);
        
        /**
         * @brief Copies image data from another image.
         * @param other The image to copy from.
         */
        void setData(const Image& other);
        
        /**
         * @brief Overloaded pixel access operator.
         * @param x X-coordinate.
         * @param y Y-coordinate.
         * @param channel Color channel index (default: 0).
         * @return A reference to the pixel value.
         */
        unsigned char &operator()(int x, int y, int channel=0);
        
        /**
         * @brief Overloaded assignment operator.
         * @param other The image to assign from.
         * @return A reference to this image.
         */
        Image& operator=(const Image& other);
        
    private:
        unsigned char* data; ///< Pointer to image data.
        int width; ///< Image width.
        int height; ///< Image height.
        int channels; ///< Number of color channels.
        ImageState state; ///< The current state of the image.
        
        /**
         * @brief Converts an RGB color to HSL.
         */
        void rgbToHsl(float r, float g, float b, float &h, float &s, float &l);
        
        /**
         * @brief Converts an RGB color to HSV.
         */
        void rgbToHsv(float r, float g, float b, float &h, float &s, float &v);
        
        /**
         * @brief Converts an HSV color to RGB.
         */
        void hsvToRgb(float h, float s, float v, float &r, float &g, float &b);
        
        /**
         * @brief Converts an HSL color to RGB.
         */
        void hslToRgb(float h, float s, float l, float &r, float &g, float &b);
        
        /**
         * @brief Converts an HSL color to HSV.
         */
        void hslToHsv(float h, float s, float l, float &hh, float &ss, float &vv);
        
        /**
         * @brief Converts an HSV color to HSL.
         */
        void hsvToHsl(float h, float s, float v, float &hh, float &ss, float &ll);
    };
    

#endif // IMAGE_H