#pragma once
#include "defines.hpp"
#include <SDL2/SDL.h>
#include <string>

#define MAP_TILE_SIZE 48
#define MAP_WIDTH 33
#define MAP_HEIGHT 19

#define MAP_RENDER_WIDTH 32
#define MAP_RENDER_HEIGHT 18

#define MAP_RENDER_X ((SCREEN_WIDTH - (MAP_RENDER_WIDTH * MAP_TILE_SIZE)) / 2)
#define MAP_RENDER_Y ((SCREEN_HEIGHT - (MAP_RENDER_HEIGHT * MAP_TILE_SIZE)) / 2)

#define TILE_HOLE 0
#define TILE_GROUND 1
#define TILE_WALL 50

typedef struct MapTile {
    int tile;
    int visible;
    int revealed;
} MapTile;

class Map {
    public:
        Map();
        ~Map();
        void init_map();

    private:
        void load_tiles();
        void load_map();

        int m_mapID;
        int m_width;
        int m_height;
        std::string m_level_name;
        MapTile m_map[MAP_WIDTH][MAP_HEIGHT];
        SDL_Point m_camera;
};