#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        VECTOR2 pos;
        VECTOR2 vec;
        float adsSpeed;
        float scale;
        float radius;
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    void create();
    void init();
    void update();
       void move();
    void draw();
    VECTOR2 vec() { return Player.vec; }
    VECTOR2 pos() { return Player.pos; }
};

