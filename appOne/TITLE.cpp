#include "TITLE.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"libOne.h"
#include"TRANSITION.h"
TITLE::TITLE(class GAME*game) :
	SCENE(game){
}
TITLE::~TITLE() {
}
void TITLE::init() {
	game()->transition()->inTrigger();
}
void TITLE::create() {
	Title = game()->container()->data().title;
}
void TITLE::draw() {
	clear(0);
	image(Title.mainImg, Title.pos.x, Title.pos.y);

	//‰æ‘œ‚É’u‚«Š·‚¦—\’è
	fill(255);
	textSize(50);
	text("PLAY", 300, 900);
	text("SCORE", 1400, 900);

	game()->transition()->draw();
}
void TITLE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->transition()->outTrigger();
	}
	if (game()->transition()->outEndFlag()) {
		game()->changeScene(GAME::STAGE_ID);
	}
}