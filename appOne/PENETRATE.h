#pragma once
#include "ITEM.h"
class PENETRATE :
    public ITEM
{
public:
    //�I���W�i���f�[�^
    struct DATA {
        float nowProgressTime;//�o�ߎ���
        float CompletionTime;//��������
    };
private:
    //�I���W�i���f�[�^
    DATA Penetrate;
public:
    PENETRATE(class GAME* game) :ITEM(game) {}
    void create();
    void init();
    void update();
    void appear();
    int effect();

};

