#ifndef TREASURE_H
#define TREASURE_H

#include "Tile.h"

enum Item {Wood = 1, Gold = 3, Diamand = 5};

class Treasure : public Tile {
private:
    Item item;
public:
    Treasure(int luckyNum) : Tile('T') {
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
                break;
        }
    }

    Item getItem();
};
#endif
