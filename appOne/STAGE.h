#pragma once
#include "SCENE.h"
#include"libOne.h"
class STAGE :
    public SCENE
{
public:
    STAGE(class GAME* game);
    ~STAGE();
    void init();
    void update();
    void draw();
    void nextScene();
};

