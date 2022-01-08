#include"libOne.h"
#include "GAME.h"
#include"CONTAINER.h"
#include"TITLE.h"
#include"STAGE.h"
#include"SCORE.h"
#include"PLAYER.h"
#include"MAP.h"
#include"CHARA.h"
#include"ITEM.h"
#include"CHARACTOR_MANAGER.h"
#include"TRANSITION_FADE.h"
#include"CURSOR.h"
#include"PLAYERBULLETS.h"
#include"BOSSBULLETS.h"
#include"HEAL.h"
GAME::GAME() {
	Container = new CONTAINER;

	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[SCORE_ID] = new SCORE(this);
	charaManager = new CHARACTOR_MANAGER(this);


	Player = new PLAYER(this);
	Map = new MAP(this);
	Transition = new TRANSITION_FADE(this);
	Cursor = new CURSOR(this);
	PlayerBullets = new PLAYERBULLETS(this);
	BossBullets = new BOSSBULLETS(this);
	Heal = new HEAL(this);

}
GAME::~GAME() {
	delete Heal;
	delete Cursor;
	delete Transition;
	delete charaManager;
	delete Map;
	delete Player;
	delete PlayerBullets;
	delete BossBullets;
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
	
	delete Container;
}
void GAME::run() {
	window(1920, 1080, full);
	rectMode(CENTER);

	Container->load();
	Scenes[TITLE_ID]->create();

	Player->create();
	charaManager->create();
	Map->create();
	Transition->create();
	Cursor->create();
	PlayerBullets->create();
	BossBullets->create();
	Heal->create();


	CurSceneId = TITLE_ID;
	Scenes[CurSceneId]->init();
	initDeltaTime();
	while (notQuit) {
		setDeltaTime();
		Scenes[CurSceneId]->proc();
	}
}
void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
	Scenes[CurSceneId]->init();
}