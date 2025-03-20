/******************************************************************************
 * @file main.cpp
 * @brief Main implementation file for the APImageFilters application.
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

// A minimal example file showing how to include the stb image headers,
// and how to read and write image files using these headers.
//
// Compilation with (e.g.): g++-14 main.cpp -o main
//
// Written by T.M. Davison (2023-25)

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"
// #define STB_IMAGE_WRITE_IMPLEMENTATION
// #include "stb_image_write.h"

// Add gaurds to the header files
// #ifndef IMAGE_H
// #define IMAGE_H

#include "Projection.h"
#include "utils/MedianUtils.h"

#include <numeric>
#include <random>
#include <deque>

#include <iostream>
#include <chrono>

using namespace std;

#include "Projection.h"
#include <iostream>
#include <string>
#include "Image.h"
#include "Filter.h"
#include "2D/EdgeDetector.h"
#include "2D/Sharpener.h"
#include "Volume.h"
#include "3D/BlurFilter3D.h"
#include "2D/SimpleFilter.h"
#include "2D/Blur.h"
#include "Slice.h"




int main(int argc, char* argv[]) {
    // Mnimum expected usage: ./APImageFilters <datatype_flag> <input_image_file> <processing_flag> <output_image_file>
    if (argc < 4) {
        std::cerr << "Expected: " << argv[0] << " [-i | -d] <input_image> <processing_flag> <output_image>" << std::endl;
        return 1;
    }

    // Store filenames and image datatype
    std::string inputImageFile;
    std::string outputImageFile;
    bool isVolume = false;

    // Store the order of processing options in deque
    std::deque<std::string> processingOrder;

    // Image processing options (2D)
    // Greyscale
    bool applyGreyscale = false;

    // Brightness
    bool applyBrightness = false;
    int brightnessVal = 0;

    // Histogram equalisation
    bool applyHistogram = false;
    std::string histogramType;

    // Blurring
    bool applyBlur = false;
    std::string blurType;
    int blurSize = 0;
    double blurStdev = 2.0;

    // Edge detection
    bool applyEdge = false;
    std::string edgeType;

    // Sharpening
    bool applySharpen = false;

    // Salt and pepper
    bool applySaltPepper = false;
    int saltPepperAmount = 0;

    // Threshold
    bool applyThreshold = false;
    float thresholdVal = 0;
    std::string thresholdType; // "HSV", "HSL", or leave empty for greyscale


    // Volume processing options (3D)
    bool setFirst = false;
    int firstSlice = 0;
    bool setLast = false;
    int lastSlice = 0;
    bool setReadExtension = false;
    std::string readExtension = "";

    // Volume Slicing
    bool applySlice = false;
    std::string slicePlane;
    int sliceIndex = 0;

    // Volume Projection
    bool applyProjection = false;
    std::string projectionType;

    // Last argument is the output image filename
    outputImageFile = argv[argc - 1];

    // Process remaining arguments (from second arg up until second-to-last arg)
    // (First arg is ./APImageFilter so we can skip it)
    for (int i = 1; i < argc - 1; i++) {
        std::string arg = argv[i];

        // Input is an image (-i)
        if (arg == "-i") {
            if (i + 1 < argc - 1) {
                inputImageFile = argv[++i];
            } else {
                std::cerr << "Error: Missing input image filename after -i" << std::endl;
                return 1;
            }
        }
        // Input is a volume (-d)
        else if (arg == "-d") {
            if (i + 1 < argc - 1) {
                inputImageFile = argv[++i];
                isVolume = true;
            } else {
                std::cerr << "Error: Missing input volume filename after -d" << std::endl;
                return 1;
            }
        }

        // Greyscale
        else if (arg == "--greyscale" || arg == "-g") {
            applyGreyscale = true;
            processingOrder.push_back("greyscale");
        }

        // Brightness
        else if (arg == "--brightness" || arg == "-b") {
            if (i + 1 < argc - 1) {
                brightnessVal = std::stoi(argv[++i]); // std::stoi converts string to integer
                applyBrightness = true;
                processingOrder.push_back("brightness");
            } else {
                std::cerr << "Error: Missing brightness value after " << arg << std::endl;
                return 1;
            }
        }

        // Histogram equalisation
        else if (arg == "--histogram" || arg == "-h") {
            if (i + 1 < argc - 1) {
                histogramType = argv[++i];
                applyHistogram = true;
                processingOrder.push_back("histogram");
            } else {
                std::cerr << "Error: Missing histogram type after " << arg << std::endl;
                return 1;
            }
        }

        // Blur -> CODE REVIEW - CHECK THIS ONE THOROUGHLY AS IT MAY CAUSE ISSUES W FLAG OPTIONALITY
        else if (arg == "--blur" || arg == "-r") {
            if (i + 2 < argc - 1) {
                blurType = argv[++i];
                blurSize = std::stoi(argv[++i]);
                // Gaussian blur
                if ((blurType == "Gaussian" || blurType == "gaussian") && (i + 1 < argc - 1)) {
                    try {
                        blurStdev = std::stod(argv[i + 1]);
                        ++i;
                    } catch (const std::exception &e) {
                        std::cerr << "Warning: Invalid standard deviation for Gaussian blur. Using default value of 2.0." << std::endl;
                        blurStdev = 2.0;
                    }
                }
                applyBlur = true;
                processingOrder.push_back("blur");
            } else {
                std::cerr << "Error: Missing arguments for blur option" << std::endl;
                return 1;
            }
        }

        // Edge detection
        else if (arg == "--edge" || arg == "-e") {
            if (i + 1 < argc - 1) {
                edgeType = argv[++i];
                applyEdge = true;
                processingOrder.push_back("edge");
            } else {
                std::cerr << "Error: Missing edge detection type after " << arg << std::endl;
                return 1;
            }
        }

        // Sharpening
        else if (arg == "--sharpen" || arg == "-p" && !isVolume) {
            applySharpen = true;
            processingOrder.push_back("sharpen");
        }

        // Salt and pepper 
        else if (arg == "--saltpepper" || arg == "-n") {
            if (i + 1 < argc - 1) {
                saltPepperAmount = std::stoi(argv[++i]);
                applySaltPepper = true;
                processingOrder.push_back("saltpepper");
            } else {
                std::cerr << "Error: Missing noise amount after " << arg << std::endl;
                return 1;
            }
        }

        // Threshold
        else if (arg == "--threshold" || arg == "-t") {
            if (i + 2 < argc - 1) {
                thresholdVal = std::stof(argv[++i]);
                thresholdType = argv[++i];
                applyThreshold = true;
                processingOrder.push_back("threshold");
            } else {
                std::cerr << "Error: Missing arguments for threshold option" << std::endl;
                return 1;
            }
        }

        // Volume processing options
        // First slice
        else if (arg == "--first" || arg == "-f") {
            if (i + 1 < argc - 1) {
                firstSlice = std::stoi(argv[++i]);
                setFirst = true;
            } else {
                std::cerr << "Error: Missing first slice number after " << arg << std::endl;
                return 1;
            }
        }

        // Last slice
        else if (arg == "--last" || arg == "-l") {
            if (i + 1 < argc - 1) {
                lastSlice = std::stoi(argv[++i]);
                setLast = true;
            } else {
                std::cerr << "Error: Missing last slice number after " << arg << std::endl;
                return 1;
            }
        }

        // Read extension
        else if (arg == "--extension" || arg == "-x") {
            if (i + 1 < argc - 1) {
                readExtension = argv[++i];
                setReadExtension = true;
            } else {
                std::cerr << "Error: Missing read extension after " << arg << std::endl;
                return 1;
            }
        }

        // Slice
        else if (arg == "--slice" || arg == "-s") {
            if (i + 2 < argc - 1) {
                slicePlane = argv[++i];
                sliceIndex = std::stoi(argv[++i]);
                applySlice = true;
                processingOrder.push_back("slice");
            } else {
                std::cerr << "Error: Missing slice plane and index after " << arg << std::endl;
                return 1;
            }
        }

        // Projection
        else if (arg == "--projection" || arg == "-p" && isVolume) {
            if (i + 1 < argc - 1) {
                projectionType = argv[++i];
                applyProjection = true;
                processingOrder.push_back("projection");
            } else {
                std::cerr << "Error: Missing projection type after " << arg << std::endl;
                return 1;
            }
        }
    }

    if (inputImageFile.empty()) {
        std::cerr << "Error: No input file specified. Use -i for image or -d for volume." << std::endl;
        return 1;
    }

    try {
        if (!isVolume) {
            // Load input image
            Image img(inputImageFile);

            // Apply filters in the order encountered.
            for(auto filter: processingOrder)
            {
                if (filter == "greyscale") {
                    SimpleFilter grayscale(SimpleFilterType::GrayScale);
                    grayscale.apply(img);
                }

                if (filter == "brightness") {
                    SimpleFilterParameters simple_params;
                    simple_params.brightness = brightnessVal;
                    SimpleFilter brightness(SimpleFilterType::BrightnessDullness, simple_params);
                    brightness.apply(img);
                }

                if (filter == "histogram") {
                    if (histogramType == "HSV" || histogramType == "hsv") {
                        SimpleFilterParameters simple_params;
                        simple_params.colorSpace = "HSV";
                        SimpleFilter histogram(SimpleFilterType::HistogramEqualization, simple_params);
                        histogram.apply(img);
                    } else if (histogramType == "HSL" || histogramType == "hsl") {
                        SimpleFilterParameters simple_params;
                        simple_params.colorSpace = "HSL";
                        SimpleFilter histogram(SimpleFilterType::HistogramEqualization, simple_params);
                        histogram.apply(img);
                    } else {
                        std::cerr << "Unknown histogram type: " << histogramType << std::endl;
                    }
                }

                if (filter == "blur") {
                    if (blurType == "Gaussian" || blurType == "gaussian") {
                        BlurParameters params;
                        params.kernelSize = blurSize;
                        params.sigma = blurStdev;
                        Blur gaussian_blur(BlurType::Gaussian, params);
                        gaussian_blur.apply(img);
                    } else if (blurType == "Box" || blurType == "box") {
                        BlurParameters params;
                        params.blurSize = blurSize;
                        Blur box_blur(BlurType::Box, params);
                        box_blur.apply(img);
                    } else if (blurType == "Median" || blurType == "median") {
                        BlurParameters params;
                        params.kernelSize = blurSize;
                        Blur median_blur(BlurType::Median, params);
                        median_blur.apply(img);
                    } else {
                        std::cerr << "Unknown blur type: " << blurType << std::endl;
                    }
                }

                if (filter == "edge") {
                    if (edgeType == "Sobel" || edgeType == "sobel") {
                        EdgeDetector sobel_edgeDetector(EdgeDetectionType::Sobel);
                        sobel_edgeDetector.apply(img);
                    } else if (edgeType == "Prewitt" || edgeType == "prewitt") {
                        EdgeDetector prewitt_edgeDetector(EdgeDetectionType::Prewitt);
                        prewitt_edgeDetector.apply(img);
                    } else if (edgeType == "Scharr" || edgeType == "scharr") {
                        EdgeDetector scharr_edgeDetector(EdgeDetectionType::Scharr);
                        scharr_edgeDetector.apply(img);
                    } else if (edgeType == "RobertsCross" || edgeType == "robertscross") {
                        EdgeDetector robertsCross_edgeDetector(EdgeDetectionType::RobertsCross);
                        robertsCross_edgeDetector.apply(img);
                    } else {
                        std::cerr << "Unknown edge detection type: " << edgeType << std::endl;
                    }
                } 
                
                if (filter == "sharpen") {
                    Sharpener sharpening;
                    sharpening.apply(img);
                }

                if (filter == "saltpepper") {
                    SimpleFilterParameters simple_params;
                    simple_params.percentage = saltPepperAmount;
                    SimpleFilter saltPepper(SimpleFilterType::SaltPepperNoise, simple_params);
                    saltPepper.apply(img);
                }

                if (filter == "threshold") {
                    SimpleFilterParameters simple_params;
                    simple_params.colorSpace = thresholdType;
                    SimpleFilter threshold(SimpleFilterType::Threshold, simple_params);
                    threshold.apply(img);
                }
            }

            // Save the processed image
            img.save(outputImageFile);
            std::cout << "Image processed and saved to " << outputImageFile << std::endl;
        }
        else
        {
            // Split the inputImageFile into folder and fileprefix 
            std::string folder = inputImageFile.substr(0, inputImageFile.find_last_of("/\\") + 1);
            std::string fileprefix = inputImageFile.substr(inputImageFile.find_last_of("/\\") + 1);

            // Load input volume 
            Volume vol(folder, fileprefix, firstSlice, lastSlice, readExtension);

            // Apply filters in the order encountered.
            if (applyBlur) {
                if (blurType == "Gaussian" || blurType == "gaussian") {
                    Filter3DParameters params;
                    params.kernelSize = blurSize;
                    params.sigma = blurStdev;
                    BlurFilter3D gaussian_blur(Filter3DType::GaussianBlur, params);
                    gaussian_blur.apply(vol);
                    // CHANGE!! BlurFilter3D::gaussianBlur(vol, blurSize, blurStdev);
                } else if (blurType == "Median" || blurType == "median") {
                    Filter3DParameters params;
                    params.kernelSize = blurSize;
                    BlurFilter3D median_blur(Filter3DType::MedianBlur, params);
                    median_blur.apply(vol);
                    // CHANGE!! BlurFilter3D::medianBlur(vol, blurSize);
                } else {
                    std::cerr << "Unknown blur type: " << blurType << std::endl;
                }
            }

            if (applySlice) {
                Image slice;

                // convert slice plane to lowercase
                std::transform(slicePlane.begin(), slicePlane.end(), slicePlane.begin(), ::tolower);

                if (slicePlane == "xz"|| slicePlane == "zx") {
                    Slice::extractXZSlice(vol, sliceIndex, slice);
                    slice.save(outputImageFile);
                    std::cout << "Slice processed and saved to " << outputImageFile << std::endl;
                } else if (slicePlane == "yz" || slicePlane == "zy") {
                    Slice::extractYZSlice(vol, sliceIndex, slice);
                    slice.save(outputImageFile);
                    std::cout << "Slice processed and saved to " << outputImageFile << std::endl;
                } else {
                    std::cerr << "Unknown slice plane: " << slicePlane << std::endl;
                }
            }

            if (applyProjection) {
                Image out;

                // convert projection type to lowercase
                std::transform(projectionType.begin(), projectionType.end(), projectionType.begin(), ::tolower);

                if (projectionType == "mip") {
                    Projection::maxIntensityProjection(vol, out);
                    out.save(outputImageFile);
                    std::cout << "Projection processed and saved to " << outputImageFile << std::endl;
                } else if (projectionType == "meanaip") {
                    Projection::meanIntensityProjection(vol, out);
                    out.save(outputImageFile);
                    std::cout << "Projection processed and saved to " << outputImageFile << std::endl;
                } else if (projectionType == "minip") {
                    Projection::minIntensityProjection(vol, out);
                    out.save(outputImageFile);
                    std::cout << "Projection processed and saved to " << outputImageFile << std::endl;
                } else if (projectionType == "medianaip") {
                    Projection::medianIntensityProjection(vol, out);
                    out.save(outputImageFile);
                    std::cout << "Projection processed and saved to " << outputImageFile << std::endl;
                } else {
                    std::cerr << "Unknown projection type: " << projectionType << std::endl;
                }
            }
        }
    }
    catch (const std::exception &ex) {
        std::cerr << "Error processing image: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
