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
    };
private:
    //オリジナルデータ
    DATA Barrier;
public:
    BARRIER(class GAME* game) :ITEM(game) {}
    void create();
    void init();
    void update();
    void draw();
    void appear();
    int effect();

private:
    void EffectDraw();
};
