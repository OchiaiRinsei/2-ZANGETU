#include "BOSS_RHAND.h"
#include"GAME.h"
#include"CHARA.h"
#include"CONTAINER.h"
#include"BOSSBULLETS.h"
void BOSS_RHAND::create() {
	Chara = game()->container()->data().charaBossRHand;
	BossRHand = game()->container()->data().bossRHand;
}
void BOSS_RHAND::init() {
	Chara.hp = game()->container()->data().charaBossRHand.hp;
	BossRHand.triggerErapsedTime = game()->container()->data().bossRHand.triggerErapsedTime;
}
void BOSS_RHAND::update() {
	if (Chara.hp > 0) {
		damage();
		Launch();
		Move();
	}
}
void BOSS_RHAND::Launch() {
	float pPosX = game()->player()->pos().x;
	float pPosY = game()->player()->pos().y;
	BossRHand.triggerErapsedTime += 1.0 * delta;
	if (BossRHand.triggerErapsedTime >= BossRHand.triggerInterval) {
		float distanceX = (pPosX - Chara.px);
		float distanceY = (pPosY - Chara.py);
		float naname = sqrt(distanceX * distanceX + distanceY * distanceY);


		float a = distanceX / naname;
		float b = distanceY / naname;

		VECTOR2 pos = VECTOR2(Chara.px, Chara.py) + VECTOR2(a, b) * BossRHand.ofsLaunchDist;

		game()->bossBullets()->launch(pos, VECTOR2(a, b));
		game()->bossBullets()->launch(pos, VECTOR2(a + 0.1f, b - 0.1f));
		BossRHand.triggerErapsedTime = 0;
	}
}
void BOSS_RHAND::Move() {
	VECTOR2 pPos = game()->player()->pos();
	VECTOR2 v =VECTOR2(width/2, height/2)- pPos;
	v = normalize(v);
	Chara.px = width/2 + v.x * -150;
	Chara.py = height / 2 + v.y * -150;
}