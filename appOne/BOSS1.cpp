#include"GAME.h"
#include"libOne.h"
#include"BOSS.h"
#include "BOSS1.h"
#include"CONTAINER.h"
void BOSS1::create() {
	Boss = game()->container()->data().bossBoss1;
	//Boss1 = game()->container()->data().boss1;
}
void BOSS1::update() {
	Move();
}
void BOSS1::Move() {
	int i = random() % 4;
    switch (i) {
	case 0:
		Boss.vx = 1;
		Boss.vy = 0;
		break;
	case 1:	  
		Boss.vx = -1;
		Boss.vy = 0;
		break;
	case 2:	  
		Boss.vx = 0;
		Boss.vy = 1;
		break;
	case 3:	  
		Boss.vx = 0;
		Boss.vy = -1;
		break;
	default:
		break;
    }
	Boss.px += Boss.vx * Boss.speed * delta;
	Boss.py += Boss.vy * Boss.speed * delta;
}
void BOSS1::damage() {
}