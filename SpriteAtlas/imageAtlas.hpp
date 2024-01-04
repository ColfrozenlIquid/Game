#include <SDL2/SDL.h>
#include <vector>

#define ATLAS_WIDTH 1000
#define ATLAS_HEIGHT 2000
#define PADDING 2

typedef struct Node {
    int x_pos;
    int y_pos;
    int width;
    int height;
    int used;
    Node* child_node[2];
} Node;

class ImageAtlas {
    public:
        ImageAtlas();
        ~ImageAtlas();
        void add_image(SDL_Surface* sdl_surface);
        void set_image_count(int image_count);
        int get_image_count();
        std::vector<SDL_Surface*>& get_image_surfaces();

        static Node* find_node(Node* root, int width, int height);
        static void split_node(Node* node, int width, int height);
        static void blit_rotated(SDL_Surface* source, SDL_Surface* destination, int dest_x, int dest_y);

    private:
        Node m_node_root;
        int m_image_count;
        std::vector<SDL_Surface*> m_image_surface_vec;
};