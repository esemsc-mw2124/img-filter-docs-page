/******************************************************************************
 * @file Volume.h
 * @brief Header file for the Volume class, which handles 3D volume data.
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

#ifndef VOLUME_H
#define VOLUME_H

#include <iostream>
#include <vector>
#include <string>

// Enum for tracking volume processing state
enum class VolumeState {
    RAW, // Unprocessed volume
    PROCESSED, // Processed volume
    UNKNOWN // Uninitialized state
};

/**
 * @class Volume
 * @brief A class for representing and managing 3D volumetric data.
 *
 * Supports loading volumes from image slices, retrieving volume properties,
 * and saving slices as 2D images.
 */
class Volume {
    public:
        /**
         * @brief Default constructor.
         */
        Volume();
        
        /**
         * @brief Constructs a volume from a sequence of image slices.
         * @param folderPath Path to the folder containing image slices.
         * @param filePrefix Prefix of the image files.
         * @param startIdx Index of the first image slice.
         * @param endIdx Index of the last image slice.
         * @param fileExtension Extension of the image files (e.g., .png, .jpg).
         */
        Volume(const std::string& folderPath, const std::string& filePrefix, int startIdx, int endIdx, const std::string& fileExtension);
        
        /**
         * @brief Destructor to free allocated memory.
         */
        ~Volume();
    
        /**
         * @brief Gets the current state of the volume.
         * @return The volume state.
         */
        VolumeState getState() const;
        
        /**
         * @brief Gets the width of the volume.
         * @return The width in pixels.
         */
        int getWidth() const;
        
        /**
         * @brief Gets the height of the volume.
         * @return The height in pixels.
         */
        int getHeight() const;
        
        /**
         * @brief Gets the depth of the volume (number of slices).
         * @return The depth in slices.
         */
        int getDepth() const;
        
        /**
         * @brief Gets the number of channels in the volume.
         * @return The number of channels.
         */
        int getChannels() const;
        
        /**
         * @brief Gets the raw volume data.
         * @return A pointer to the volume data.
         */
        const unsigned char* getData() const;
        
        /**
         * @brief Saves all slices of the volume as images.
         * @param outputFolder Path to the folder where slices will be saved.
         * @param quality Image quality for saving (if applicable).
         * @param fileExtension File extension for the saved images.
         */
        void saveSlices(const std::string& outputFolder, int quality, const std::string& fileExtension) const;
    
    private:
        unsigned char* data; ///< Pointer to volume data.
        int width; ///< Width of the volume.
        int height; ///< Height of the volume.
        int depth; ///< Depth of the volume (number of slices).
        int channels; ///< Number of color channels.
        VolumeState state; ///< The current state of the volume.
    
        /**
         * @brief Loads a volume from a folder containing 2D image slices.
         * @param folderPath Path to the folder containing image slices.
         * @param filePrefix Prefix of the image files.
         * @param startIdx Index of the first image slice.
         * @param endIdx Index of the last image slice.
         * @param fileExtension Extension of the image files.
         */
        void loadVolume(const std::string& folderPath, const std::string& filePrefix, int startIdx, int endIdx, const std::string& fileExtension);
        
        /**
         * @brief Utility function to compare filenames for sorting.
         * @param a First filename.
         * @param b Second filename.
         * @return True if a should come before b in sorting order.
         */
        static bool compareFileNames(const std::string& a, const std::string& b);
    };
    
#endif // VOLUME_H