#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "character.hpp"
#include "camera.hpp"

#define SPRITE_SHEET_PATH "sprites/ghost-Sheet.bmp"
#define CAMERA_PATH "sprites/camera_sprite.bmp"
#define SPRITE_WIDTH 128
#define SPRITE_HEIGHT 128
#define SPRITESHEET_WIDTH 5 //(0..5)

#define SPRITESHEET_WALK 0

Character::Character(): m_spritesheet(SPRITE_SHEET_PATH, 0, 0) {
    m_image = SDL_LoadBMP(SPRITE_SHEET_PATH);
    cam_image = SDL_LoadBMP(CAMERA_PATH);

    m_position.x = 0;
    m_position.y = 0;
    m_position.w = SPRITE_WIDTH;
    m_position.h = SPRITE_HEIGHT;
    m_direction = Direction::NONE;
    m_x = 0.0;
    m_y = 0.0;

    m_spritesheet.select_sprite(0, 0);
    m_spritesheet_column = 0;
    cam_position = &m_position;
}

void Character::handle_events(SDL_Event const &event) {
    switch(event.type) {
        case SDL_KEYDOWN:
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1)
                m_direction = Direction::UP;
            else if(keys[SDL_SCANCODE_S] == 1)
                m_direction = Direction::DOWN;
            else if(keys[SDL_SCANCODE_A] == 1)
                m_direction = Direction::LEFT;
            else if(keys[SDL_SCANCODE_D] == 1)
                m_direction = Direction::RIGHT;
            else if(keys[SDL_SCANCODE_SPACE] == 1)
                m_direction = Direction::NONE;
            break;
    }
}

void Character::update(double delta_time) {
    switch (m_direction) {
        case Direction::NONE:
            m_x += 0.0;
            m_y += 0.0;
            m_spritesheet.select_sprite(m_spritesheet_column, SPRITESHEET_WALK);
            break;
        case Direction::UP:
            m_y = m_y - (5.0 * delta_time);
            m_spritesheet.select_sprite(m_spritesheet_column, SPRITESHEET_WALK);
            break;
        case Direction::DOWN:
            m_y = m_y + (5.0 * delta_time);
            m_spritesheet.select_sprite(m_spritesheet_column, SPRITESHEET_WALK);
            break;
        case Direction::RIGHT:
            m_x = m_x + (5.0 * delta_time);
            m_spritesheet.select_sprite(m_spritesheet_column, SPRITESHEET_WALK);
            break;
        case Direction::LEFT:
            m_x = m_x - (5.0 * delta_time);
            m_spritesheet.select_sprite(m_spritesheet_column, SPRITESHEET_WALK);
            break;
        default:
            std::cout << "No direction set" << std::endl;
    }
    m_position.x = m_x;
    m_position.y = m_y;

    m_spritesheet_column ++;

    if (m_spritesheet_column > SPRITESHEET_WIDTH) {
        m_spritesheet_column = 1;
    }
}

void Character::draw(SDL_Surface *window_surface) {
    m_spritesheet.draw_selected_sprite(window_surface, &m_position);
    //SDL_Delay(100);
    //SDL_BlitSurface(m_image, nullptr, window_surface, &m_position);
    //SDL_BlitSurface(cam_image, nullptr, window_surface, cam_position);
}

std::string Character::get_direction() {
    switch (m_direction) {
        case Direction::UP:
            return "Direction is UP";
            break;
        case Direction::DOWN:
            return "Direction is DOWN";
            break;
        case Direction::RIGHT:
            return "Direction is RIGHT";
            break;
        case Direction::LEFT:
            return "Direction is LEFT";
            break;
        default:
            return "Direction is NONE";
    }
}

void Character::set_direction(Direction direction) {
    this->m_direction = direction;
}

SDL_Rect Character::get_position(Character &character) {
    return character.m_position;
}