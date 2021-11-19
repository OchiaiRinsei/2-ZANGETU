#pragma once
class GAME
{
//コンテナ
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//マップ
private:
	class MAP* Map;
public:
	class MAP* map() { return Map; }
//SCENE
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		SCORE_ID,
		NUM_SCENES
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
public:
	void changeScene(SCENE_ID sceneId);

//キャラクター
private:
	class GAME* Game = nullptr;
	class PLAYER* Player = nullptr;
	class BOSS_MANAGER* BossManager = nullptr;
	class TRANSITION* Transition = nullptr;

public:
	class PLAYER* player() { return Player; }
	class GAME* game() { return Game; }

	class BOSS_MANAGER* bossManager() { return BossManager; }
	class TRANSITION* transition() { return Transition; }

public:
	GAME();
	~GAME();
	void run();
};

