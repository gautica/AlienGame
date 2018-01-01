#include <string>
#include "PlayerMapInteraction.h"

void PlayerMapInteraction::start(Map &map) {
    while (!battle.isEnd(map)) {
        std::cout << map << '\n';
        switch (mode) {
            case Mode::WALK:
                inModeWalk(map);
                break;
            case Mode::FIGHT:
                inModeFight(map);
                break;
            default:
                std::cout << "invalid game mode" << '\n';
        }
    }
}

void PlayerMapInteraction::inModeWalk(Map &map) {
    std::cout << "in Mode Walk" << '\n';
    std::cout << "input a/A, d/D, s/S, w/W to walk and # to change mode" << '\n';
    char in;
    std::cin >> in;
    switch (in) {
        case '#':
            mode = Mode::FIGHT;
            return;
        case 'a':
        case 'A':
            if (map.isWalkable(-1, 0)) {
                map.setOccupition(map.getPlayer().getPos().getX(), map.getPlayer().getPos().getY(), false);
                map.getPlayer().walk(-1, 0);
                map.setOccupition(map.getPlayer().getPos().getX(), map.getPlayer().getPos().getY(), true);
            }
            break;
        case 'd':
        case 'D':
            if (map.isWalkable(1, 0)) {
                map.setOccupition(map.getPlayer().getPos().getX(), map.getPlayer().getPos().getY(), false);
                map.getPlayer().walk(1, 0);
                map.setOccupition(map.getPlayer().getPos().getX(), map.getPlayer().getPos().getY(), true);
            }
            break;
        case 's':
        case 'S':
            if (map.isWalkable(0, 1)) {
                map.setOccupition(map.getPlayer().getPos().getX(), map.getPlayer().getPos().getY(), false);
                map.getPlayer().walk(0, 1);
                map.setOccupition(map.getPlayer().getPos().getX(), map.getPlayer().getPos().getY(), true);
            }
            break;
        case 'w':
        case 'W':
            if (map.isWalkable(0, -1)) {
                map.setOccupition(map.getPlayer().getPos().getX(), map.getPlayer().getPos().getY(), false);
                map.getPlayer().walk(0, -1);
                map.setOccupition(map.getPlayer().getPos().getX(), map.getPlayer().getPos().getY(), true);
            }
            break;
        default:
            std::cout << "invalid input: input a/A, d/D, s/S, w/W to walk and # to change mode" << '\n';
    }
}

void PlayerMapInteraction::inModeFight(Map &map) {
    std::cout << "in Mode Fight" << '\n';
    std::cout << "player's hp is: " << map.getPlayer().getHP() << '\n';
    std::cout << "input x coordinate" << '\n';
    std::string x;
    std::cin >> x;
    if (x == "#") {
        mode = Mode::WALK;
        return;
    }
    //std::cout << x;
    std::cout << "input y coordinate" << '\n';
    std::string y;
    std::cin >> y;
    if (y == "#") {
        mode = Mode::WALK;
        return;
    }
    battle.fight(map, Point(stoi(x), stoi(y)));
}
