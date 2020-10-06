#pragma once

#include <utility>
#include <vector>
#include <iostream>
#include <cmath>

#include "point.h" // Point
#include "color.h" // Color

class Image {
public:
    typedef Point Position;
    typedef std::pair<unsigned int, unsigned int> Dimension;
    enum class Occupancy { OCCUPIED, EMPTY };

    Image(const unsigned int width, const unsigned int height)
            : width{width}, height{height} {
        pixels.resize(width * height);
        occupancyGrid.resize(width * height);
    }

    Image(const unsigned int width, const unsigned int height, std::vector<Color>&& pixels)
            : width{width}, height{height}, pixels{std::move(pixels)} {
        pixels.resize(width * height);
        occupancyGrid.resize(width * height);
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

    void occupacyGrid() { createOccupancyGrid(); };

    bool isOccupied(const Position& position) { return occupancyGrid[position.y * width + position.x] == Occupancy::OCCUPIED; }
    bool isEmpty(const Position& position) { return occupancyGrid[position.y * width + position.x] == Occupancy::EMPTY; }

    float straightLine(const Position& p1, const Position& p2);

    void setStartLocation(const Position& start) {
        this->setPixel({start.x, start.y}, Color::RED());
        this->occupy(start);
    }

    void setEndLocation(const Position& end) {
        this->setPixel({end.x, end.y}, Color::GREEN());
        this->occupy(end);
    }

    void printOccupancyGrid() {
        for (size_t y = 0; y < height; y++) {
            for (size_t x = 0; x < width; x++) {
                std::cout << (occupancyGrid[y * width + x] == Occupancy::EMPTY);
            }
            std::cout << std::endl;
        }
        
    }

    Dimension getDimension() const { return std::make_pair(width, height); }
    unsigned int getWidth() const { return width; }
    unsigned int getHeight() const { return height; }

private:
    std::vector<Color> pixels;
    std::vector<Occupancy> occupancyGrid;
    const unsigned int width;
    const unsigned int height;

    void assertInBound(const Position& position) const {
        if (!verifyBounds(position)) {
            throw std::exception();
        }
    }

    void occupy(const Position& position) {
        occupancyGrid[position.y * width + position.x] = Occupancy::OCCUPIED;
    };

    void empty(const Position& position) {
        occupancyGrid[position.y * width + position.x] = Occupancy::EMPTY;
    }

    void createOccupancyGrid() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                const auto color = getPixel({x, y});
                if (color == Color::BLACK() || color == Color::GRAY()) {
                    this->occupy({x, y});
                } else if (color == Color::WHITE()) {
                    this->empty({x, y});
                }
            }
        }
    }

    void drawLine(std::vector<Position> &points);
};