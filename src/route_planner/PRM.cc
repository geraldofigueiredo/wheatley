#include "PRM.h"

void PRM::generateRoute(Image &image, const unsigned int numNodes) {
    distanceMatrix.resize(numNodes, std::vector<double>(numNodes, 0));
    
    generateNodeGrid(image, numNodes);
    printNodeGrid();
}

void PRM::generateNodeGrid(Image &image, const unsigned int numNodes) {
    const auto [width, height] = image.getDimension();
    Point::Component x;
    Point::Component y;
    
    for (size_t i = 0; i < numNodes; i++) {
        do {
            x = rand() % width;
            y = rand() % height;
        } while(image.isOccupied({x,y}));

        nodeGrid.push_back(Point({x,y}));
        image.setPixel({x,y}, Color::BLUE());
    }
}

void PRM::connectNodes(Image &image) {
    
}