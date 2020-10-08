#pragma once

#include <memory>
#include <vector>
#include <limits.h> 
#include <stdio.h> 

#include "../image/image.h"
#include "../image/color.h"
#include "../image/image_op.h"
#include "../algorithm/algorithm.h"

std::vector<int> dijkstra(const std::vector<std::vector<double>> &graph, const int source, const int target);

class PRM {
public:
    PRM(Algorithm *shortestPathAlgo):shortestPathAlgo{shortestPathAlgo}{};
    
    void generateRoute(const Image &image, const Image::Position& start, const Image::Position& end);
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
    }

    void resetNodeGrid(const Image::Position &start, const Image::Position &end) {
        nodeGrid.clear();
        nodeGrid.push_back(start);
        nodeGrid.push_back(end);
    }

    void resetDistanceMatrix(const unsigned int numNodes) {
        distanceMatrix.clear();
        distanceMatrix.resize(numNodes+2, std::vector<double>(numNodes+2, 0));
    }

    void printNodeGrid() {
        for (size_t i = 0; i < nodeGrid.size(); i++){
            nodeGrid[i].print();
        }
    }
private:
    std::vector<Point> nodeGrid;
    std::vector<std::vector<double>> distanceMatrix;
    Algorithm *shortestPathAlgo;

    Image generateNodeGrid(Image image, const unsigned int numNodes);
    Image connectNodes(Image image);
    Image drawRoute(Image image, const std::vector<int> &sequence);
};