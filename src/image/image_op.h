#pragma once

#include <memory>

#include "image.h"

namespace image_op {

std::unique_ptr<Image> loadImage(const char *filename);
void writeImage(const char *filename, const Image &image);

} // namespace images
