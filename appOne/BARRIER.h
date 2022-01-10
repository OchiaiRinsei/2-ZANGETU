#pragma once
#include "ITEM.h"
class BARRIER :
    public ITEM
{
public:
    //オリジナルデータ
    struct DATA {
       
    };
private:
    //オリジナルデータ
    DATA Heal;
public:
    BARRIER(class GAME* game) :ITEM(game) {}
    void create();
    void update();
    void appear();
private:
};

