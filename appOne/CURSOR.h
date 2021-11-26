#pragma once
#include "GAME_OBJECT.h"
class CURSOR :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        float px;
        float py;
        float scale;
    };
private:
    DATA Cursor;
public:
    CURSOR(class GAME* game);
    void create();
    void init();
    void update();
    void draw();
    float px() { return Cursor.px; }
    float py() { return Cursor.py; }
};

