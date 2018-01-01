#ifndef BATTLE_H
#define BATTLE_H

#include "Map.h"

class Battle {

public:
    Battle() {

    }
    void fight(Map &map, const Point &pos);
    bool isEnd(Map &map);
};
#endif
