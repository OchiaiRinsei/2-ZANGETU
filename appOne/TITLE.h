#pragma once
#include "SCENE.h"
#include"libOne.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        int mainImg=0,logoImg=0,startImg=0,scoreImg=0;
        VECTOR2 mainPos,logoPos,startPos,scorePos;
        float radius=0;
        float scale;
        int ID;
    };
private:
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void init();
    void create();
    void update();
    void draw();
    void nextScene();
};

