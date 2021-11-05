#include "STAGE.h"
#include"GAME.h"
#include"libOne.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {
}
void STAGE::init() {
}
void STAGE::draw() {
	clear(0);
	fill(255);
	textSize(200);
	text("STAGE", 300, 500);
}
void STAGE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::SCORE_ID);
	}
}
void STAGE::update() {
}