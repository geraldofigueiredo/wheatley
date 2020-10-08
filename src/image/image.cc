#include "image.h"

void Image::drawLine(const std::vector<Position> &points) {
    for (size_t i = 0; i < points.size(); i++) {
        this->setPixel({points[i].x, points[i].y}, Color::LIGHTRED());
    }
}

std::vector<Image::Position> Image::getPathBetweenPoints(const Position& p1, const Position& p2) {
    auto start = p1;
    auto end = p2;
    // DDA algorithm
    if (start.x > end.x) {
        int tempX, tempY = 0;
        tempX = start.x;
        tempY = start.y;

        start.x = end.x;
        start.y = end.y;

        end.x = tempX;
        end.y = tempY;
    }

    int step = abs(end.x - start.x);
    int stepY = abs(end.y - start.y);
    if (stepY > step) {
        step = stepY;
    }

    float x, y, xInc, yInc = 0;
    xInc = (float) (end.x - start.x)/step;
    yInc = (float) (end.y - start.y)/step;
    x = start.x;
    y = start.y;

    std::vector<Position> points;
    while (x < end.x) {
        x += xInc;
        y += yInc;
        points.push_back({round(x), round(y)});

        if (this->isOccupied({round(x), round(y)})) {
            points.clear();
            break;
        }
    }

    // if (freeWay) {
    //     this->drawLine(points);
    //     float distance = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2) * 1.0);
    //     std::cout << "distance: " << distance << std::endl;
    //     return distance;
    // }
    return points;
}