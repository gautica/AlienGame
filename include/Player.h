#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"
#include "Character.h"

class Player : public Character {
public:
    Player() : Character('P') {}
    Player(Point pos) : Character('P', pos) {}
};
#endif
