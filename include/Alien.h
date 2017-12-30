#ifndef ALIEN_H
#define ALIEN_H

#include "Point.h"
#include "Character.h"

class Alien : public Character {
public:
    Alien() : Character('A') {}
    Alien(Point pos) : Character('A', pos) {}
};
#endif
