#pragma once

class Color {
public:
    typedef unsigned char Component;

    Component r, g, b;

    inline void operator=(const Color &other) {
        r = other.r;
        g = other.g;
        b = other.b;
    }

    inline bool operator==(const Color &other) const {
        return r == other.r && g == other.g && b == other.b;
    }

    static constexpr Color BLACK() { return {0, 0, 0}; }
    static constexpr Color WHITE() { return {255, 255, 255}; }
    static constexpr Color GRAY() { return {54, 54, 54}; }
    static constexpr Color RED() { return {255, 0, 0}; }
    static constexpr Color GREEN() { return {0, 255, 0}; }
    static constexpr Color BLUE() { return {0, 0, 255}; }
};
