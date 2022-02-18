#pragma once
#include "ITEM.h"
class PENETRATE :
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
    DATA Penetrate;
public:
    PENETRATE(class GAME* game) :ITEM(game) {}
    void create();
    void init();
    void update();
    void appear();
    int effect();

};

