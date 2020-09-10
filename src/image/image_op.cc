#include "image_op.h"

#include "lodepng/lodepng.h"
#include <iostream>

namespace image_op {

std::unique_ptr<Image> loadImage(const char *filename) {
    unsigned int width, height;
    std::vector<unsigned char> buffer;

    const auto error = lodepng::decode(buffer, width, height, filename);
    if (error) {
        throw std::runtime_error(lodepng_error_text(error));
    }

    for (auto y = 0; y < height; y++) {
        for (auto x = 0; x < width; x++) {
            const auto index = 4 * (y * width + x);
            const auto r = buffer[index + 0];
            const auto g = buffer[index + 1];
            const auto b = buffer[index + 2];

            std::cout << "position: {" 
            << x << "," << y << "}" 
            << " color: {" <<
            r << "," << g << "," << b
            << "\n";
        }
    }
    return nullptr;
}

}