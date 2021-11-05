#pragma once
#include "SCENE.h"
#include"libOne.h"
class TITLE :
    public SCENE
{
public:
    TITLE(class GAME* game);
    ~TITLE();
    void init();
    void create();
    void draw();
    void nextScene();
};

