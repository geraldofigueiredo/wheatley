#pragma once

class Point {
public:
    typedef int Component;

    Component x;
    Component y;

    Point(Component x, Component y): x{x}, y{y} {}
    Point(): Point{0,0} {}
    Point(const Point &other): Point{other.x, other.y} {}

    void operator=(const Point &other) {
        x = other.x;
        y = other.y;
    }

    void print() {
        std::cout << "{" << x << "," << y << "} " << std::endl;
    }
};