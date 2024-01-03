#include "imageAtlas.hpp"

ImageAtlas::ImageAtlas() {}

ImageAtlas::~ImageAtlas() {}

void ImageAtlas::add_image(SDL_Surface* sdl_surface) {
    this->m_image_surface_vec.push_back(sdl_surface);
}

void ImageAtlas::set_image_count(int image_count) {
    this->m_image_count = image_count;
}

int ImageAtlas::get_image_count() {
    return this->m_image_count;
}

std::vector<SDL_Surface*>& ImageAtlas::get_image_surfaces() {
    return this->m_image_surface_vec;
}