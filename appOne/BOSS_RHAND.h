#pragma once
#include"CHARA.h"
class BOSS_RHAND :
    public CHARA
{
public:
    //�I���W�i���f�[�^
    struct DATA {
        float theta;
        float ofsLaunchDist;
        float triggerErapsedTime;
        float triggerInterval;
    };
private:
    //�I���W�i���f�[�^
    DATA BossRHand;
public:
    BOSS_RHAND(class GAME* game) :CHARA(game) {}
    void create();
    void init();
    void update();
    int hp() { return Chara.hp; }
private:
    void Launch();
    void Move();
};

