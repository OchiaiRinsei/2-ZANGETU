#pragma once
#include "ITEM.h"
class HEAL :
    public ITEM
{
public:
    //オリジナルデータ
    struct DATA {
        int itemId;
        int id;
    };
private:
    //オリジナルデータ
    DATA Heal;
public:
    HEAL(class GAME* game):ITEM(game){}
    void create();
    void update();
    void appear();
private:
};

