#pragma once
#include "ITEM.h"
class HEAL :
    public ITEM
{
public:
    //�I���W�i���f�[�^
    struct DATA {
        float nowProgressTime;//�o�ߎ���
        float CompletionTime;//��������
        int healAmount;
    };
private:
    //�I���W�i���f�[�^
    DATA Heal;
public:
    HEAL(class GAME* game):ITEM(game){}
    void create();
    void update();
    void appear();
    int effect();
private:
};

