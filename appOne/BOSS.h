#pragma once
#include"GAME_OBJECT.h"
class BOSS :
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

        int hp = 0;
        float offsetLeft = 0;
        float offsetTop = 0;
        float offsetRight = 0;
        float offsetBottom = 0;
    };
protected:
    DATA Boss;
public:
    BOSS(class GAME* game);
    virtual void create();
    virtual void init();
    virtual void update();
    virtual void draw();
    virtual void damage();
    int hp() { return Boss.hp; }
    int groupId() { return Boss.gropId; }
};
