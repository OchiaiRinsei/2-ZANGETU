#include "PLAYER.h"
#include"GAME.h"
#include"CONTAINER.h"
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
}
void PLAYER::move() {
	//struct VECTOR2 b;
	if (isPress(KEY_W)) { Player.vec.y = -1; }
	if (isPress(KEY_S)) { Player.vec.y = 1; }
	if (isPress(KEY_A)) { Player.vec.x = -1; }
	if (isPress(KEY_D)) { Player.vec.x = 1; }

	Player.pos.x += Player.vec.x * Player.adsSpeed * delta;
	Player.pos.y += Player.vec.y * Player.adsSpeed * delta;
	//ŽÎ‚ßˆÚ“®‚Ì³‹K‰»‚ÍŒã‰ñ‚µ
	Player.vec.x = 0;
	Player.vec.y = 0;
	//“®‚«‚Ì§ŒÀ
	if (Player.pos.x > width-100) {
		Player.pos.x = width-100;
	}
	if (Player.pos.x < 0+100) {
		Player.pos.x = 0+100;
	}
	if (Player.pos.y > height-100) {
		Player.pos.y = height-100;
	}			   
	if (Player.pos.y < 0+100) {
		Player.pos.y = 0+100;
	}
}
void PLAYER::draw() {
	image(Player.img, Player.pos.x, Player.pos.y,0,Player.scale);
}