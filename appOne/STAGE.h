#pragma once
#include "SCENE.h"
class STAGE :
    public SCENE
{
private:
    //class BOSS** bosses = nullptr;
    //class BOSS_MANAGER* BossManager = nullptr;
public:
    //class BOSS_MANAGER* bossManager() { return BossManager; }
    
//public:
//    enum BOSS_ID {
//        BOSS1_ID,
//        NUM_BOSSES
//    };
public:
    STAGE(class GAME* game);
    ~STAGE();
    void init();
    void update();
    void draw();
    void nextScene();
};

