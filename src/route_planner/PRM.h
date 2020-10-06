#pragma once

#include <memory>
#include <vector>

#include "../image/image.h"
#include "../image/color.h"

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

    void printNodeGrid() {
        for (size_t i = 0; i < nodeGrid.size(); i++){
            nodeGrid[i].print();
        }
    }
private:
    std::vector<Point> nodeGrid;
    std::vector<std::vector<double>> distanceMatrix;

    void generateNodeGrid(Image &image, const unsigned int numNodes);
    void connectNodes(Image &image);
};