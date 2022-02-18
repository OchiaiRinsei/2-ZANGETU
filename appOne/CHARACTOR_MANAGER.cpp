#include"CHARACTOR_MANAGER.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"CHARA.h"

CHARACTOR_MANAGER::CHARACTOR_MANAGER(class GAME* game) :
	GAME_OBJECT(game) {
}
CHARACTOR_MANAGER::~CHARACTOR_MANAGER() {
	for (int i = 0; i < numCharactors; i++) {
		delete Charactors[i];
	}
	delete[] Charactors;
}
void CHARACTOR_MANAGER::create() {


	Charactors = new CHARA * [numCharactors];

	Charactors[0] = new BOSS1(game());
	Charactors[1] = new BOSS2(game());
	Charactors[2] = new BOSS3(game());
	Charactors[3] = new BOSS_RHAND(game());
	Charactors[4] = new BOSS_LHAND(game());

	


	for (int i = 0; i < numCharactors; i++) {
		Charactors[i]->create();
	}
}
void CHARACTOR_MANAGER::init() {
	for (int i = 0; i < numCharactors; i++) {
		Charactors[i]->init();
	}
	
}
void CHARACTOR_MANAGER::update() {
	lasBossHp = Charactors[2]->hp();
	if (Charactors[0]->hp() <= 0 && Charactors[1]->hp() <= 0) {
		Charactors[2]->update();
		Charactors[3]->update();
		Charactors[4]->update();
	}
	else if (Charactors[0]->hp() <= 0) {
		Charactors[1]->update();
	}
	if(Charactors[0]->hp() > 0) {
		Charactors[0]->update();
	}
}
void CHARACTOR_MANAGER::draw() {
	if (Charactors[0]->hp() <= 0 && Charactors[1]->hp() <= 0) {
		Charactors[2]->draw();
		Charactors[3]->draw();
		Charactors[4]->draw();
	}
	else if (Charactors[0]->hp() <= 0) {
		Charactors[1]->draw();
	}
	if(Charactors[0]->hp() > 0){
		Charactors[0]->draw();
	}
}
	//for (int i = 0; i < numBosses; i++) {
	//	Bosses[i]->draw();
	//}





