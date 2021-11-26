#include "BOSS.h"
#include"CONTAINER.h"
#include"GAME.h"
BOSS::BOSS(GAME* game) :
	GAME_OBJECT(game) {
}
void BOSS::create() {
}
void BOSS::init() {

}
void BOSS::update() {
	
}
void BOSS::draw() {
	image(Boss.img, Boss.px, Boss.py,Boss.angle, Boss.scale);
}
void BOSS::damage() {
	if (Boss.hp > 0) {
		Boss.hp--;
	}
}