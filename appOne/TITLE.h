#pragma once
#include "SCENE.h"
#include"libOne.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        int mainImg,logoImg,startImg,scoreImg;
        VECTOR2 mainPos,logoPos,startPos,scorePos;
        float radius;
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

