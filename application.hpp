#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "character.hpp"
#include "np_character.hpp"

class Application {
    public:
        Application();
        ~Application();

        void update(double delta_time);
        void draw();
        void loop();
        bool init();

    private:
        Character m_character;
        NPCharacter m_npc;

        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Surface *m_window_surface;
        SDL_Surface *background_surface;
        SDL_Event m_window_event;
};