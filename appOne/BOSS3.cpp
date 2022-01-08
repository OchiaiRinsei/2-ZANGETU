#include"GAME.h"
#include"CHARA.h"
#include "BOSS3.h"
#include"CONTAINER.h"
#include"BOSSBULLETS.h"

void BOSS3::create() {
	Chara = game()->container()->data().charaBoss3;
	Boss3 = game()->container()->data().boss3;
}
void BOSS3::update() {
	Move();
	damage();
	Launch();
}
void BOSS3::Move() {
	
}
void BOSS3::Launch() {
	float pPosX = game()->player()->pos().x;
	float pPosY = game()->player()->pos().y;
	Boss3.triggerErapsedTime += 1.0 * delta;
	if (Boss3.triggerErapsedTime >= Boss3.triggerInterval) {
		float distanceX = (pPosX - Chara.px);
		float distanceY = (pPosY - Chara.py);
		float naname = sqrt(distanceX * distanceX + distanceY * distanceY);


		float a = distanceX / naname;
		float b = distanceY / naname;

		VECTOR2 pos = VECTOR2(Chara.px, Chara.py) + VECTOR2(a, b) * Boss3.ofsLaunchDist;

		game()->bossBullets()->launch(pos, VECTOR2(a, b));
		Boss3.triggerErapsedTime = 0;
	}
}