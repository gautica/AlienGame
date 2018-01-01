#include "Character.h"
char Character::getSym() {
    return Sym;
}

Point& Character::getPos() {
    return pos;
}

void Character::setSym(char Sym) {
    this->Sym = Sym;
}

void Character::setPos(Point &position) {
    this->pos = position;
}

int Character::getHP() {
    return HP;
}

void Character::setHP(int hp) {
    HP = hp;
}
