#pragma once
#include "GAME_OBJECT.h"
class BOSS_MANAGER :
    public GAME_OBJECT
{
public:
    int numBosses = 1;
private:
    int Total = 0;
    class BOSS** Bosses = nullptr;
public:
    BOSS_MANAGER(class GAME* game);
    ~BOSS_MANAGER();
    void create();
    void init();
    void update();
    void draw();
};

