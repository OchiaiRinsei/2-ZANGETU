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
#include"BOSSBULLETS.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {
}
void STAGE::init() {
	//game()->transition()->inTrigger();
	game()->charactorManager()->init();
	game()->playerBullets()->init();
	game()->bossBullets()->init();
}
void STAGE::update() {
	game()->player()->update();
	game()->map()->update();
	game()->charactorManager()->update();
	game()->cursor()->update();
	game()->playerBullets()->update();
	game()->bossBullets()->update();
}
void STAGE::draw() {
	clear(0);
	game()->map()->draw();
	game()->player()->draw();
	game()->charactorManager()->draw();
	game()->cursor()->draw();
	game()->playerBullets()->draw();
	game()->bossBullets()->draw();
}

void STAGE::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::SCORE_ID);
	}
}
