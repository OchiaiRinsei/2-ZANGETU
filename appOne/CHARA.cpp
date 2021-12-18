#include "CHARA.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
CHARA::CHARA(GAME* game) :
	GAME_OBJECT(game) {
}
void CHARA::create() {
}
void CHARA::init() {

}
void CHARA::update() {
	
}
void CHARA::draw() {
	//Šm”F—p
	fill(0);
	stroke(5);
	circle(Chara.px, Chara.py, Chara.radius*2);
	VECTOR2 pPos = game()->player()->pos();
	line(Chara.px, Chara.py, pPos.x, pPos.y);
	//-----------------------------
	image(Chara.img, Chara.px, Chara.py,Chara.angle, Chara.scale);
}
void CHARA::damage() {
	if (Chara.hp > 0) {
		Chara.hp--;
	}
}