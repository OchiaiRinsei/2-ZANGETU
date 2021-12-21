#include "PLAYER.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYERBULLETS.h"
PLAYER::PLAYER(class GAME* game) :
	GAME_OBJECT(game) {
}
void PLAYER::create() {
	//Player = game()->container()->player();
	Player = game()->container()->data().player;
}
void PLAYER::init() {
}
void PLAYER::update() {
	move();
	launch();
}
void PLAYER::move() {
	if (isPress(KEY_W)) { Player.vec.y = -1; }
	if (isPress(KEY_S)) { Player.vec.y = 1; }
	if (isPress(KEY_A)) { Player.vec.x = -1; }
	if (isPress(KEY_D)) { Player.vec.x = 1; }
	//³‹K‰»‚Å‚«‚Ä‚È‚¢‚í
	normalize(Player.vec);
	//
	Player.pos += Player.vec * Player.adsSpeed * delta;
	Player.vec = (0, 0);
	//“®‚«‚Ì§ŒÀ
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
			
			
			//0‚ÅŠ„‚é‚±‚Æ‚ð–h‚®
			/*
			if (naname == 0) {
				naname = 1;
			}
			*/
			float a = distanceX / naname;
			float b = distanceY / naname;
			//
			VECTOR2 pos = Player.pos + VECTOR2(a,b) * Player.ofsLaunchDist;
			//a = b = 0‚Ìê‡ã•ûŒü‚É”­ŽË
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
void PLAYER::draw() {
	//Šm”F—p
	float cpx = game()->cursor()->px();
	float cpy = game()->cursor()->py();
	fill(0);
	strokeWeight(5);
	line(Player.pos.x, Player.pos.y, cpx, cpy);

	circle(Player.pos.x, Player.pos.y, Player.radius * 2);
	//--------------------------------------
	image(Player.img, Player.pos.x, Player.pos.y, 0, Player.scale);
}