#pragma once
#include "TITLE.h"
#include"PLAYER.h"
#include"MAP.h"
#include"CHARA.h"
#include"BOSS1.h"
#include"BOSS2.h"
#include"BOSS3.h"
#include"BOSS_RHAND.h"
#include"BOSS_LHAND.h"
#include"ITEM.h"
#include"HEAL.h"
#include"BARRIER.h"
#include"PENETRATE.h"
#include"CURSOR.h"
#include"BULLETS.h"
#include"PLAYERBULLETS.h"
#include"BOSSBULLETS.h"
class CONTAINER{
	struct DATA {
		TITLE::DATA title;
		PLAYER::DATA player;
		MAP::DATA map;
	    CHARA::DATA charaBoss1;
		CHARA::DATA charaBoss2;
		CHARA::DATA charaBoss3;
		CHARA::DATA charaBossRHand;
		CHARA::DATA charaBossLHand;
		BOSS1::DATA boss1;
		BOSS2::DATA boss2;
		BOSS3::DATA boss3;
		BOSS_RHAND::DATA bossRHand;
		BOSS_LHAND::DATA bossLHand;
		ITEM::DATA itemHeal;
		ITEM::DATA itemBarrier;
		ITEM::DATA itemPenetrate;
		HEAL::DATA heal;
		BARRIER::DATA barrier;
		PENETRATE::DATA penetrate;

		CURSOR::DATA cursor;
		BULLETS::DATA playerBullets;
		BULLETS::DATA bossBullets;
	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();
	const DATA& data() { return Data; }
};

