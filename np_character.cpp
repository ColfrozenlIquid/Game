#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "np_character.hpp"

#define SPRITE_PATH "sprites/mage_sprite.bmp"
#define SPRITE_WIDTH 64
#define SPRITE_HEIGHT 80

NPCharacter::NPCharacter() {
    m_image = SDL_LoadBMP(SPRITE_PATH);

    m_position.x = 960;
    m_position.y = 480;
    m_position.w = SPRITE_WIDTH;
    m_position.h = SPRITE_HEIGHT;
}

void NPCharacter::draw(SDL_Surface *window_surface) {
    SDL_BlitSurface(m_image, nullptr, window_surface, &m_position);
}