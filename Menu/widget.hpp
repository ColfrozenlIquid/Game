#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#define MAX_NAME_LENGTH

class Widget {
    public:
        Widget(std::string name);
        ~Widget();

    private:
        std::string m_name;
        std::string m_label;
        int x_pos;
        int y_pos;
        Widget* m_previous_widget;
        Widget* m_next_widget;
};