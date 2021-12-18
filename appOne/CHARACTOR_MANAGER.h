#pragma once
#include "GAME_OBJECT.h"
class CHARACTOR_MANAGER :
    public GAME_OBJECT
{
public:
    int numBosses = 1;
    int numBullets = 8;
private:
    int Total = 0;
    class CHARA** Bosses = 0;
    class BULLETS** Bullets = 0;
public:
    CHARACTOR_MANAGER(class GAME* game);
    ~CHARACTOR_MANAGER();
    void create();
    void init();
    void update();
    void draw();
};

