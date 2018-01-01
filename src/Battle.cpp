#include <ostream>
#include "Battle.h"

void Battle::fight(Map &map, const Point &pos) {
    // player
    Alien* temp = map.getAlien(pos);
    if ( temp == nullptr) {
        std::cout << "Player hat Alien verfehlt" << '\n';
    } else {
        map.getPlayer().createDamage(temp);
    }
    //aliens
    srand(time(0));
    for (unsigned int i = 0; i < map.getCount(); i++) {
        map.getAliens()[i].createDamage(map.getPlayer());
    }
}

bool Battle::isEnd(Map &map) {
    if (map.getPlayer().getHP() == 0) {
        std::cout << "Player won!!!" << '\n';
        return true;
    }
    for (unsigned int i = 0; i < map.getCount(); i++) {
        if (map.getAliens()[i].getHP() > 0) {
            return false;
        }
    }
    std::cout << "Alien won!!!" << '\n';
    return true; 
}
