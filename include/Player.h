#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"
#include "Character.h"
#include "Linkedlist.h"
#include "Treasure.h"

class Player : public Character {
private:
    Linkedlist<Treasure> list;
public:
    Player() : Character('P', 5) {}
    Player(Point pos) : Character('P', 5, pos) {}
    void createDamage(Character* chara);
    void walk(int x, int y);
};
#endif
