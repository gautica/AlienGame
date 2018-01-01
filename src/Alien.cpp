#include <stdlib.h>
#include "Alien.h"

void Alien::createDamage(Player &player) {
    if (HP <= 0) {
        return;
    }
    unsigned int distance = abs(pos.getX() - player.getPos().getX()) + abs(pos.getY() - player.getPos().getY());
    int random = rand() % 10 * distance;
    if (random > 10) {
        player.setHP(player.getHP() - 1);
    } else {
        std::cout << "alien" << getPos() << "hat player verfehlt" << '\n';
    }
}
