#pragma once
#include "GAME_OBJECT.h"
class CHARACTOR_MANAGER :
    public GAME_OBJECT
{
public:
    int numCharactors = 5;
    int lasBossHp = 0;
private:
    int Total = 0;
    class CHARA** Charactors = 0;
public:
    CHARACTOR_MANAGER(class GAME* game);
    ~CHARACTOR_MANAGER();
    void create();
    void init();
    void update();
    void draw();
    int lastBossHp(){return lasBossHp; }
};

