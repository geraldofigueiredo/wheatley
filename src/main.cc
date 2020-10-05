#include <iostream>
#include <image/image_op.h>

int main(int argc, char **argv) {
    const auto imagem = image_op::loadImage("../resources/map.png");
    
    imagem->occupacyGrid();
    imagem->setStartLocation({20, 340});
    imagem->setEndLocation({340, 30});
    
    image_op::writeImage("./output.png", *imagem);
    imagem->printOccupancyGrid();
    return 0;
}