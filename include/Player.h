#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"
#include "Character.h"

class Player : public Character {
private:
    int HP;
public:
    Player() : Character('P'), HP(5) {}
    Player(Point pos) : Character('P', pos), HP(5) {}
    int getHP();
    void setHP(int hp);
};
#endif
