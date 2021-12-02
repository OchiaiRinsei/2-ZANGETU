#include "STAGE.h"
#include"GAME.h"
#include"libOne.h"
#include"PLAYER.h"
#include"MAP.h"
#include"BOSS.h"
#include"BOSS1.h"
#include"CHARACTOR_MANAGER.h"
#include"TRANSITION.h"
#include"CURSOR.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {
}
void STAGE::init() {
	//game()->transition()->inTrigger();
	game()->bossManager()->init();
}
void STAGE::update() {
	game()->player()->update();
	game()->map()->update();
	game()->bossManager()->update();
	game()->cursor()->update();
	
}
void STAGE::draw() {
	clear(0);
	game()->map()->draw();
	game()->player()->draw();
	game()->bossManager()->draw();
	game()->cursor()->draw();
}

void STAGE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::SCORE_ID);
	}
}
