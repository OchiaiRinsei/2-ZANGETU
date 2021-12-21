#pragma once
#include "CHARA.h"
class BOSS1 :
    public CHARA
{
public:
    //オリジナルデータ
    struct DATA {
        float theta;
        float rollDistance;
        float ofsLaunchDist;
        float triggerErapsedTime;
        float triggerInterval;

    };
private:
    //オリジナルデータ
   DATA Boss1;
public:
    BOSS1(class GAME* game):CHARA(game){}
    void create();
    void update();
private:
    void Move();
    void Launch();
    void damage();
};


