#include "BOSS2.h"
#include"GAME.h"
#include"CHARA.h"
#include"CONTAINER.h"
#include"BOSSBULLETS.h"
void BOSS2::create() {
	Chara = game()->container()->data().charaBoss2;
	Boss2 = game()->container()->data().boss2;
}
void BOSS2::init() {
	Chara.hp = game()->container()->data().charaBoss2.hp;
	Boss2.triggerErapsedTime = game()->container()->data().boss2.triggerErapsedTime;
}
void BOSS2::update() {
	damage();
	Launch();
}
void BOSS2::Launch() {
	Boss2.triggerErapsedTime += 1.0 * delta;
	if (Boss2.triggerErapsedTime >= Boss2.triggerInterval) {
		
		Boss2.theta = random(1, 360);
		float a = cos(Boss2.theta);
		float b = sin(Boss2.theta);

		VECTOR2 pos = VECTOR2(Chara.px, Chara.py) + VECTOR2(a, b) * Boss2.ofsLaunchDist;

		game()->bossBullets()->launch(pos, VECTOR2(a, b));
		Boss2.triggerErapsedTime = 0;
	}
}