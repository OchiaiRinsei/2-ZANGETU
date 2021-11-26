#include"libOne.h"
#include "GAME.h"
#include"CONTAINER.h"
#include"TITLE.h"
#include"STAGE.h"
#include"SCORE.h"
#include"PLAYER.h"
#include"MAP.h"
#include"BOSS.h"
#include"BOSS1.h"
#include"BOSS_MANAGER.h"
#include"TRANSITION_FADE.h"
GAME::GAME() {
	Container = new CONTAINER;

	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[SCORE_ID] = new SCORE(this);
	BossManager = new BOSS_MANAGER(this);


	Player = new PLAYER(this);
	Map = new MAP(this);
	Transition = new TRANSITION_FADE(this);
}
GAME::~GAME() {
	delete Transition;
	delete BossManager;
	delete Map;
	delete Player;
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
	BossManager->create();
	Map->create();
	Transition->create();

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