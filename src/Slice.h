/******************************************************************************
 * @file Slice.h
 * @brief Header file for slice extraction from volume data.
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

#ifndef SLICE_H
#define SLICE_H

#include "Volume.h"
#include "Image.h"
#include <string>

/**
 * @class Slice
 * @brief A utility class for extracting 2D slices from a 3D volume.
 *
 * Supports extracting XZ and YZ slices from volumetric data.
 */
class Slice {
  public:
      /**
       * @brief Extracts an XZ slice from a 3D volume at a given Y-index.
       * @param volume The input 3D volume.
       * @param yIndex The Y-index at which the slice is extracted.
       * @param outputImage The output 2D image representing the extracted slice.
       * @return True if extraction is successful, false otherwise.
       */
      static bool extractXZSlice(const Volume& volume, int yIndex, Image& outputImage);
  
      /**
       * @brief Extracts a YZ slice from a 3D volume at a given X-index.
       * @param volume The input 3D volume.
       * @param xIndex The X-index at which the slice is extracted.
       * @param outputImage The output 2D image representing the extracted slice.
       * @return True if extraction is successful, false otherwise.
       */
      static bool extractYZSlice(const Volume& volume, int xIndex, Image& outputImage);
  };
#endif // SLICE_H
