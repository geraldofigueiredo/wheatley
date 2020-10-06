#include <iostream>
#include <image/image_op.h>
#include <route_planner/PRM.h>

int main(int argc, char **argv) {
    srand(0);
    const auto imagem = image_op::loadImage("../resources/map.png");
    
    imagem->occupacyGrid();
    imagem->setStartLocation({20, 340});
    imagem->setEndLocation({340, 30});

    const auto prm = new PRM();

    prm->generateRoute(*imagem, 100);
    
    image_op::writeImage("./output.png", *imagem);
    // imagem->printOccupancyGrid();
    return 0;
}