#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class MAP :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        VECTOR2 pos;
        float scale;
        float AlimmitX;
        float DlimmitX;
        float WlimmitY;
        float SlimmitY;
    };
private:
    DATA Map;
public:
    MAP(class GAME* game);
    void create();
    void update();
    void draw();
};