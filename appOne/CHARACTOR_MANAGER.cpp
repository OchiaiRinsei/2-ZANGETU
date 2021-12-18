#include"CHARACTOR_MANAGER.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"CHARA.h"
#include"PLAYER.h"
#include"BULLETS.h"

CHARACTOR_MANAGER::CHARACTOR_MANAGER(class GAME* game) :
	GAME_OBJECT(game) {
}
CHARACTOR_MANAGER::~CHARACTOR_MANAGER() {
	for (int i = 0; i < numBosses; i++) {
		delete Bosses[i];
	}
	delete[] Bosses;
}
void CHARACTOR_MANAGER::create() {
	int BossMng = 1;

	//Total = 9;

	Bosses  = new CHARA * [1];
	Bullets = new BULLETS * [8];

	Bosses[0] = new BOSS1(game());
	

	for (int i = 0; i < 1; i++) {
		Bosses[i]->create();
	}
}
void CHARACTOR_MANAGER::init() {
	for (int i = 0; i < numBosses; i++) {
		Bosses[i]->init();
	}
}
void CHARACTOR_MANAGER::update() {
	for (int i = 0; i < numBosses; i++) {
		Bosses[i]->update();
	}
}
void CHARACTOR_MANAGER::draw() {
	for (int i = 0; i < numBosses; i++) {
		Bosses[i]->draw();
	}
}