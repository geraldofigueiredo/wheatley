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
};
