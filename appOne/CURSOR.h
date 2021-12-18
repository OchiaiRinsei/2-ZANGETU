#pragma once
#include "GAME_OBJECT.h"
class CURSOR :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img=0;
        float px=0;
        float py=0;
        float scale=0;

        float radius=0;
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
    float radius() { return Cursor.radius; }
};

