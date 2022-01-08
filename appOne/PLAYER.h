#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        int hp;
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
        //itemä«óù
        int itemId;
        int firstItemFrag;
        //heal
        float nowHealProgressTime;
        float healCompletionTime;
        int healDurability;
        int healAmount;
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    void create();
    void init();
    void update();
    void move();
    void damage();
    //bullets
    void launch();
    void draw();
    //item
    int appearItem();
    void rightClick();
    VECTOR2 vec() { return Player.vec; }
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }
    float radius() { return Player.radius; }
    int playerBulletsHp(){ return Player.playerBulletsHp; }
};

