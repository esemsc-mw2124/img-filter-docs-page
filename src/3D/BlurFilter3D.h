/******************************************************************************
 * @file BlurFilter3D.h
 * @brief Header file for 3D image blurring techniques.
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

#ifndef _3D_BLUR_FILTER_H
#define _3D_BLUR_FILTER_H

#include "Filter.h"
#include "../Volume.h"
#include <vector>
#include <stdexcept>
#include <cmath>

enum class Filter3DType {
    GaussianBlur,
    MedianBlur
};

struct Filter3DParameters {
    int kernelSize;
    float sigma;
};

/**
 * @class BlurFilter3D
 * @brief A filter class for applying 3D blurring techniques to volumetric data.
 *
 * Supports Gaussian and median blurring for 3D volumes.
 */
class BlurFilter3D: public Filter {
    public:
        /**
         * @brief Constructs a 3D blur filter with specified parameters.
         * @param type The type of 3D blur filter to apply.
         * @param params The parameters for the blur effect.
         */
        BlurFilter3D(Filter3DType type, const Filter3DParameters& params)
            : type(type), params(params) {}
    
        /**
         * @brief Constructs a 3D blur filter with default parameters.
         * @param type The type of 3D blur filter to apply.
         */
        BlurFilter3D(Filter3DType type)
            : type(type), params({5, 2.0f}) {}  // Default values: 3x3x3 kernel, sigma = 2.0
    
        /**
         * @brief Applies the selected 3D blur filter to a volumetric dataset.
         * @param volume The volume to be processed.
         * @throws std::invalid_argument If an unknown filter type is provided.
         */
        void apply(Volume& volume) override {
            switch (type) {
                case Filter3DType::GaussianBlur:
                    gaussianBlur(volume, params.kernelSize, params.sigma);
                    break;
                case Filter3DType::MedianBlur:
                    medianBlur(volume, params.kernelSize);
                    break;
                default:
                    throw std::invalid_argument("Unknown 3D filter type");
            }
        }
        
        /**
         * @brief Throws an exception, as 2D image processing is not supported.
         * @param img The image to which the filter cannot be applied.
         * @throws std::runtime_error Always throws since 2D filtering is not supported.
         */
        void apply(Image& img) override {
            throw std::runtime_error("BlurFilter3D does not support 2D images.");
        }
        
    private:
        Filter3DType type; ///< The type of 3D blur filter.
        Filter3DParameters params; ///< The parameters for the blur effect.
        
        /**
         * @brief Applies Gaussian blur to a 3D volume.
         * @param volume The volume to process.
         * @param kernelSize The size of the Gaussian blur kernel.
         * @param sigma The standard deviation of the Gaussian kernel.
         */
        void gaussianBlur(Volume& volume, int kernelSize = 5, float sigma = 2.0f);
        
        /**
         * @brief Applies median blur to a 3D volume.
         * @param volume The volume to process.
         * @param kernelSize The size of the median blur kernel.
         */
        void medianBlur(Volume& volume, int kernelSize = 5);
        
        /**
         * @brief Internal method to apply a Gaussian blur kernel to a 3D volume.
         * @param volume The volume to process.
         * @param kernelSize The size of the Gaussian kernel.
         * @param sigma The standard deviation of the Gaussian kernel.
         */
        static void applyGaussianKernel(Volume& volume, int kernelSize, float sigma);
        
        /**
         * @brief Internal method to apply a median blur kernel to a 3D volume.
         * @param volume The volume to process.
         * @param kernelSize The size of the median kernel.
         */
        static void applyMedianKernel(Volume& volume, int kernelSize);
        
        /**
         * @brief Computes the Gaussian kernel weight for a given voxel offset.
         * @param x X-coordinate offset.
         * @param y Y-coordinate offset.
         * @param z Z-coordinate offset.
         * @param sigma The standard deviation of the Gaussian kernel.
         * @return The computed weight for the given offset.
         */
        static float gaussianKernel(int x, int y, int z, float sigma);
        
        /**
         * @brief Retrieves neighboring voxels for a given voxel position.
         * @param volume The volume to process.
         * @param x X-coordinate of the voxel.
         * @param y Y-coordinate of the voxel.
         * @param z Z-coordinate of the voxel.
         * @param kernelSize The size of the kernel used to extract neighbors.
         * @param neighbourhood A vector to store the retrieved neighboring voxel values.
         */
        static void getNeighbouringVoxels(const Volume& volume, int x, int y, int z, int kernelSize, std::vector<unsigned char>& neighbourhood);
    };
    

#endif // _3D_BLUR_FILTER_H
