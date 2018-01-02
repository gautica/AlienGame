#include "Treasure.h"

char Treasure::getSym() const {
    return Sym;
}

Point& Treasure::getPos() {
    return pos;
}

void Treasure::setPos(Point pos) {
    this->pos = pos;
}

Item Treasure::getItem() {
    return item;
}

void Treasure::setItem(Item item) {
    this->item = item;
}

void Treasure::createItem(int luckyNum) {
    switch (luckyNum) {
        case 0:
            item = Wood;
            break;
        case 1:
            item = Gold;
            break;
        case 2:
            item = Diamand;
            break;
        default:
            item = None;
            break;
    }
}

std::ostream& operator<<(std::ostream &out, Treasure &treasure) {
    out << treasure.item;
    return out;
}
