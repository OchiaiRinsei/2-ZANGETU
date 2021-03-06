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
//カーソル
private:
	class CURSOR* Cursor;
public:
	class CURSOR* cursor() { return Cursor; }
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
	class CHARACTOR_MANAGER* charaManager = nullptr;
	class TRANSITION* Transition = nullptr;
	class PLAYERBULLETS* PlayerBullets = nullptr;
	class BOSSBULLETS* BossBullets = nullptr;
	class HEAL* Heal = nullptr;
	class BARRIER* Barrier = nullptr;
	class PENETRATE* Penetrate = nullptr;
public:
	class GAME* game() { return Game; }
	class PLAYER* player() { return Player; }
	class PLAYERBULLETS* playerBullets() { return PlayerBullets; }
	class BOSSBULLETS* bossBullets() { return BossBullets; }
	
	class CHARACTOR_MANAGER* charactorManager() { return charaManager; }
	class TRANSITION* transition() { return Transition; }

	class HEAL* heal() { return Heal; }
	class BARRIER* barrier() { return Barrier; }
	class PENETRATE* penetrate() { return Penetrate; }
public:
	GAME();
	~GAME();
	void run();
};

