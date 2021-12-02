#include"CHARACTOR_MANAGER.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"BOSS.h"

CHARACTOR_MANAGER::CHARACTOR_MANAGER(class GAME* game) :
	GAME_OBJECT(game) {
}
CHARACTOR_MANAGER::~CHARACTOR_MANAGER() {
	for (int i = 0; i < Total; i++) {
		delete Bosses[i];
	}
	delete[] Bosses;
}
void CHARACTOR_MANAGER::create() {
	int BossMng = 1;

	Total = 1;
	Bosses  = new BOSS * [Total];


	Bosses[0] = new BOSS1(game());

	for (int i = 0; i < Total; i++) {
		Bosses[i]->create();
	}
}
void CHARACTOR_MANAGER::init() {
	for (int i = 0; i < Total; i++) {
		Bosses[i]->init();
	}
}
void CHARACTOR_MANAGER::update() {
	for (int i = 0; i < Total; i++) {
		Bosses[i]->update();
	}
}
void CHARACTOR_MANAGER::draw() {
	for (int i = 0; i < Total; i++) {
		Bosses[i]->draw();
	}
}

