#pragma once
#include "GAME_OBJECT.h"
class CHARACTOR_MANAGER :
    public GAME_OBJECT
{
public:
    int numBosses = 1;
private:
    int Total = 0;
    class BOSS** Bosses = nullptr;
public:
    CHARACTOR_MANAGER(class GAME* game);
    ~CHARACTOR_MANAGER();
    void create();
    void init();
    void update();
    void draw();
};

