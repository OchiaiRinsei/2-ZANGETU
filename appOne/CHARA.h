#pragma once
#include"GAME_OBJECT.h"
class CHARA :
    public GAME_OBJECT
{
public:
    struct DATA {

        int img=0;

        char bossId = 0;
        int gropId = 0;
        float px = 0;
        float py = 0;
        float vx = 0;
        float vy = 0;
        float speed = 0;
        float angle = 0;
        float scale = 0;
        float radius = 0;

        int hp = 0;
        float offsetLeft = 0;
        float offsetTop = 0;
        float offsetRight = 0;
        float offsetBottom = 0;
    };
protected:
    DATA Chara;
public:
    CHARA(class GAME* game);
    virtual void create();
    virtual void init();
    virtual void update();
    virtual void draw();
    virtual void damage();
    int hp() { return Chara.hp; }
};
