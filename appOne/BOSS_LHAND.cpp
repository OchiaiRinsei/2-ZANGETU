#include "BOSS_LHAND.h"
#include"GAME.h"
#include"CHARA.h"
#include"CONTAINER.h"
#include"BOSSBULLETS.h"
void BOSS_LHAND::create() {
	Chara = game()->container()->data().charaBossLHand;
	BossLHand = game()->container()->data().bossLHand;
}
void BOSS_LHAND::init() {
	Chara.hp = game()->container()->data().charaBossLHand.hp;
	BossLHand.triggerErapsedTime = game()->container()->data().bossLHand.triggerErapsedTime;
}
void BOSS_LHAND::update() {
	if (Chara.hp > 0) {
		damage();
		Launch();
		Move();
	}
}
void BOSS_LHAND::Launch() {
	float tPosX = game()->cursor()->px();
	float tPosY = game()->cursor()->py();
	BossLHand.triggerErapsedTime += 1.0 * delta;
	if (BossLHand.triggerErapsedTime >= BossLHand.triggerInterval) {
		float distanceX = (tPosX - Chara.px);
		float distanceY = (tPosY - Chara.py);
		float naname = sqrt(distanceX * distanceX + distanceY * distanceY);

		float a = distanceX / naname;
		float b = distanceY / naname;

		VECTOR2 pos = VECTOR2(Chara.px, Chara.py) + VECTOR2(a, b) * BossLHand.ofsLaunchDist;

		game()->bossBullets()->launch(pos, VECTOR2(a, b));
		game()->bossBullets()->launch(pos, VECTOR2(a + 0.1f, b - 0.1f));
		BossLHand.triggerErapsedTime = 0;
	}
}
void BOSS_LHAND::Move() {
	Chara.px = game()->container()->data().charaBoss1.px;
	Chara.py = game()->container()->data().charaBoss1.py;
	BossLHand.theta += 0.099;
	Chara.px = Chara.px + cos(BossLHand.theta) * BossLHand.rollDistance + sin(BossLHand.theta) * BossLHand.rollDistance;
	Chara.py = Chara.py - sin(BossLHand.theta) * BossLHand.rollDistance + cos(BossLHand.theta) * BossLHand.rollDistance;
	Chara.px += 10;
}