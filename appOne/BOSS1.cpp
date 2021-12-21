#include"GAME.h"
#include"CHARA.h"
#include "BOSS1.h"
#include"CONTAINER.h"
#include"BOSSBULLETS.h"
void BOSS1::create() {
	Chara = game()->container()->data().charaBoss1;
	Boss1 = game()->container()->data().boss1;
}
void BOSS1::update() {
	Move();
	Launch();
}
void BOSS1::Move() {
	Chara.px = game()->container()->data().charaBoss1.px;
	Chara.py = game()->container()->data().charaBoss1.py;
	Boss1.theta += 0.03333;
	Chara.px = Chara.px +cos(Boss1.theta) * Boss1.rollDistance + sin(Boss1.theta)*Boss1.rollDistance;
	Chara.py = Chara.py -sin(Boss1.theta) * Boss1.rollDistance + cos(Boss1.theta)*Boss1.rollDistance;
	
}
void BOSS1::Launch() {
	float pPosX = game()->player()->pos().x;
	float pPosY = game()->player()->pos().y;
		Boss1.triggerErapsedTime += 1.0*delta;
		if (Boss1.triggerErapsedTime >= Boss1.triggerInterval) {
			float distanceX = (pPosX - Chara.px);
			float distanceY = (pPosY - Chara.py);
			float naname = sqrt(distanceX * distanceX + distanceY * distanceY);


			float a = distanceX / naname;
			float b = distanceY / naname;

			VECTOR2 pos = VECTOR2(Chara.px, Chara.py) + VECTOR2(a, b) * Boss1.ofsLaunchDist;
			
			game()->bossBullets()->launch(pos, VECTOR2(a, b));
			Boss1.triggerErapsedTime = 0;
		}
}
void BOSS1::damage() {
}