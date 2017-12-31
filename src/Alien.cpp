#include <stdlib.h>
#include "Alien.h"

int Alien::createDamage(Player &player) {
    unsigned int distance = abs(pos.getX() - player.pos.getX()) + abs(pos.getY() - player.pos.getY());
    srand(time(0));
    int random = rand() % 10 * distance;
    if (random > 10) {
        return 1;
    } else {
        return 0;
    }
}
