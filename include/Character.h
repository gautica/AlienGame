#ifndef CHARACTER_H
#define CHARACTER_H

#include "Point.h"

class Character {
public:
    char Sym;
    Point pos;
public:
    Character(char Sym) : Sym(Sym) {};
    Character(Point &position) : Sym(' '), pos(position) {}
    Character(char Sym, Point &position) : Sym(Sym), pos(position) {}
    virtual ~Character() {}

    char getSym();
    void setSym(char Sym);
    Point& getPos();
    void setPos(Point &position);
};
#endif
