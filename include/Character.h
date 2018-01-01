#ifndef CHARACTER_H
#define CHARACTER_H

#include "Point.h"

class Character {
protected:
    char Sym;
    unsigned int HP;
    Point pos;

public:
    Character(char Sym, unsigned int hp) : Sym(Sym), HP(hp) {};
    //Character(Point &position) : Sym(' '), pos(position) {}
    Character(char Sym, unsigned int hp, Point &position) : Sym(Sym), HP(hp), pos(position) {}
    virtual ~Character() {}

    char getSym();
    void setSym(char Sym);
    Point& getPos();
    void setPos(Point &position);
    int getHP();
    void setHP(int hp);
};
#endif
