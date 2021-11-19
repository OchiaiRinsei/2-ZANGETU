#include "STAGE.h"
#include"GAME.h"
#include"libOne.h"
#include"PLAYER.h"
#include"MAP.h"
#include"BOSS.h"
#include"BOSS1.h"
#include"BOSS_MANAGER.h"
#include"TRANSITION.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {
}
void STAGE::init() {
	game()->transition()->inTrigger();
}

void STAGE::draw() {
	clear(0);
	game()->map()->draw();

	game()->player()->draw();
	game()->transition()->draw();

	//bosses[BOSS1_ID]->update();
	//bosses[BOSS1_ID]->draw();
}

void STAGE::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::SCORE_ID);
	}
}

void STAGE::update() {
	game()->player()->update();
	game()->map()->update();
	//bosses = new BOSS * [NUM_BOSSES];
	//bosses[BOSS1_ID] = new BOSS1(game());
}