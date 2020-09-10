#pragma once

#include <utility>
#include <vector>

#include "point.h" // Point
#include "color.h" // Color

class Image {
public:
    typedef Point Position;
    typedef std::pair<unsigned int, unsigned int> Dimension;

    Image(const unsigned int width, const unsigned int height)
            : width{width}, height{height} {
        pixels.resize(width * height);
    }

    Image(const unsigned int width, const unsigned int height, std::vector<Color>&& pixels)
            : width{width}, height{height}, pixels{std::move(pixels)} {
        pixels.resize(width * height);
    }

    bool verifyBounds(const Position& position) const {
        return position.x >= 0 && position.y >= 0 && position.x < width && position.y < height;
    }

    Color getPixel(const Position& position) const {
        assertInBound(position);
        return pixels[position.y * width + position.x];
    }

    void setPixel(const Position& position, const Color& color) {
        assertInBound(position);
        pixels[position.y * width + position.x] = color;
    }

    Dimension getDimension() const { return std::make_pair(width, height); }
    unsigned int getWidth() const { return width; }
    unsigned int getHeight() const { return height; }

private:
    std::vector<Color> pixels;
    const unsigned int width;
    const unsigned int height;

    void assertInBound(const Position& position) const {
        if (!verifyBounds(position)) {
            throw std::exception();
        }
    }
};