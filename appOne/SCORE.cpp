#include "SCORE.h"
#include"GAME.h"
#include"libOne.h"
#include"PLAYER.h"
SCORE::SCORE(class GAME* game) :
	SCENE(game) {
}
SCORE::~SCORE() {
}
void SCORE::init() {
}
void SCORE::draw() {
	//CLAER
	if (game()->player()->hp() > 0) {
	clear(160);
	textSize(150);
	text("CLEARTIME", 1200, 300);
	float time = game()->player()->time();
	text(time, 100, 500);
	}
	//----------------------
	else {
		textSize(200);
		fill(255, 0, 0);
		text("GAME_OVER", width/2-200, height/2);
		textSize(100);
		fill(0);
		text("PUSH_SPACE", width / 2, 700);
	}
}
void SCORE::update() {
	
}
void SCORE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}