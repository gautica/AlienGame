#include <ostream>
#include "Battle.h"

void Battle::fight(Map &map, const Point &pos) {
    // player
    Alien* temp = map.getAlien(pos);
    if ( temp == nullptr) {
        std::cout << "Player hat Alien verfehlt" << '\n';
    } else {
        temp->setSym('X');
    }
    //aliens
    srand(time(0));
    for (unsigned int i = 0; i < map.getCount(); i++) {
        if (map.getAliens()[i].getSym() == 'A') {
            if (map.getAliens()[i].createDamage(map.getPlayer()) == 0) {
                std::cout << "alien" << map.getAliens()[i].getPos() << "hat player verfehlt" << '\n';
            }
            map.getPlayer().setHP(map.getPlayer().getHP() - map.getAliens()[i].createDamage(map.getPlayer()));
        }
    }
}
