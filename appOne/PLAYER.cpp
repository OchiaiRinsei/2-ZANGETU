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
}
void PLAYER::update() {
	move();
	launch();
	rightClick();
	damage();
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
	if (isPress(KEY_SPACE)) {
		Player.triggerErapsedTime += delta;
		if (Player.triggerErapsedTime >= Player.triggerInterval) {
			float distanceX = (cPosX-Player.pos.x);
			float distanceY = (cPosY-Player.pos.y);
			float naname = sqrt(distanceX * distanceX + distanceY * distanceY);
			
			
			//0で割ることを防ぐ
			/*
			if (naname == 0) {
				naname = 1;
			}
			*/
			float a = distanceX / naname;
			float b = distanceY / naname;
			//
			VECTOR2 pos = Player.pos + VECTOR2(a,b) * Player.ofsLaunchDist;
			//a = b = 0の場合上方向に発射
			/*
			if (a == 0 && b == 0) {
				a = 0;
				b = -1;
			}
			*/
			game()->playerBullets()->launch(pos,  VECTOR2(a,b));
			Player.triggerErapsedTime = 0;
		}
	}
	else {
		Player.triggerErapsedTime = Player.triggerInterval;
	}
}
int PLAYER::appearItem() {
	if (Player.hp <= game()->container()->data().player.hp / 2&&Player.firstItemFrag == 0) {
		Player.itemId = 1;//random()%2+1;//後のアイテム完成後にランダム性を持たせる
		Player.firstItemFrag = 1;
		return Player.itemId;
	}
	return 0;
}
void PLAYER::rightClick() {//switch文のほうが見やすいかも余裕あったら
	if (isPress(KEY_M)) {
		if (Player.itemId == 0) {
			//ここにアイテム表示を暗くする(fillを暗くする)をいれる。後回し
		}
		//HEALに移したほうがいい時間あるとき
		if (Player.itemId == 1&&game()->heal()->possession()) {
			//使用中の動き等の制限追加予定
			//game()->heal()->effect()
			switch (game()->heal()->effect())
			{
			case 1:
				Player.hp += 250;
				break;
			case 2:
				Player.itemId = 0;
				break;
			default:
				break;
			}
		}
		if (Player.itemId == 2) {

		}
		//-----------------------------


	}
}
void PLAYER::damage() {
	float bRadius = game()->container()->data().bossBullets.radius;
	float damaged = game()->container()->data().bossBullets.damage;
	for (int i = 0; i < game()->bossBullets()->curNum(); i++) {
		VECTOR2 bPos = game()->bossBullets()->pos(i);
		float distanceX = bPos.x - Player.pos.x;
		float distanceY = bPos.y - Player.pos.y;
		float c = sqrt(distanceX * distanceX + distanceY * distanceY);
		if (c <= bRadius + Player.radius) {
			Player.hp -= damaged;
		}
	} 
}
void PLAYER::draw() {
	//確認用
	float cpx = game()->cursor()->px();
	float cpy = game()->cursor()->py();
	fill(0);
	strokeWeight(5);
	line(Player.pos.x, Player.pos.y, cpx, cpy);

	circle(Player.pos.x, Player.pos.y, Player.radius * 2);
	//--------------------------------------
	
	//hpバー(仮) 
	rectMode(CORNER);
	stroke(255);
	rect(40, height - 60, 1008, 50);

	stroke(0, 255, 0);
	fill(0, 255, 0);
	rect(44, height - 55, Player.hp, 40);
	//----------------------------------------------
	//アイテム表示欄(仮)
	noStroke();
	fill(255, 255, 0);
	rect(1700, 860, 200, 200);
	if (Player.itemId == 0) {
		fill(255);
		rect(1715, 875, 170, 170);
	}
	//-------------------------------------------
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, 0, Player.scale);
}