#include "STAGE.h"
#include"GAME.h"
#include"libOne.h"
#include"PLAYER.h"
#include"MAP.h"
#include"CHARA.h"
#include"BOSS1.h"
#include"BOSS2.h"
#include"BOSS3.h"
#include"CHARACTOR_MANAGER.h"
#include"TRANSITION.h"
#include"CURSOR.h"
#include"PLAYERBULLETS.h"
#include"BOSSBULLETS.h"
#include"ITEM.h"
#include"HEAL.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {
}
void STAGE::init() {
	//game()->transition()->inTrigger();
	game()->player()->init();
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
	game()->heal()->update();
}
void STAGE::draw() {
	clear(0);
	game()->map()->draw();
	game()->player()->draw();
	game()->charactorManager()->draw();
	game()->cursor()->draw();
	game()->playerBullets()->draw();
	game()->bossBullets()->draw();
	game()->heal()->draw();
}

void STAGE::nextScene() {
	if (game()->player()->hp() <= 0) {
		game()->changeScene(GAME::SCORE_ID);
	}
}
