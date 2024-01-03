#include <SDL2/SDL.h>
#include <vector>

typedef struct Node {
    
} Node;

class ImageAtlas {
    public:
        ImageAtlas();
        ~ImageAtlas();
        void add_image(SDL_Surface* sdl_surface);
        void set_image_count(int image_count);
        int get_image_count();
        std::vector<SDL_Surface*>& get_image_surfaces();

    private:
        int m_pos_x;
        int m_pos_y;
        int m_atlas_height;
        int m_atlas_width;
        int m_used;
        int m_image_count;
        std::vector<SDL_Surface*> m_image_surface_vec;
};