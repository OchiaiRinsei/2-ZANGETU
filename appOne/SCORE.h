#pragma once
#include "SCENE.h"
class SCORE :
    public SCENE
{
    int n1, n2, n3, n4;
public:
    SCORE(class GAME* game);
    ~SCORE();
    void init();
    void update();
    void draw();
    void nextScene();
};

