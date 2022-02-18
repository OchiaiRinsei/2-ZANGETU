#pragma once
#include "GAME_OBJECT.h"
class COUNT_SCORE :
    public GAME_OBJECT
{
public:
    struct DATA {
        int one, two, three, four;
        int nowTime;
        int lastTime;
    };
};

