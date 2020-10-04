#include <iostream>
#include <image/image_op.h>

int main(int argc, char **argv) {
    const auto imagem = image_op::loadImage("../resources/map.png");
    imagem->occupacyGrid();
    imagem->printOccupancyGrid();
    return 0;
}