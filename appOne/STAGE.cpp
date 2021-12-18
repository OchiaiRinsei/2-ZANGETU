#include "STAGE.h"
#include"GAME.h"
#include"libOne.h"
#include"PLAYER.h"
#include"MAP.h"
#include"CHARA.h"
#include"BOSS1.h"
#include"CHARACTOR_MANAGER.h"
#include"TRANSITION.h"
#include"CURSOR.h"
#include"PLAYERBULLETS.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {
}
void STAGE::init() {
	//game()->transition()->inTrigger();
	game()->charactorManager()->init();
	game()->playerBullets()->init();
}
void STAGE::update() {
	game()->player()->update();
	game()->map()->update();
	game()->charactorManager()->update();
	game()->cursor()->update();
	game()->playerBullets()->update();
}
void STAGE::draw() {
	clear(0);
	game()->map()->draw();
	game()->player()->draw();
	game()->charactorManager()->draw();
	game()->cursor()->draw();
	game()->playerBullets()->draw();
}

void STAGE::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::SCORE_ID);
	}
}
