#pragma once
#include "ITEM.h"
class BARRIER :
    public ITEM
{
public:
    //�I���W�i���f�[�^
    struct DATA {
       
    };
private:
    //�I���W�i���f�[�^
    DATA Heal;
public:
    BARRIER(class GAME* game) :ITEM(game) {}
    void create();
    void update();
    void appear();
private:
};

