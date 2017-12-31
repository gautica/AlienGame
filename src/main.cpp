#include <iostream>
#include <cstdlib>
#include "Map.h"
#include "Battle.h"

void print_usage();
int main(int args, const char** argv) {
    if (args != 4) {
        print_usage();
    }
    unsigned int width = atoi(argv[1]);
    unsigned int height = atoi(argv[2]);
    unsigned int count = atoi(argv[3]);
    Map map(width, height, count);
    Battle battle;
    while (1) {
        std::cout << map << '\n';
        std::cout << "player's hp is: " << map.getPlayer().getHP() << '\n';
        std::cout << "input x coordinate" << '\n';
        int x;
        std::cin >> x;
        std::cout << "input y coordinate" << '\n';
        int y;
        std::cin >> y;
        battle.fight(map, Point(x, y));
    }
    return 0;
}

void print_usage() {
    std::cout << "usage: [width] [height] [number of aliens]" << '\n';
    exit(EXIT_FAILURE);
}
