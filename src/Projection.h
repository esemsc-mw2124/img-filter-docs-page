/******************************************************************************
 * @file Projection.h
 * @brief Header file for projection techniques on volumetric data.
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

#ifndef PROJECTION_H
#define PROJECTION_H

#include "Volume.h"
#include "Image.h"

/**
 * @class Projection
 * @brief A class for performing intensity projection operations on 3D volumes.
 *
 * Supports maximum, minimum, mean, and median intensity projections.
 */
class Projection{
    public:
        /**
         * @brief Default constructor.
         */
        Projection() = default;
    
        /**
         * @brief Default destructor.
         */
        ~Projection() = default;
    
        /**
         * @brief Computes the maximum intensity projection of a volume.
         * @param volume The input 3D volume.
         * @param output The output 2D image.
         */
        static void maxIntensityProjection(const Volume& volume, Image& output);
    
        /**
         * @brief Computes the minimum intensity projection of a volume.
         * @param volume The input 3D volume.
         * @param output The output 2D image.
         */
        static void minIntensityProjection(const Volume& volume, Image& output);
    
        /**
         * @brief Computes the mean intensity projection of a volume.
         * @param volume The input 3D volume.
         * @param output The output 2D image.
         */
        static void meanIntensityProjection(const Volume& volume, Image& output);
    
        /**
         * @brief Computes the median intensity projection of a volume.
         * @param volume The input 3D volume.
         * @param output The output 2D image.
         */
        static void medianIntensityProjection(const Volume& volume, Image& output);
    };
    
#endif // PROJECTIONFILTER3D_H