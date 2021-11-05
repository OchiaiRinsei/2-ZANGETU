#include"libOne.h"
#include "GAME.h"
#include"TITLE.h"
#include"STAGE.h"
#include"SCORE.h"
GAME::GAME() {
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[SCORE_ID] = new SCORE(this);
}
GAME::~GAME() {
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
}
void GAME::run() {
	window(1920, 1080, full);
	initDeltaTime();
	CurSceneId = TITLE_ID;
	while (notQuit) {
		setDeltaTime();
		Scenes[CurSceneId]->proc();
	}
}
void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
}