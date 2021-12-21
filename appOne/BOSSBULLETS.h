#pragma once
#include "BULLETS.h"
class BOSSBULLETS :
    public BULLETS
{
public:
    BOSSBULLETS(class GAME* game);
    void create();
};

