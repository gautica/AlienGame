#ifndef ALIEN_H
#define ALIEN_H

#include "Point.h"
#include "Character.h"
#include "Player.h"

class Alien : public Character {
public:
    Alien() : Character('A', 1) {}
    Alien(Point pos) : Character('A', 1, pos) {}
    void createDamage(Player& player);
};
#endif
