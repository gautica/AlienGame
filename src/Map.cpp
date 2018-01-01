#include <iostream>
#include "Map.h"

Alien* Map::getAlien(const Point &pos) {
    if (map[pos.getY()][pos.getX()] != 'A') {
        return nullptr;
    }
    for (unsigned int i = 0; i < COUNT; i++) {
        if (aliens[i].getPos() == pos) {
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

bool Map::getOccupition(int x, int y) {
    return isOccupied[y][x];
}

void Map::setOccupition(int x, int y, bool Occupition) {
    isOccupied[y][x] = Occupition;
}

bool Map::isWalkable(int x, int y) {
    return !getOccupition(player.getPos().getX() + x, player.getPos().getY() + y);
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
            if (Point(x, y) == map.getPlayer().getPos()) {
                out << 'P';
            } else {
                out << map.map[y][x];
            }
        }
        out << '\n';
    }
    return out;
}
