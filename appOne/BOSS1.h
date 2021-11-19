#pragma once
#include "BOSS.h"
class BOSS1 :
    public BOSS
{
public:
    //オリジナルデータ
    struct DATA {
    };
private:
    //オリジナルデータ
   // DATA Boss1;
public:
    BOSS1(class GAME* game):BOSS(game){}
    void create();
    void update();
private:
    void Move();
    void damage();
};


