#pragma once
#include "SCENE.h"
#include"libOne.h"
class SCORE :
    public SCENE
{
public:
    SCORE(class GAME* game);
    ~SCORE();
    void init();
    void update();
    void draw();
    void nextScene();
};

