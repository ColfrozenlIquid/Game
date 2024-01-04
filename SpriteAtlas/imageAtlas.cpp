#include "imageAtlas.hpp"

ImageAtlas::ImageAtlas() {
    this->m_node_root.x_pos = 0;
    this->m_node_root.y_pos = 0;
    this->m_node_root.width = ATLAS_WIDTH;
    this->m_node_root.height = ATLAS_HEIGHT;
    this->m_node_root.used = 0;

    SDL_Surface* atlas = SDL_CreateRGBSurface(0, ATLAS_WIDTH, ATLAS_HEIGHT, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
}

ImageAtlas::~ImageAtlas() {}

void ImageAtlas::add_image(SDL_Surface* sdl_surface) {
    this->m_image_surface_vec.push_back(sdl_surface);
}

void ImageAtlas::set_image_count(int image_count) {
    this->m_image_count = image_count;
}

int ImageAtlas::get_image_count() {
    return this->m_image_count;
}

std::vector<SDL_Surface*>& ImageAtlas::get_image_surfaces() {
    return this->m_image_surface_vec;
}

Node* ImageAtlas::find_node(Node* root, int width, int height) {
    if (root->used) {
        Node* node = NULL;
        if ((node = find_node(root->child_node[0], width, height)) != NULL || 
            (node = find_node(root->child_node[1], width, height)) != NULL) {
                return node;
        }
    }
    else if (width <= root->width && height <= root->height) {
        split_node(root, width, height);
        return root;
    }
    return NULL;
}

void ImageAtlas::split_node(Node* node, int width, int height) {
    node->used = 1;
    
    node->child_node[0]->x_pos = node->x_pos + node->width + PADDING;
    node->child_node[0]->y_pos = node->y_pos;
    node->child_node[0]->width = node->width - width - PADDING;
    node->child_node[0]->height = height;

    node->child_node[1]->x_pos = node->x_pos;
    node->child_node[1]->y_pos = node->y_pos + height + PADDING;
    node->child_node[1]->width = node->width;
    node->child_node[1]->height = node->height - height - PADDING;
}

void ImageAtlas::blit_rotated(SDL_Surface* source, SDL_Surface* destination, int dest_x, int dest_y) {
    int dx, dy;
    dy = 0;
    for (int x = 0; x < source->w; x++) {
        dx = source->h - 1;
        for (int y = 0; y < source->h; y++) {
            int p = get_pixel(source, x, y);
            put_pixel(dest_x + dx, dest_y + dy, p, destination);
            dx--;
        }
        dy++;
    }
}