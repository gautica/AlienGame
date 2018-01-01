#ifndef PLAYERMAPINTERACTION_H
#define PLAYERMAPINTERACTION_H

#include "Map.h"
#include "Battle.h"

enum class Mode {
    WALK,
    FIGHT
};
class PlayerMapInteraction {
private:
    Mode mode = Mode::WALK;
    Battle battle;
public:
    void start(Map &map);
private:
    void inModeWalk(Map &map);
    void inModeFight(Map &map);
};
#endif
