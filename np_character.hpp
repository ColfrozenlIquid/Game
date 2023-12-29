#pragma once
#include <SDL2/SDL.h>

class NPCharacter {
    public:

        NPCharacter();
        ~NPCharacter() = default;

        void draw(SDL_Surface *window_surface);

    private:
        SDL_Surface *m_image;
        SDL_Rect m_position;
};