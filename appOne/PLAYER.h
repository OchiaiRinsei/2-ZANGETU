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

        //bullets
        int playerBulletsHp = 0;
        VECTOR2 launchVec;
        float triggerErapsedTime;
        float triggerInterval;
        float ofsLaunchDist;
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    void create();
    void init();
    void update();
    void move();
    //bullets
    void launch();
    void draw();
    VECTOR2 vec() { return Player.vec; }
    VECTOR2 pos() { return Player.pos; }
    int playerBulletsHp(){ return Player.playerBulletsHp; }
};

