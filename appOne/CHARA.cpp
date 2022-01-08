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
	if (Chara.hp >= 0) {
	//確認用
	fill(0);
	stroke(5);
	circle(Chara.px, Chara.py, Chara.radius*2);
	VECTOR2 pPos = game()->player()->pos();
	line(Chara.px, Chara.py, pPos.x, pPos.y);
	//-----------------------------
	//BOSSのhpの確認
	textSize(100);
	text(Chara.hp, 100, 100);
	//-----------------------------
	image(Chara.img, Chara.px, Chara.py, Chara.angle, Chara.scale);
	}
}
void CHARA::damage() {
	float pRadius = game()->container()->data().player.radius;
	float damaged = game()->container()->data().playerBullets.damage;
	for (int i = 0; i < game()->playerBullets()->curNum(); i++) {
		VECTOR2 bPos = game()->playerBullets()->pos(i);
		float distanceX = bPos.x - Chara.px;
		float distanceY = bPos.y - Chara.py;
		float c = sqrt(distanceX * distanceX + distanceY * distanceY);
		if (c <= pRadius + Chara.radius) {
			Chara.hp -= damaged;
		}
	}
}