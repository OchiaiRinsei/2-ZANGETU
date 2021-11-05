#include "SCORE.h"
#include"GAME.h"
#include"libOne.h"
SCORE::SCORE(class GAME* game) :
	SCENE(game) {
}
SCORE::~SCORE() {
}
void SCORE::init() {
}
void SCORE::draw() {
	clear(0);
	fill(255);
	textSize(200);
	text("SCORE", 300, 500);
}
void SCORE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
void SCORE::update() {
}