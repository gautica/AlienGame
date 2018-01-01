#include <iostream>
#include "Map.h"

Alien* Map::getAlien(const Point &pos) {
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
    //map.refresh();
    char** str = new char*[map.HEIGHT];
    for (unsigned int y = 0; y < map.HEIGHT; y++) {
        str[y] = new char[map.WIDTH];
        for (unsigned int x = 0; x < map.WIDTH; x++) {
            str[y][x] = map.map[y][x].getSym();
        }
    }
    str[map.player.getPos().getY()][map.player.getPos().getX()] = map.player.getSym();
    for (unsigned int i = 0; i < map.COUNT; i++) {
        str[map.aliens[i].getPos().getY()][map.aliens[i].getPos().getX()] = map.aliens[i].getSym();
    }

    for (unsigned int y = 0; y < map.HEIGHT; y++) {
        for (unsigned int x = 0; x < map.WIDTH; x++) {
            out << str[y][x];
        }
        out << '\n';
    }
    for (unsigned int y = 0; y < map.HEIGHT; y++) {
        delete[] str[y];
    }
    delete[] str;
    return out;
}
