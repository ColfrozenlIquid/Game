#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "camera.hpp"
#include "spritesheet.hpp"

class Character {
    public:
        enum class Direction {
            NONE,
            UP,
            DOWN,
            LEFT,
            RIGHT,
        };

        Character();
        ~Character() = default;

        void update(double delta_time);
        void draw(SDL_Surface *window_surface);
        void handle_events(SDL_Event const &event);
        void set_direction(Direction direction);
        
        SDL_Rect get_position(Character &character);

        std::string get_direction();

    private:
        Spritesheet m_spritesheet;
        int m_spritesheet_column;
        Camera camera;
        SDL_Surface *m_image;
        SDL_Surface *cam_image;
        SDL_Rect m_position;
        SDL_Rect *cam_position;
        double m_x;
        double m_y;
        Direction m_direction;
};