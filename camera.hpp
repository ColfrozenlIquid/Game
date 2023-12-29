#pragma once
#include <SDL2/SDL.h>

class Camera {
    public:
        Camera();
        ~Camera() = default;
        SDL_Rect get_cam_position();

        //void set_cam_position(int &x, int &y);

    protected:
        SDL_Rect cam_position;
};