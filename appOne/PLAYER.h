#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        float time;
        int hp;
        VECTOR2 pos;
        VECTOR2 vec;
        float angle;
        float adsSpeed;
        float scale;
        float radius;
        //Image
        int img;
        int nImg;
        int sImg;
        int eImg;
        int wImg;

        //bullets
        //int playerBulletsHp = 0;
        VECTOR2 launchVec;
        float triggerErapsedTime;
        float triggerInterval;
        float ofsLaunchDist;
        //item�Ǘ�
        int itemId;
        int firstItemFrag;
        //heal�֌W
        //barrier�֌W
        int invincibility;//���G���̏��
        //penetrate�֌W
        int buffBullet;//�e���ђʂ����邩
        
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    void create();
    void init();
    void update();
    void move();
    void setImg();
    void damage();
    void countTime();
    //bullets
    void launch();
    void draw();
    //item
    void appearItem();
    void rightClick();

    VECTOR2 vec() { return Player.vec; }
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }
    float radius() { return Player.radius; }
    //int playerBulletsHp(){ return Player.playerBulletsHp; }
    int itemId() { return Player.itemId; }
    int invincibility() { return Player.invincibility; }
    int buffBullet() { return Player.buffBullet; }
    float time() { return Player.time; }
};

