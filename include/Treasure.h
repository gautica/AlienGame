#ifndef TREASURE_H
#define TREASURE_H

#include <cstdlib>
#include <ctime>
#include "Point.h"

enum Item {Wood = 1, Gold = 3, Diamand = 5, None = 0};

class Treasure {
private:
    char Sym = 'T';
    Point pos;
    Item item;
public:
    Treasure() {}

    char getSym() const;
    Point& getPos();
    void setPos(Point pos);
    Item getItem();
    void setItem(Item item);
    void createItem(int luckyNum);
    friend std::ostream& operator<<(std::ostream &out, Treasure &treasure);
};
#endif
