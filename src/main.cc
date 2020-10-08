#include <iostream>
#include <image/image_op.h>
#include <route_planner/PRM.h>

int main(int argc, char **argv) {
    srand(0);
    const auto imagem = image_op::loadImage("../resources/map.png");
    
    imagem->occupacyGrid();

    const auto prm = new PRM();

    prm->generateRoute(*imagem, 90, {20, 340}, {340, 30});
    
    image_op::writeImage("./output.png", *imagem);
    return 0;
}