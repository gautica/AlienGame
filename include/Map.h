#ifndef MAP_H
#define MAP_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Alien.h"
#include "Player.h"
#include "Character.h"
#include "Point.h"

class Map {
private:
    unsigned int WIDTH;
    unsigned int HEIGHT;
    unsigned int COUNT;
    bool** isOccupied;
    Alien* aliens;
    Player player;
    char** map;
public:
    Map(unsigned int width, unsigned int height, unsigned int count)
        :WIDTH(width), HEIGHT(height), COUNT(count)
    {
        map = new char*[HEIGHT];
        isOccupied = new bool*[HEIGHT];
        for (unsigned int y = 0; y < HEIGHT; y++) {
            map[y] = new char[WIDTH];
            isOccupied[y] = new bool[WIDTH];
            for (unsigned int x = 0; x < WIDTH; x++) {
                if (y == 0 || y == HEIGHT - 1 ||
                    x == 0 || x == WIDTH - 1) {
                    map[y][x] = '#';
                    isOccupied[y][x] = true;
                } else {
                    map[y][x] = ' ';
                    isOccupied[y][x] = false;
                }
            }
        }
        // creating aliens
        aliens = new Alien[COUNT];
        //std::cout << player.getSym() << std::endl;
        placeCharacter();
    }

    ~Map() {
        for (unsigned int y = 0; y < HEIGHT; y++) {
            delete[] map[y];
        }
        delete[] map;
        delete[] aliens;        // delete array
    }

    unsigned int getWidth();
    unsigned int getHeight();
    unsigned int getCount();
    bool getOccupition(int x, int y);
    void setOccupition(int x, int y, bool Occupition);
    bool isWalkable(int x, int y);
    Alien* getAlien(const Point &pos);
    Alien* getAliens();
    Player& getPlayer();
    friend std::ostream& operator<<(std::ostream &out, Map &map);
    //void printMap();

private:
    void placeCharacter() {
        Point pos;
        generatePos(pos);
        player.setPos(pos);
        for (unsigned int i = 0; i < COUNT; i++) {
            generatePos(pos);
            aliens[i].setPos(pos);
        }
    }

    void generatePos(Point &pos) {
        srand(time(0));
        unsigned int x = rand() % (WIDTH - 2) + 1;
        unsigned int y = rand() % (HEIGHT - 2) + 1;
        while (isOccupied[y][x]) {
            x = rand() % (WIDTH - 2) + 1;
            y = rand() % (HEIGHT - 2) + 1;
        }
        pos.setX(x);
        pos.setY(y);
        isOccupied[y][x] = true;
    }

    void refresh() {
        for (unsigned int i = 0; i < COUNT; i++) {
            map[aliens[i].getPos().getY()][aliens[i].getPos().getX()] = aliens[i].getSym();
        }
    }
};
#endif
