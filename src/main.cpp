#include <iostream>
#include <cstdlib>
#include "Map.h"

void print_usage();
int main(int args, const char** argv) {
    if (args != 4) {
        print_usage();
    }
    unsigned int width = atoi(argv[1]);
    unsigned int height = atoi(argv[2]);
    unsigned int count = atoi(argv[3]);
    Map map(width, height, count);

    map.printMap();

    return 0;
}

void print_usage() {
    std::cout << "usage: [width] [height] [number of aliens]" << '\n';
    exit(EXIT_FAILURE);
}
