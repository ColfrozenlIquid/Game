#include "application.hpp"
#include "header.hpp"
#include <iostream>


Application::Application() {
    if (!init()) {
        return;
    }
}

Application::~Application() {
    SDL_FreeSurface(m_window_surface);
    SDL_FreeSurface(background_surface);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Application::update(double delta_time) {
    m_character.update(delta_time);
}

void Application::draw() {
    SDL_Rect player_pos = m_character.get_position(m_character);
    SDL_BlitSurface(background_surface, NULL, m_window_surface, &player_pos);
    //SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
    //SDL_FillRect(m_window_surface, NULL, SDL_MapRGB(m_window_surface->format, 0, 0, 0));
    m_character.draw(m_window_surface);
    m_npc.draw(m_window_surface);
    SDL_UpdateWindowSurface(m_window);
}

void Application::loop() {
    bool keep_window_open = true;
    while (keep_window_open) {
        while (SDL_PollEvent(&m_window_event) > 0) {
            m_character.handle_events(m_window_event);
            switch (m_window_event.type) {
                case SDL_QUIT:
                    keep_window_open = false;
                break;
            }
        }
        update(1.0/60.0);
        draw();
    }
}

bool Application::init() {
    bool initialisation_success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialise. SDL Error: %s\n", SDL_GetError());
        initialisation_success = false;
    }

    if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear textture filtering is not enabled.\n");
    }

    m_window = SDL_CreateWindow(
        "SDL2 Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT,
        0
    );

    if (m_window == NULL) {
        printf("Could not initialise main window. SDL Error: %s\n", SDL_GetError());
        initialisation_success = false;
    }
    
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == NULL) {
        printf("Could not initialise renderer. SDL Error: %s", SDL_GetError());
        initialisation_success = false;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);
    background_surface = SDL_LoadBMP("sprites/background.bmp");

    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0, 0, 0xFF);
    return initialisation_success;
}