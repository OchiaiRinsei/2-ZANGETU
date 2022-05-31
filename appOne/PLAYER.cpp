#include "PLAYER.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYERBULLETS.h"
#include"BOSSBULLETS.h"
PLAYER::PLAYER(class GAME* game) :
	GAME_OBJECT(game) {
}
void PLAYER::create() {
	Player = game()->container()->data().player;
}
void PLAYER::init() {
	Player.hp = game()->container()->data().player.hp;
	Player.pos = game()->container()->data().player.pos;
	Player.itemId = 0;
	Player.firstItemFrag = 0;
	Player.invincibility = 0;
	Player.buffBullet = 0;
	Player.time = 0.0f;
}
void PLAYER::update() {
	setImg();
	move();
	launch();
	appearItem();
	rightClick();
	countTime();
	damage();
}
void PLAYER::setImg() {
	//余弦定理でワンちゃんθだせるそれをangleできれいに回せるかも
	float cPx = game()->cursor()->px();
	float cPy = game()->cursor()->py();
	float distanceX = cPx - Player.pos.x;
	float distanceY = cPy - Player.pos.y;
	float naname = sqrt(distanceX * distanceX + distanceY * distanceY);
	float sin = distanceY / naname;
	float cos = distanceX / naname;
	if (isTrigger(KEY_W)) {
		Player.img = Player.nImg;
	}
	if (isTrigger(KEY_S)) {
		Player.img = Player.sImg;
	}
	if (isTrigger(KEY_D)) {
		Player.img = Player.eImg;
	}
	if (isTrigger(KEY_A)) {
		Player.img = Player.wImg;
	}
}
void PLAYER::move() {
	if (isPress(KEY_W)) { Player.vec.y = -1; }
	if (isPress(KEY_S)) { Player.vec.y = 1; }
	if (isPress(KEY_A)) { Player.vec.x = -1; }
	if (isPress(KEY_D)) { Player.vec.x = 1; }

	normalize(Player.vec);

	Player.pos += Player.vec * Player.adsSpeed * delta;
	Player.vec = (0, 0);
	//動きの制限(仮)
	if (Player.pos.x > width - 100) {
		Player.pos.x = width - 100;
	}
	if (Player.pos.x < 0 + 100) {
		Player.pos.x = 0 + 100;
	}
	if (Player.pos.y > height - 100) {
		Player.pos.y = height - 100;
	}
	if (Player.pos.y < 0 + 100) {
		Player.pos.y = 0 + 100;
	}
}
	
void PLAYER::launch() {
	float cPosX = game()->cursor()->px();
	float cPosY = game()->cursor()->py();
	if (isPress(MOUSE_LBUTTON)) {
		Player.triggerErapsedTime += delta;
		if (Player.triggerErapsedTime >= Player.triggerInterval) {
			float distanceX = (cPosX-Player.pos.x);
			float distanceY = (cPosY-Player.pos.y);
			float naname = sqrt(distanceX * distanceX + distanceY * distanceY);
			
			
			//0で割ることを防ぐ
			if (naname == 0) {
				naname = 1;
			}
			float a = distanceX / naname;
			float b = distanceY / naname;
			//
			VECTOR2 pos = Player.pos + VECTOR2(a,b) * Player.ofsLaunchDist;
			//a = b = 0の場合上方向に発射
			if (a == 0 && b == 0) {
				a = 0;
				b = -1;
			}
			game()->playerBullets()->launch(pos,  VECTOR2(a,b));
			Player.triggerErapsedTime = 0;
		}
	}
	else {
		Player.triggerErapsedTime = Player.triggerInterval;
	}
}
void PLAYER::appearItem() {
	if (Player.hp <= game()->container()->data().player.hp / 2&&Player.firstItemFrag == 0) {
		Player.itemId = random()%3+1;
		Player.firstItemFrag = 1;
	}

}
void PLAYER::rightClick() {
	if (isPress(MOUSE_RBUTTON)) {
		if (Player.itemId == 0) {}
		//HEAL
		if (Player.itemId == 1&&game()->heal()->possession()) {
			switch (game()->heal()->effect())
			{
			case 1:
				Player.hp += 7;
				Player.hp = game()->container()->data().player.hp <= Player.hp ? game()->container()->data().player.hp : Player.hp;
				break;
			case 2:
				Player.itemId = 0;
				break;
			default:
				break;
			}
		}
		//----------------------------
	}
	//BARRIER
	if (isTrigger(MOUSE_RBUTTON) && Player.itemId == 2&&game()->barrier()->possession()) {
		Player.invincibility = 1;
	}
	if (Player.invincibility == 1 && Player.itemId == 2 && game()->barrier()->possession() == 1 && game()->barrier()->effect() == 1) {
		Player.itemId = 0;
		Player.invincibility = 0;
	}
	//------------------------------------
	//PENETRATE
	if (isTrigger(MOUSE_RBUTTON) && Player.itemId == 3 && game()->penetrate()->possession()) {
		Player.buffBullet=1;
	}
	if (Player.itemId == 3 && game()->penetrate()->possession() && Player.buffBullet == 1 && game()->penetrate()->effect()==2) {
		Player.itemId = 0;
		Player.buffBullet = 0;
	}
	//-----------------------------------------
}
void PLAYER::damage() {
	if (Player.invincibility == 0) {
		float bRadius = game()->container()->data().bossBullets.radius;
		float damaged = game()->container()->data().bossBullets.damage;
		for (int i = 0; i < game()->bossBullets()->curNum(); i++) {
			VECTOR2 bPos = game()->bossBullets()->pos(i);
			float distanceX = bPos.x - Player.pos.x;
			float distanceY = bPos.y - Player.pos.y;
			float c = sqrt(distanceX * distanceX + distanceY * distanceY);
			if (c <= bRadius + Player.radius) {
				Player.hp -= damaged;
				game()->bossBullets()->kill(i);
			}
		}
	}
}
void PLAYER::countTime() {
	Player.time += 1.0f * delta;
}
void PLAYER::draw() {
	//確認用
	if (isPress(KEY_H)) {
		float cPx = game()->cursor()->px();
		float cPy = game()->cursor()->py();
		fill(0);
		strokeWeight(5);
		line(Player.pos.x, Player.pos.y, cPx, cPy);

		circle(Player.pos.x, Player.pos.y, Player.radius * 2);
	}
	//--------------------------------------

	//hpバー(仮) 
	rectMode(CORNER);
	stroke(255);
	fill(255);
	rect(40, height - 60, 1008, 50);

	stroke(0, 255, 0);
	fill(0, 255, 0);
	rect(44, height - 55, Player.hp*50, 40);
	//----------------------------------------------
	//アイテム表示欄(仮)
	noStroke();
	fill(255, 255, 0);
	rect(1700, 860, 200, 200);

	fill(255);
	rect(1715, 875, 170, 170);

	//-------------------------------------------
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, Player.angle, Player.scale);
}