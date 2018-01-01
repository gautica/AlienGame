#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"
#include "Character.h"

class Player : public Character {
public:
    Player() : Character('P', 5) {}
    Player(Point pos) : Character('P', 5, pos) {}
    void createDamage(Character* chara);
    void walk(int x, int y);
};
#endif
