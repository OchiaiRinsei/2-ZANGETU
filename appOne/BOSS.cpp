#include "BOSS.h"
#include"CONTAINER.h"
#include"GAME.h"
BOSS::BOSS(GAME* game) :
	GAME_OBJECT(game) {
}
void BOSS::create() {
}
void BOSS::init() {
	Boss.hp = 0;
}
void BOSS::update() {
	
}
void BOSS::draw() {
	//float px = game()->container()->data().bossBoss1.px;
	//float py = game()->container()->data().bossBoss1.py;
	rect(500, 500, 500, 500);
	image(Boss.img, 500, 600,Boss.angle, Boss.scale);
}
void BOSS::damage() {
	if (Boss.hp > 0) {
		Boss.hp--;
	}
}