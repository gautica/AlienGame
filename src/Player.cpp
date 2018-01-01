#include "Player.h"

void Player::createDamage(Character* chara) {
    chara->setHP(chara->getHP() - 1);
    if (chara->getHP() == 0) {
        chara->setSym('X');
    }
}

void Player::walk(int x, int y) {
    pos.setX(pos.getX() + x);
    pos.setY(pos.getY() + y);
}
