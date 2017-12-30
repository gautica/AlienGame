#include <iostream>
#include "Map.h"

unsigned int Map::getWidth() {
    return WIDTH;
}

unsigned int Map::getHeight() {
    return HEIGHT;
}

unsigned int Map::getCount() {
    return COUNT;
}

void Map::printMap() {
    for (unsigned int y = 0; y < HEIGHT; y++) {
        for (unsigned int x = 0; x < WIDTH; x++) {
            std::cout << map[y][x];
        }
        std::cout << '\n';
    }
}
