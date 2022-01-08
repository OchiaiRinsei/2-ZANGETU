#pragma once
class GAME
{
//�R���e�i
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
//�}�b�v
private:
	class MAP* Map;
public:
	class MAP* map() { return Map; }
//�J�[�\��
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

//�L�����N�^�[
private:
	class GAME* Game = nullptr;
	class PLAYER* Player = nullptr;
	class CHARACTOR_MANAGER* charaManager = nullptr;
	class TRANSITION* Transition = nullptr;
	class PLAYERBULLETS* PlayerBullets = nullptr;
	class BOSSBULLETS* BossBullets = nullptr;
	class HEAL* Heal = nullptr;
public:
	class GAME* game() { return Game; }
	class PLAYER* player() { return Player; }
	class PLAYERBULLETS* playerBullets() { return PlayerBullets; }
	class BOSSBULLETS* bossBullets() { return BossBullets; }
	
	class CHARACTOR_MANAGER* charactorManager() { return charaManager; }
	class TRANSITION* transition() { return Transition; }

	class HEAL* heal() { return Heal; }
public:
	GAME();
	~GAME();
	void run();
};

