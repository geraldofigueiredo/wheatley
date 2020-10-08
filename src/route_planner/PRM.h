#pragma once

#include <memory>
#include <vector>

#include "../image/image.h"
#include "../image/color.h"
#include "../image/image_op.h"

class PRM {
public:
    PRM() = default;
    
    void generateRoute(Image &image, const unsigned int numNodes, const Image::Position& start, const Image::Position& end);
    void printDistanceMatrix() {
        for (size_t i = 0; i < distanceMatrix.size(); i++) {
            for (size_t j = 0; j < distanceMatrix.size(); j++) {
                std::cout << distanceMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void setDistanceBetweenPoints(const int initialP, const int finalP) {
        const auto start = nodeGrid[initialP];
        const auto end = nodeGrid[finalP];

        float distance = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2) * 1.0);
        this->distanceMatrix[initialP][finalP] = distance;
        std::cout << "distance: " << distance << std::endl;
    }

    void printNodeGrid() {
        for (size_t i = 0; i < nodeGrid.size(); i++){
            nodeGrid[i].print();
        }
    }
private:
    std::vector<Point> nodeGrid;
    std::vector<std::vector<double>> distanceMatrix;

    void generateNodeGrid(Image &image, const unsigned int numNodes);
    Image connectNodes(Image image);
};