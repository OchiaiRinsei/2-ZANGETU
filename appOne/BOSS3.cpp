#include"GAME.h"
#include"CHARA.h"
#include "BOSS3.h"
#include"CONTAINER.h"
#include"BOSSBULLETS.h"
#include"PLAYER.h"
void BOSS3::create() {
	Chara = game()->container()->data().charaBoss3;
	Boss3 = game()->container()->data().boss3;
}
void BOSS3::init() {
	Chara.hp = game()->container()->data().charaBoss3.hp;
	Chara.px = game()->container()->data().charaBoss3.px;
	Chara.py = game()->container()->data().charaBoss3.py;
	Boss3.triggerErapsedTime = game()->container()->data().boss3.triggerErapsedTime;
}
void BOSS3::update() {
	Move();
	damage();
	Launch();
}
void BOSS3::Move() {
	if (Chara.hp <= game()->container()->data().charaBoss3.hp/2) {//‚±‚±‚ÉŽè‚Ìhp‚ª2‚Â‚Æ‚à‚O‚È‚ç‚ð‚¢‚ê‚é
		float distanceX = width / 2-random(300,-300) - Chara.px;
		float distanceY = height / 2-random(300,-300) - Chara.py;
		float naname = sqrt(distanceX * distanceX + distanceY * distanceY);
		float targetX = distanceX / naname;
		float targetY = distanceY / naname;

		if (Chara.vx == 0 && Chara.vy == 0) {
			Chara.vx = targetX * Chara.speed;
			Chara.vy = targetY * Chara.speed;
		}

		Chara.px += Chara.vx;
		Chara.py += Chara.vy;

		if (Chara.px > width + Chara.radius) {
			Chara.px = -Chara.radius;
			Chara.py = random(0, 1080);
			Chara.vx = 0;
			Chara.vy = 0;
		}
		if (Chara.px < 0 - Chara.radius) {
			Chara.px = width + Chara.radius;
			Chara.py = random(0, 1080);
			Chara.vx = 0;
			Chara.vy = 0;
		}
		if (Chara.py > height + Chara.radius) {
			Chara.py = -Chara.radius;
			Chara.px = random(0, 1920);
			Chara.vx = 0;
			Chara.vy = 0;
		}
		if (Chara.py < 0 - Chara.radius) {
			Chara.py = height + Chara.radius;
			Chara.px = random(0, 1920);
			Chara.vx = 0;
			Chara.vy = 0;
		}
	}
}
void BOSS3::Launch() {
	if (Chara.hp <= game()->container()->data().charaBoss3.hp / 2) {
		Boss3.triggerInterval = 0.2f;
	}
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