#include "BOSS.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
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
	//Šm”F—p
	fill(0);
	stroke(5);
	circle(Boss.px, Boss.py, Boss.radius*2);
	VECTOR2 pPos = game()->player()->pos();
	line(Boss.px, Boss.py, pPos.x, pPos.y);
	//-----------------------------
	image(Boss.img, Boss.px, Boss.py,Boss.angle, Boss.scale);
}
void BOSS::damage() {
	if (Boss.hp > 0) {
		Boss.hp--;
	}
}