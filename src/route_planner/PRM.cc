#include "PRM.h"

void PRM::generateRoute(Image &image, const unsigned int numNodes, const Image::Position& start, const Image::Position& end) {
    distanceMatrix.resize(numNodes+2, std::vector<double>(numNodes+2, 0));
    image.setStartLocation(start);
    image.setEndLocation(end);
    
    nodeGrid.push_back(start);
    nodeGrid.push_back(end);
    
    generateNodeGrid(image, numNodes);
    image_op::writeImage("./1-nodes.png", image);

    image_op::writeImage("./2-nodesConnection.png", connectNodes(image));
    
    printNodeGrid();
    printDistanceMatrix();

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

        nodeGrid.push_back({x,y});
        image.setPixel({x,y}, Color::BLUE());
    }
}

Image PRM::connectNodes(Image image) {
    for (size_t i = 0; i < nodeGrid.size(); i++) {
        for (size_t j = 0; j < nodeGrid.size(); j++) {
            if (i == j) {
                this->distanceMatrix[i][j] = 0;
                continue;
            }
            std::vector<Image::Position> points = image.getPathBetweenPoints(nodeGrid[i], nodeGrid[j]);
            image.drawLine(points);

            if (points.size() > 0) {
                setDistanceBetweenPoints(i, j);
            }
        }
    }
    return image;
}