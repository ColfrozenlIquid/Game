#pragma once
#include <string>
#include <vector>

typedef struct Map_Data {
    std::string map_name;
    int map_width;
    int map_height;
    std::vector<int> map_data_arr;
} Map_Data;

Map_Data read_map_from_file(std::string);
std::vector<int> read_map_data(int, std::string);