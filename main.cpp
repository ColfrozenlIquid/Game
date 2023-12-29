#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include "application.hpp"
#include "character.hpp"
#include "map.hpp"

int main() {
    Application app;
    Map map;
    //map.init_map();
    std::cout << "Running" << std::endl;
    app.loop();
    return 0;
}
