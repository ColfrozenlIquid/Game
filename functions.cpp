#include <fstream>
#include <iostream>
#include "functions.hpp"
#include <stdlib.h>
#include <cstring>
#include <vector>

//Function reads map data from map.data file
//Row 1: Map name
//Row 2: Map width
//Row 3: Map height
//Row 4: Map data
Map_Data read_map_from_file(std::string filepath){
    Map_Data map_data;
    std::ifstream fstream;
    fstream.open(filepath);
    int line_count = 0;
    if (fstream.is_open()) {
        for (std::string line; std::getline(fstream, line); ){
            if (line_count == 0) {
                map_data.map_name = line;
                line_count++;
                continue;
            }
            if (line_count == 1) {
                map_data.map_width = std::stoi(line);
                line_count++;
                continue;
            }
            if (line_count == 2) {
                map_data.map_height = std::stoi(line);
                line_count++;
                continue;
            }
            if (line_count == 3) {
                int map_size = map_data.map_height * map_data.map_width;
                map_data.map_data_arr = read_map_data(map_size, line);
                line_count++;
                continue;
            }
        }
    }
    else {
        std::cout << "Couldnt load map file" << filepath << '\n';
    }
    
    fstream.close();
    return map_data;
}

std::vector<int> read_map_data(int map_size, std::string line) {
    std::vector<int> map_data;
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        map_data.push_back(std::stoi(token));
        line.erase(0, pos + delimiter.length());
    }
    map_data.push_back(std::stoi(line));
    return map_data;
}