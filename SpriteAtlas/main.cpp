#define SDL_MAIN_HANDLED
#include "atlasGenerator.hpp"
#include "imageAtlas.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <filesystem>
#include <iostream>
#include <algorithm>

void count_folder_images(std::string, ImageAtlas& image_atlas);
std::string get_path(const std::filesystem::path&);
bool sort_Images(SDL_Surface*, SDL_Surface*);

int main() {
    std::string path = "C:/Users/Daniel/Desktop/C++/Game/sprites";
    ImageAtlas image_atlas;
    count_folder_images(path, image_atlas);
    std::cout << "Contains " << image_atlas.get_image_surfaces().size() << " elements" << std::endl;
    std::cout << "Found " << image_atlas.get_image_count() << " images" << std::endl;

    std::sort(image_atlas.get_image_surfaces().begin(), image_atlas.get_image_surfaces().end(), sort_Images);

    for(auto image_surface : image_atlas.get_image_surfaces()) {
        std::cout << "Image width: " << image_surface->w << " image height: " << image_surface->h << std::endl;
    }
    return 0;
}

bool sort_Images(SDL_Surface* sdl_surface_a, SDL_Surface* sdl_surface_b) {

    std::cout << "Surface A: " << sdl_surface_a->h << std::endl;
    std::cout << "Surface B: " << sdl_surface_b->h << std::endl;
    if (sdl_surface_a->h > sdl_surface_b->h) {
        return 1;
    }
    return 0;
}

void count_folder_images(std::string folderpath, ImageAtlas& image_atlas) {
    int count = 0;
    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(folderpath)){
        SDL_Surface* image = IMG_Load(get_path(dir_entry.path()).c_str());
        if (image) {
            std::cout << "Found image at: " << get_path(dir_entry.path()) << std::endl;
            image_atlas.add_image(image);
            count++;
        }
    }
    image_atlas.set_image_count(count);
}

std::string get_path(const std::filesystem::path& path) {
    return path.string();
}