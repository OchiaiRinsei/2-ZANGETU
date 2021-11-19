#include "BOSS_MANAGER.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"BOSS.h"

BOSS_MANAGER::BOSS_MANAGER(class GAME* game) :
	GAME_OBJECT(game) {
}
BOSS_MANAGER::~BOSS_MANAGER() {
	for (int i = 0; i < Total; i++) {
		delete Bosses[i];
	}
	delete[] Bosses;
}
void BOSS_MANAGER::create() {
	int BossMng = 1;

	Total = 1;
	Bosses  = new BOSS * [Total];


	Bosses[0] = new BOSS1(game());

	for (int i = 0; i < Total; i++) {
		Bosses[i]->create();
	}
}
void BOSS_MANAGER::init() {
	for (int i = 0; i < Total; i++) {
		Bosses[i]->init();
	}
}
void BOSS_MANAGER::update() {
	for (int i = 0; i < Total; i++) {
		Bosses[i]->update();
	}
}
void BOSS_MANAGER::draw() {
	for (int i = 0; i < Total; i++) {
		Bosses[i]->draw();
	}
}

