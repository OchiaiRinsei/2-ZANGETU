#pragma once
#include "CHARA.h"
class BOSS1 :
    public CHARA
{
public:
    //�I���W�i���f�[�^
    struct DATA {
        float theta;
        float rollDistance;
    };
private:
    //�I���W�i���f�[�^
   DATA Boss1;
public:
    BOSS1(class GAME* game):CHARA(game){}
    void create();
    void update();
private:
    void Move();
    void damage();
};


