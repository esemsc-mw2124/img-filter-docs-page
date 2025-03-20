/******************************************************************************
 * @file Sharpener.h
 * @brief Header file for image sharpening techniques.
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

#ifndef SHARPENER_H
#define SHARPENER_H
#include "../Image.h"
#include "../Filter.h"

/**
 * @class Sharpener
 * @brief A filter class for applying sharpening effects to images.
 *
 * Uses a Laplacian kernel to enhance the edges in an image.
 */
class Sharpener : public Filter {
    public:
        /**
         * @brief Applies the sharpening filter to an image.
         * @param img The image to process.
         */
        void apply(Image& img) override { 
            SharpenImage(img, laplacian); 
        }

        /**
         * @brief Throws an exception, as 3D volume sharpening is not supported.
         * @param vol The volume to which the sharpening filter cannot be applied.
         * @throws std::runtime_error Always throws since 3D sharpening is not supported.
         */
        void apply(Volume& vol) override {
            throw std::runtime_error("Sharpening filter does not support 3D volumes.");
        }

    private:
        /**
         * @brief Applies a sharpening filter using the provided 3x3 kernel.
         * @param img The image to be sharpened.
         * @param kernel The 3x3 sharpening kernel.
         */
        void SharpenImage(Image& img, const float kernel[3][3]);

        /**
         * @brief Laplacian kernel used for sharpening.
         */
        const float laplacian[3][3] = {
            {0, -1, 0},
            {-1, 4, -1},
            {0, -1, 0}
        };
};
   

#endif // SHARPENER_H
