// #include "header.hpp"
#include "camera.hpp"
#include "character.hpp"
#include "defines.hpp"

Camera::Camera() {
    cam_position.h = WINDOW_HEIGHT;
    cam_position.w = WINDOW_WIDTH;
    cam_position.x = LEVEL_WIDTH/2 - WINDOW_WIDTH;
    cam_position.y = LEVEL_HEIGHT/2 - WINDOW_HEIGHT;
}

SDL_Rect Camera::get_cam_position() {
    return this->cam_position;
}