#pragma once
#include "ITEM.h"
class BARRIER :
    public ITEM
{
public:
    //�I���W�i���f�[�^
    struct DATA {
        float nowProgressTime;//�o�ߎ���
        float CompletionTime;//��������
        int invincibility;//���G
    };
private:
    //�I���W�i���f�[�^
    DATA Barrier;
public:
    BARRIER(class GAME* game) :ITEM(game) {}
    void create();
    void update();
    void draw();
    void appear();
    int effect();

    int invincibility() { return Barrier.invincibility; }
private:
    void effectDraw();
};
