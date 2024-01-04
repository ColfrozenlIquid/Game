#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "widget.hpp"

int main() {

    Widget widgethead("Head");
    Widget widgettail = widgethead&;

    return 0;
}