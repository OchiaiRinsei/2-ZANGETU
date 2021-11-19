#pragma once
#include "SCENE.h"
#include"libOne.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        int mainImg;
        VECTOR2 pos;
        float scalX;
        float scalY;
        float scale;
    };
private:
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void init();
    void create();
    void draw();
    void nextScene();
};

