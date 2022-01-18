#pragma once
#include "ITEM.h"
class BARRIER :
    public ITEM
{
public:
    //オリジナルデータ
    struct DATA {
        float nowProgressTime;//経過時間
        float CompletionTime;//完了時間
        int invincibility;//無敵
    };
private:
    //オリジナルデータ
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
