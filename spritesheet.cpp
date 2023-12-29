#include <SDL2/SDL.h>
#include <stdio.h>
#include "spritesheet.hpp"

#define SPRITE_SHEET_HEIGHT 128
#define SPRITE_SHEET_WIDTH 384
#define SPRITE_WIDTH 128

Spritesheet::Spritesheet(char const *path, int row, int column) {
    m_spritesheet_image = SDL_LoadBMP(path);

    m_clip.w = SPRITE_WIDTH;
    m_clip.h = SPRITE_SHEET_HEIGHT;
}

Spritesheet::~Spritesheet() {
    SDL_FreeSurface(m_spritesheet_image);
}

void Spritesheet::select_sprite(int x, int y) {
    m_clip.x = x * m_clip.w;
    m_clip.y = y * m_clip.h;
}

void Spritesheet::draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position) {
    SDL_BlitSurface(m_spritesheet_image, &m_clip, window_surface, position);
}