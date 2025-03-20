/******************************************************************************
 * @file SimpleFilter.cpp
 * @brief Implementation file for simple image filtering techniques.
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

#include "SimpleFilter.h"
#include <stdexcept>
#include "../Image.h"

// Apply histogram equalization to the specified channel of an image.
void SimpleFilter::applyHistogramEqualizationForChannel(Image& img, int width, int height, int pixelSize, int channelIndex) {
    // Compute the histogram for the selected channel
    int hist[256] = {0};
    for (int i = 0; i < width * height * pixelSize; i += pixelSize) {
        int x = (i / pixelSize) % width;   // Calculate the column
        int y = (i / pixelSize) / width;   // Calculate the row    
        
        // Ensure correct channel index (V or L, not H)
        hist[img(x, y, channelIndex)]++;  
    }

    // Compute the cumulative distribution function (CDF)
    int cdf[256] = {0};
    cdf[0] = hist[0];
    for (int i = 1; i < 256; ++i) {
        cdf[i] = cdf[i - 1] + hist[i];
    }

    // Normalize the CDF and create the lookup table
    int totalPixels = width * height;
    unsigned char lookupTable[256];
    for (int i = 0; i < 256; ++i) {
        lookupTable[i] = static_cast<unsigned char>((cdf[i] - cdf[0]) * 255 / (totalPixels - cdf[0]));
    }

    // Apply the equalization to the selected channel (V or L)
    for (int i = 0; i < width * height * pixelSize; i += pixelSize) {
        int x = (i / pixelSize) % width;   // Calculate the column
        int y = (i / pixelSize) / width;   // Calculate the row 
        
        // Apply the lookup table to the selected channel (V or L)
        img(x, y, channelIndex) = lookupTable[img(x, y, channelIndex)];
    }
} 


// helper function- mean brightness
float SimpleFilter::calculateMeanBrightness(Image& img) {
    float sum = 0.0;
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();
    int totalPixels = width * height;

    switch (channels) {
        case 1:
            // gray image
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    sum += img(x, y, 0);
                }
            }
            break;

        case 3:
        case 4:
            // RGB or RGBA image
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    sum += img(x, y, 0); // R
                    sum += img(x, y, 1); // G
                    sum += img(x, y, 2); // B
                }
            }
            sum /= 3.0;
            break;

        default:
            throw std::invalid_argument("Unsupported number of channels");
    }

    return sum / totalPixels;
}

void SimpleFilter::applyGrayScale(Image &img)
{
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();
    Image gray_img(width, height, 1);

    // Process each pixel
    for (int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            // Get the RGB values
            float r = img(i,j,0);
            float g = img(i,j,1);
            float b = img(i,j,2);

        // Calculate luminance using the formula
            gray_img(i,j) = static_cast<unsigned char>(0.2126 * r + 0.7152 * g + 0.0722 * b);
        }

    }
    img.setData(gray_img);
}

void SimpleFilter::applyBrightnessDullness(Image &img, float brightness)
{
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();
    Image img_sp = Image(img);

    // automatic brightness filter
    if (brightness < -255.0f || brightness > 255.0f)
    {
        // calculate the mean brightness
        float avg = calculateMeanBrightness(img_sp);
        // compute offset to make the average brightness reach 128
        brightness = static_cast<int>(128.0f - avg);
    }

    // adjust brightness for each pixel
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            switch (channels)
            {
                case 1: // gray image
                {
                    float newVal = img_sp(x, y, 0) + brightness;
                    newVal = std::min(255.0f, std::max(0.0f, newVal));
                    img_sp(x, y, 0) = static_cast<unsigned char>(newVal);
                    break;
                }

                case 3: // RGB
                case 4: // RGBA
                {
                    for (int c = 0; c < 3; ++c)
                    {
                        int newVal = img_sp(x, y, c) + brightness;
                        newVal = std::min(255, std::max(0, newVal));
                        img_sp(x, y, c) = static_cast<unsigned char>(newVal);
                    }
                    break;
                }

                default:
                    throw std::invalid_argument("Unsupported number of channels");
            }
        }
    }
    img.setData(img_sp);
}


void SimpleFilter::applyHistogramEqualization(Image &img, const std::string &colorSpace)
{
    // Convert color space to lowercase for case-insensitive comparison
    std::string colorSpaceLower = colorSpace;
    std::transform(colorSpaceLower.begin(), colorSpaceLower.end(), colorSpaceLower.begin(), ::tolower);

    // unsigned char *data = const_cast<unsigned char *>(img.getData());
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();
    Image img_sp(img);

    // Use a switch-case to handle different image types and color spaces
    switch (img.getState())
    {
    case ImageState::GRAY:
    {
        // For grayscale images, directly apply histogram equalization
        // Stretch the histogram to fill the range 0-255
        applyHistogramEqualizationForChannel(img_sp, width, height, 1, 0); // Channel index 0 for grayscale
        break;
    }

    case ImageState::RGB:
    case ImageState::RGBA:
    {
        // For RGB images, process the image based on the chosen color space (HSV or HSL)
        if (colorSpaceLower == "hsv")
        {
            img_sp.convertToHSV(); // Convert to HSV color space
        }
        else if (colorSpaceLower == "hsl")
        {
            img_sp.convertToHSL(); // Convert to HSL color space
        }
        else
        {
            throw std::runtime_error("Invalid color space choice. Use 'HSV' or 'HSL'.");
        }

        // Equalize the intensity values of the V (Value) or L (Luminance) channel
        applyHistogramEqualizationForChannel(img_sp, width, height, channels, 2); // 2 is the index for V or L channel

        // Convert the processed image back to RGB color space
        img_sp.convertToRGB(); // Convert back to RGB from HSV or HSL
        break;
    }

    default:
        throw std::runtime_error("Unsupported image state for histogram equalization.");
    }
    img.setData(img_sp);
}


void SimpleFilter::applyThreshold(Image& img, float threshold, const std::string &colorSpace) {
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();
    Image img_sp = Image(img);

    switch (channels) {
        case 1:
            // gray image
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    img_sp(x, y, 0) = (img(x, y, 0) >= threshold) ? 255 : 0;
                }
            }
            break;

        case 3:
        case 4: {
            // RGB or RGBA image

            // Create a new image with the same dimensions
            if (colorSpace == "HSV") {
                img.convertToHSV();
            } else if (colorSpace == "HSL") {
                img.convertToHSL();
            } else {
                throw std::invalid_argument("Invalid color space specified for thresholding");
            }

            // Create a new image with the same dimensions
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    float v = img(x, y, 2) / 255.0f;  // Normalize the value channel
                    unsigned char newValue = (v * 255 >= threshold) ? 255 : 0;

                    // Set the new RGB values
                    img_sp(x, y, 0) = newValue;
                    img_sp(x, y, 1) = newValue;
                    img_sp(x, y, 2) = newValue;

                    // Set the alpha channel if present
                    if (channels == 4) {
                        img_sp(x, y, 3) = 255;
                    }
                }
            }
            img_sp.convertToRGB();
            break;
        }

        default:
            throw std::runtime_error("Unsupported image format");
    }
    // img_sp.save("Outputs/applyThreshold.png", 100);
    img.setData(img_sp);
}

void SimpleFilter::applySaltPepperNoise(Image &img, int percentage)
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    int width = img.getWidth();
    int height = img.getHeight();
    int totalPixels = width * height;

    Image img_sp = Image(img);
    int numNoisyPixels = (totalPixels * percentage) / 100; // Calculate the number of pixels to add noise

    int pixelSize = img.getChannels();

    for (int i = 0; i < numNoisyPixels; ++i)
    {
        // Randomly select a pixel index
        int pixelIndex = rand() % totalPixels;
        int x = pixelIndex % width;  // Column (x coordinate)
        int y = pixelIndex / width;  // Row (y coordinate)

        // Randomly choose between salt (white) or pepper (black)
        unsigned char noiseValue = (rand() % 2 == 0) ? 0 : 255; // 50% chance of black (0) or white (255)

        // Apply salt and pepper noise (Set R, G, B channels)
        if (img.getState() == ImageState::GRAY)
        {
            img_sp(x,y,0) = noiseValue;
        }else{
            img_sp(x,y,0)  = noiseValue;     // R channel
            img_sp(x,y,1)  = noiseValue; // G channel
            img_sp(x,y,2)  = noiseValue; // B channel
        }
    }
    img.setData(img_sp);
}
