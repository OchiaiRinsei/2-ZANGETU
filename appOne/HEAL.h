#pragma once
#include "ITEM.h"
class HEAL :
    public ITEM
{
public:
    //�I���W�i���f�[�^
    struct DATA {
        int itemId;
        int id;
    };
private:
    //�I���W�i���f�[�^
    DATA Heal;
public:
    HEAL(class GAME* game):ITEM(game){}
    void create();
    void update();
    void appear();
private:
};

