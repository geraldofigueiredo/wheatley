#include <iostream>

#include "image/image_op.h"
#include "route_planner/PRM.h"
#include "algorithm/dijkstras.h"

int main(int argc, char **argv) {
    // srand(7);
    srand (time(NULL));
    const auto imagem = image_op::loadImage("../resources/map.png");
    
    imagem->createOccupancyGrid();

    Dijkstras shortestPathAlgo;
    const auto prm = new PRM(&shortestPathAlgo);
    prm->generateRoute(*imagem, {20, 340}, {340, 30});
    return 0;
}