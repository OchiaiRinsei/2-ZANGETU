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

	//個別テスト用 テストの際はヘッダーのnumBossesを１にしてください
	//Bosses = new CHARA * [1];
	//Bosses[0] = new BOSS3(game());


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
	
	if (Charactors[0]->hp() <= 0 && Charactors[1]->hp() <= 0) {
		Charactors[2]->update();
	}
	else if (Charactors[0]->hp() <= 0) {
		Charactors[1]->update();
	}
	if(Charactors[0]->hp() >= 0) {
		Charactors[0]->update();
	}
}
void CHARACTOR_MANAGER::draw() {
	if (Charactors[0]->hp() <= 0 && Charactors[1]->hp() <= 0) {
		Charactors[2]->draw();
	}
	else if (Charactors[0]->hp() <= 0) {
		Charactors[1]->draw();
	}
	if(Charactors[0]->hp() >= 0){
		Charactors[0]->draw();
	}

}
	//for (int i = 0; i < numBosses; i++) {
	//	Bosses[i]->draw();
	//}





