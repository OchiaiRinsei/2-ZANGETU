#pragma once
#include"CHARA.h"
class BOSS2 :
    public CHARA
{
public:
    //オリジナルデータ
    struct DATA {
        float theta;
        float ofsLaunchDist;
        float triggerErapsedTime;
        float triggerInterval;
    };
private:
    //オリジナルデータ
    DATA Boss2;
public:
    BOSS2(class GAME* game) :CHARA(game) {}
    void create();
    void update();
private:
    void Launch();
};

