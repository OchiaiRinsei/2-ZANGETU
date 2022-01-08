#pragma once
#include"CHARA.h"
class BOSS3 :
    public CHARA
{
public:
    //�I���W�i���f�[�^
    struct DATA {
        //Move
        float angle;
        float RotSpeed;
        //VECTOR2 Vel;
        //VECTOR2 Acc;
        //VECTOR2 V;
        float MaxSpeed;
        float MaxForce;
        float NearDistance;
        //Launch
        float theta;
        float ofsLaunchDist;
        float triggerErapsedTime;
        float triggerInterval;
    };
private:
    //�I���W�i���f�[�^
    DATA Boss3;
public:
    BOSS3(class GAME* game) :CHARA(game) {}
    void create();
    void update();
private:
    void Launch();
    void Move();
};