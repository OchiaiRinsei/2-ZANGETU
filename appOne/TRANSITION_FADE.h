#pragma once
#include "TRANSITION.h"
#include"libOne.h"
class TRANSITION_FADE :
    public TRANSITION {
public:
    struct DATA {
        COLOR color;
        float time = 0;
    };
private:
    DATA Transition;
public:
    TRANSITION_FADE(class GAME* game);
    void create();
    void inTriggerProc();
    bool inProc();
    void outtriggerProc();
    bool outProc();
};