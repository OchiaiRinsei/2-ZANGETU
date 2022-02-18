#pragma once
#include"CHARA.h"
class BOSS_LHAND :
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
    DATA BossLHand;
public:
    BOSS_LHAND(class GAME* game) :CHARA(game) {}
    void create();
    void init();
    void update();
    int hp() { return Chara.hp; }
private:
    void Launch();
    void Move();
};


