#pragma once
#include "BOSS.h"
class BOSS1 :
    public BOSS
{
public:
    //�I���W�i���f�[�^
    struct DATA {
    };
private:
    //�I���W�i���f�[�^
   // DATA Boss1;
public:
    BOSS1(class GAME* game):BOSS(game){}
    void create();
    void update();
private:
    void Move();
    void damage();
};


