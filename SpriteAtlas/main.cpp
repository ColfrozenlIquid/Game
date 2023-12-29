#define SDL_MAIN_HANDLED
#include "atlasGenerator.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <filesystem>
#include <iostream>

static int count_folder_images(std::string);

int main() {
    //SDL_Init(SDL_INIT_VIDEO);
    count_folder_images("C:/Users/dstoklosa/Desktop/C++/Game/sprites");
    return 0;
}

static int count_folder_images(std::string folderpath) {
    for (auto const& dir_entry : std::filesystem::recursive_directory_iterator(folderpath)){
        std::cout << dir_entry << std::endl;
    }
}