#include "TITLE.h"
#include"GAME.h"
#include"libOne.h"
TITLE::TITLE(class GAME*game) :
	SCENE(game){
}
TITLE::~TITLE() {
}
void TITLE::init() {
}
void TITLE::create() {
}
void TITLE::draw() {
	clear(0);
	fill(255);
	textSize(200);
	text("TITLE", 300, 500);
}
void TITLE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::STAGE_ID);
	}
}