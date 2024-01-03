#define SDL_MAIN_HANDLED
#include "atlasGenerator.hpp"
#include "imageAtlas.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <filesystem>
#include <iostream>
#include <algorithm>

#define SPRITEPATH "..\\sprites"

void count_folder_images(std::string, ImageAtlas&);
std::string get_path(const std::filesystem::path&);
bool sort_Images(const SDL_Surface*, const SDL_Surface*);

int main() {

    bool initialisation_success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialise. SDL Error: %s\n", SDL_GetError());
        initialisation_success = false;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        printf("SDL_IMG could not initialise PNG. SDL_IMAGE Error: %s\n", SDL_GetError());
        initialisation_success = false;
    }

    std::string path = SPRITEPATH;
    ImageAtlas image_atlas;
    count_folder_images(path, image_atlas);
    std::sort(image_atlas.get_image_surfaces().begin(), image_atlas.get_image_surfaces().end(), sort_Images);

    for(auto image_surface : image_atlas.get_image_surfaces()) {
        std::cout << "Image width: " << image_surface->w << " image height: " << image_surface->h << std::endl;
    }

    IMG_Quit();
    SDL_Quit();

    return 0;
}

bool sort_Images(const SDL_Surface* sdl_surface_a, const SDL_Surface* sdl_surface_b) {
    if (!sdl_surface_a || !sdl_surface_b) {
        return false;
    }
    return (sdl_surface_a->h > sdl_surface_b->h);
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
        else {
            std::cout << "Failed to load image at: " << get_path(dir_entry.path()) << std::endl;
        }
    }
    image_atlas.set_image_count(count);
}

std::string get_path(const std::filesystem::path& path) {
    return path.string();
}