#pragma once
#include "ITEM.h"
class HEAL :
    public ITEM
{
public:
    //オリジナルデータ
    struct DATA {
        float nowProgressTime;
        float CompletionTime;
        int healAmount;
    };
private:
    //オリジナルデータ
    DATA Heal;
public:
    HEAL(class GAME* game):ITEM(game){}
    void create();
    void update();
    void appear();
    int effect();
private:
};

