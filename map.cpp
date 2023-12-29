#include <iostream>
#include "map.hpp"
#include "functions.hpp"

Map::Map() {
    init_map();
}

Map::~Map() {}

void Map::init_map() {
    load_tiles();
    load_map();
}

void Map::load_map() {
    int x, y;
    Map_Data map_data = read_map_from_file("map.data");
    std::cout << "Map data read successfully" << std::endl;
    this->m_level_name = map_data.map_name;
    this->m_width = map_data.map_width;
    this->m_height = map_data.map_height;

    std::cout << "Map name: " << m_level_name << '\n';
    std::cout << "Map width: " << m_width << '\n';
    std::cout << "Map height: " << m_height << '\n';

    // std::cout << "Map data: " << '\n';

    // for (int i = 0; i < m_width * m_height; i++) {
    //     std::cout << map_data.map_data_arr[i] << '\n';
    // }
}

void Map::load_tiles(){
    int i;
}

