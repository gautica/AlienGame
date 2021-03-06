#ifndef MAP_H
#define MAP_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Alien.h"
#include "Player.h"
#include "Character.h"
#include "Point.h"
#include "Wall.h"
#include "Treasure.h"

class Map {
private:
    unsigned int WIDTH;
    unsigned int HEIGHT;
    unsigned int COUNT;
    bool** isOccupied;
    Alien* aliens;
    Player player;
    Tile** map;

    Treasure treasure[2];
public:
    Map(unsigned int width, unsigned int height, unsigned int count)
        :WIDTH(width), HEIGHT(height), COUNT(count)
    {
        map = new Tile*[HEIGHT];
        isOccupied = new bool*[HEIGHT];
        for (unsigned int y = 0; y < HEIGHT; y++) {
            map[y] = new Tile[WIDTH];
            isOccupied[y] = new bool[WIDTH];
            for (unsigned int x = 0; x < WIDTH; x++) {
                if (y == 0 || y == HEIGHT - 1 ||
                    x == 0 || x == WIDTH - 1) {
                    map[y][x] = Wall();
                    isOccupied[y][x] = true;
                } else {
                    isOccupied[y][x] = false;
                }
            }
        }
        // creating aliens
        aliens = new Alien[COUNT];
        // creating treasures
        srand(time(0));
        for (unsigned int i = 0; i < sizeof(treasure) / sizeof(Treasure); i++) {
            int luckyNum = rand() % 3;
            treasure[i].createItem(luckyNum);
        }
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
        // placing treasure
        for (unsigned int i = 0; i < sizeof(treasure) / sizeof(Treasure); i++) {
            generatePos(pos);
            treasure[i].setPos(pos);
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
/**
    void refresh() {
        for (unsigned int i = 0; i < COUNT; i++) {
            map[aliens[i].getPos().getY()][aliens[i].getPos().getX()] = aliens[i].getSym();
        }
    }
    */
};
#endif
