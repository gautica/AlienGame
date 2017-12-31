#include <iostream>
#include "Map.h"

Alien* Map::getAlien(const Point &pos) {
    if (map[pos.getY()][pos.getX()] != 'A') {
        return nullptr;
    }
    for (unsigned int i = 0; i < COUNT; i++) {
        if (aliens[i].pos == pos) {
            return &aliens[i];
        }
    }
    return nullptr;
}

unsigned int Map::getWidth() {
    return WIDTH;
}

unsigned int Map::getHeight() {
    return HEIGHT;
}

unsigned int Map::getCount() {
    return COUNT;
}

Alien* Map::getAliens() {
    return aliens;
}

Player& Map::getPlayer() {
    return player;
}
std::ostream& operator<<(std::ostream& out, Map &map) {
    map.refresh();
    for (unsigned int y = 0; y < map.HEIGHT; y++) {
        for (unsigned int x = 0; x < map.WIDTH; x++) {
            out << map.map[y][x];
        }
        out << '\n';
    }
    return out;
}
