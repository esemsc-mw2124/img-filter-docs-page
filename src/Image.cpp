/******************************************************************************
 * @file Image.cpp
 * @brief Implementation file for image processing techniques.
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

#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


Image::Image() : data(nullptr), width(0), height(0), channels(0), state(ImageState::UNKNOWN) {}

Image::Image(const std::string& filename) {
    data = stbi_load(filename.c_str(), &width, &height, &channels, 0);
    if (!data) {
        width = height = channels = 0;
        throw std::runtime_error("Failed to load image");
    }

    switch (channels) {
    case 1:
        state = ImageState::GRAY;
        break;
    case 2:
        state = ImageState::GRAYA;
        break;
    case 3:
        state = ImageState::RGB;
        break;
    case 4:
        state = ImageState::RGBA;
        break;
    default:
        state = ImageState::UNKNOWN;
        break;
    }
}

Image::Image(int width, int height, int channels)
{
    this->width = width;
    this->height = height;
    this->channels = channels;
    data = new unsigned char[width * height * channels];
    switch (channels) {
    case 1:
        state = ImageState::GRAY;
        break;
    case 2:
        state = ImageState::GRAYA;
        break;
    case 3:
        state = ImageState::RGB;
        break;
    case 4:
        state = ImageState::RGBA;
        break;
    default:
        state = ImageState::UNKNOWN;
        break;
    } 
}

Image::Image(unsigned char *data, int width, int height, int channels, ImageState state)
{
    this->data = data;
    this->width = width;
    this->height = height;
    this->channels = channels;
    this->state = state;
}

// Copy constructor implementation
Image::Image(const Image& other) {
    // Allocate new memory and copy data
    width = other.width;
    height = other.height;
    channels = other.channels;
    state = other.state;
    
    if (other.data) {
        size_t dataSize = width * height * channels;
        data = new unsigned char[dataSize];
        std::memcpy(data, other.data, dataSize);
    } else {
        data = nullptr;
    }
}

// Overloaded setData implementation to copy from another Image
void Image::setData(const Image& other) {
    // Free existing memory if any
    if (this->data) {
        stbi_image_free(this->data);
    }
    
    // Copy dimensions and state
    this->width = other.width;
    this->height = other.height;
    this->channels = other.channels;
    this->state = other.state;
    
    // Allocate new memory and copy data
    if (other.data) {
        size_t dataSize = width * height * channels;
        this->data = new unsigned char[dataSize];
        std::memcpy(this->data, other.data, dataSize);
    } else {
        this->data = nullptr;
    }
}

Image::~Image()
{
    if (data) {
        stbi_image_free(data);
    }
}

ImageState Image::getState() const {
    return state;
}

void Image::rgbToHsl(float r, float g, float b, float& h, float& s, float& l) {
    float max = std::max({r, g, b});
    float min = std::min({r, g, b});
    l = (max + min) / 2.0f;

    if (max == min) {
        h = s = 0.0f;
    } else {
        float d = max - min;
        s = l > 0.5f ? d / (2.0f - max - min) : d / (max + min);
        if (max == r) {
            h = (g - b) / d + (g < b ? 6.0f : 0.0f);
        } else if (max == g) {
            h = (b - r) / d + 2.0f;
        } else {
            h = (r - g) / d + 4.0f;
        }
        h /= 6.0f;
    }
}

void Image::rgbToHsv(float r, float g, float b, float& h, float& s, float& v) {
    float max = std::max({r, g, b});
    float min = std::min({r, g, b});
    v = max;
    float d = max - min;
    s = max == 0 ? 0 : d / max;

    if (max == min) {
        h = 0;
    } else {
        if (max == r) {
            h = (g - b) / d + (g < b ? 6.0f : 0.0f);
        } else if (max == g) {
            h = (b - r) / d + 2.0f;
        } else {
            h = (r - g) / d + 4.0f;
        }
        h /= 6.0f;
    }
}

void Image::convertToHSL() {
    // If already in HSL/HSLA format, no conversion needed
    if (state == ImageState::HSL || state == ImageState::HSLA) {
        return;
    }
    
    // Direct conversion from HSV/HSVA to HSL/HSLA
    if (state == ImageState::HSV || state == ImageState::HSVA) {
        int pixelSize = (state == ImageState::HSVA) ? 4 : 3;
        for (int i = 0; i < width * height * pixelSize; i += pixelSize) {
            float h = data[i] / 255.0f;
            float s = data[i + 1] / 255.0f;
            float v = data[i + 2] / 255.0f;
            float outH, outS, outL;
            
            hsvToHsl(h, s, v, outH, outS, outL);
            
            data[i] = static_cast<unsigned char>(outH * 255);
            data[i + 1] = static_cast<unsigned char>(outS * 255);
            data[i + 2] = static_cast<unsigned char>(outL * 255);
        }
        state = (state == ImageState::HSVA) ? ImageState::HSLA : ImageState::HSL;
        return;
    }
    
    // Conversion from RGB/RGBA to HSL/HSLA
    if (!data || (state != ImageState::RGB && state != ImageState::RGBA)) {
        throw std::runtime_error("Invalid image state for HSL conversion");
    }

    int pixelSize = (state == ImageState::RGBA) ? 4 : 3;
    for (int i = 0; i < width * height * pixelSize; i += pixelSize) {
        float r = data[i] / 255.0f;
        float g = data[i + 1] / 255.0f;
        float b = data[i + 2] / 255.0f;
        float h, s, l;
        rgbToHsl(r, g, b, h, s, l);
        data[i] = static_cast<unsigned char>(h * 255);
        data[i + 1] = static_cast<unsigned char>(s * 255);
        data[i + 2] = static_cast<unsigned char>(l * 255);
    }
    state = (state == ImageState::RGBA) ? ImageState::HSLA : ImageState::HSL;
}

void Image::convertToHSV() {
    // If already in HSV/HSVA format, no conversion needed
    if (state == ImageState::HSV || state == ImageState::HSVA) {
        return;
    }
    
    // Direct conversion from HSL/HSLA to HSV/HSVA
    if (state == ImageState::HSL || state == ImageState::HSLA) {
        int pixelSize = (state == ImageState::HSLA) ? 4 : 3;
        for (int i = 0; i < width * height * pixelSize; i += pixelSize) {
            float h = data[i] / 255.0f;
            float s = data[i + 1] / 255.0f;
            float l = data[i + 2] / 255.0f;
            float outH, outS, outV;
            
            hslToHsv(h, s, l, outH, outS, outV);
            
            data[i] = static_cast<unsigned char>(outH * 255);
            data[i + 1] = static_cast<unsigned char>(outS * 255);
            data[i + 2] = static_cast<unsigned char>(outV * 255);
        }
        state = (state == ImageState::HSLA) ? ImageState::HSVA : ImageState::HSV;
        return;
    }
    
    // Conversion from RGB/RGBA to HSV/HSVA
    if (!data || (state != ImageState::RGB && state != ImageState::RGBA)) {
        throw std::runtime_error("Invalid image state for HSV conversion");
    }

    int pixelSize = (state == ImageState::RGBA) ? 4 : 3;
    for (int i = 0; i < width * height * pixelSize; i += pixelSize) {
        float r = data[i] / 255.0f;
        float g = data[i + 1] / 255.0f;
        float b = data[i + 2] / 255.0f;
        float h, s, v;
        rgbToHsv(r, g, b, h, s, v);
        data[i] = static_cast<unsigned char>(h * 255);
        data[i + 1] = static_cast<unsigned char>(s * 255);
        data[i + 2] = static_cast<unsigned char>(v * 255);
    }
    state = (state == ImageState::RGBA) ? ImageState::HSVA : ImageState::HSV;
}

void Image::convertToRGB() {
    // If already in RGB/RGBA format, no conversion needed
    if (state == ImageState::RGB || state == ImageState::RGBA) {
        return;
    }
    
    // Check if valid state for conversion
    if (!data || (state != ImageState::HSL && state != ImageState::HSLA && 
                  state != ImageState::HSV && state != ImageState::HSVA)) {
        throw std::runtime_error("Invalid image state for RGB conversion");
    }

    int pixelSize = (state == ImageState::HSLA || state == ImageState::HSVA) ? 4 : 3;
    for (int i = 0; i < width * height * pixelSize; i += pixelSize) {
        float h = data[i] / 255.0f;
        float s = data[i + 1] / 255.0f;
        float v_or_l = data[i + 2] / 255.0f;
        float r, g, b;

        if (state == ImageState::HSL || state == ImageState::HSLA) {
            hslToRgb(h, s, v_or_l, r, g, b);
        } else {
            hsvToRgb(h, s, v_or_l, r, g, b);
        }

        data[i] = static_cast<unsigned char>(r * 255);
        data[i + 1] = static_cast<unsigned char>(g * 255);
        data[i + 2] = static_cast<unsigned char>(b * 255);
    }
    state = (state == ImageState::HSLA || state == ImageState::HSVA) ? ImageState::RGBA : ImageState::RGB;
}


void Image::save(const std::string &filename, int quality) const
{
    // Determine the file extension
    std::string extension;
    size_t dotPos = filename.find_last_of('.');
    if (dotPos != std::string::npos)
    {
        extension = filename.substr(dotPos + 1);
    }
    else
    {
        throw std::runtime_error("Filename must have an extension.");
    }

    int success = 0;
    if (extension == "png")
    {
        success = stbi_write_png(filename.c_str(), width, height, channels, data, width * channels);
    }
    else if (extension == "jpg" || extension == "jpeg")
    {
        success = stbi_write_jpg(filename.c_str(), width, height, channels, data, quality);
    }
    else
    {
        throw std::runtime_error("Unsupported file format: " + extension);
    }

    if (!success)
    {
        throw std::runtime_error("Failed to save image as " + extension);
    }
}


void Image::setData(unsigned char *data, int width, int height, int channels, ImageState state)
{
    // Free the memory if it is already allocated
    if (this->data) {
        stbi_image_free(this->data);
    }

    this->data = data;

    assert(height == this->height && width == this->width && channels == this->channels);
}

// Getter for image width
int Image::getWidth() const {
    return width;
}

// Getter for image height
int Image::getHeight() const {
    return height;
}

// Getter for image channels
int Image::getChannels() const {
    return channels;
}

// Getter for image data
const unsigned char* Image::getData() const {
    return data;
}

// Convert HSL to RGB
void Image::hslToRgb(float h, float s, float l, float &r, float &g, float &b) {
    auto hueToRgb = [](float p, float q, float t) {
        if (t < 0) t += 1;
        if (t > 1) t -= 1;
        if (t < 1.0f / 6.0f) return p + (q - p) * 6.0f * t;
        if (t < 0.5f) return q;
        if (t < 2.0f / 3.0f) return p + (q - p) * (2.0f / 3.0f - t) * 6.0f;
        return p;
    };
    

    if (s == 0) {
        r = g = b = l;
    } else {
        float q = (l < 0.5) ? (l * (1 + s)) : (l + s - l * s);
        float p = 2 * l - q;
        r = hueToRgb(p, q, h + 1.0 / 3);
        g = hueToRgb(p, q, h);
        b = hueToRgb(p, q, h - 1.0 / 3);
    }
}

// Convert HSV to RGB
void Image::hsvToRgb(float h, float s, float v, float &r, float &g, float &b) {
    int i = static_cast<int>(h * 6);
    float f = h * 6 - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    switch (i % 6) {
        case 0: r = v, g = t, b = p; break;
        case 1: r = q, g = v, b = p; break;
        case 2: r = p, g = v, b = t; break;
        case 3: r = p, g = q, b = v; break;
        case 4: r = t, g = p, b = v; break;
        case 5: r = v, g = p, b = q; break;
    }
}

// Convert HSL to HSV
void Image::hslToHsv(float h, float s, float l, float &outH, float &outS, float &outV) {
    outH = h;
    float v = l + s * std::min(l, 1 - l);
    outV = v;
    outS = (v == 0) ? 0 : 2 * (1 - l / v);
}

// Convert HSV to HSL
void Image::hsvToHsl(float h, float s, float v, float &outH, float &outS, float &outL) {
    outH = h;
    float l = v * (1 - s / 2);
    outL = l;
    outS = (l == 0 || l == 1) ? 0 : (v - l) / std::min(l, 1 - l);
}

unsigned char& Image::operator()(int x, int y, int channel) {
    if (x < 0 || x >= width || y < 0 || y >= height || channel < 0 || channel >= channels) {
        throw std::out_of_range("Pixel coordinates or channel out of bounds");
    }
    
    // Calculate the index in the data array
    // Pixel data is typically stored in row-major order
    // For each pixel, we move by 'channels' bytes
    return data[y * width * channels + x * channels + channel];
}

Image& Image::operator=(const Image& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Free existing memory
    if (data) {
        stbi_image_free(data);
    }

    // Copy dimensions and state
    width = other.width;
    height = other.height;
    channels = other.channels;
    state = other.state;

    // Allocate new memory and copy data
    if (other.data) {
        size_t dataSize = width * height * channels;
        data = new unsigned char[dataSize];
        std::memcpy(data, other.data, dataSize);
    } else {
        data = nullptr;
    }

    return *this;
}
