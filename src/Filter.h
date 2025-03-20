/******************************************************************************
 * @file Filter.h
 * @brief Header file for filter interface used in image and volume processing.
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

// Filter.h
#ifndef FILTER_H
#define FILTER_H

#include "Image.h"
#include "Volume.h"

/**
 * @class Filter
 * @brief An abstract base class for image and volume processing filters.
 *
 * Defines a common interface for applying filters to both 2D images and 3D volumes.
 */
class Filter {
    public:
        /**
         * @brief Applies the filter to a 2D image.
         * @param img The image to process.
         */
        virtual void apply(Image& img) = 0;  // For 2D images
        
        /**
         * @brief Applies the filter to a 3D volume.
         * @param vol The volume to process.
         */
        virtual void apply(Volume& vol) = 0; // For 3D volumes
    };
#endif // FILTER_H
