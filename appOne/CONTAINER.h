#pragma once
#include "TITLE.h"
#include"PLAYER.h"
#include"MAP.h"
#include"CHARA.h"
#include"BOSS1.h"
#include"BOSS2.h"
#include"BOSS3.h"
#include"ITEM.h"
#include"HEAL.h"
#include"CURSOR.h"
#include"BULLETS.h"
#include"PLAYERBULLETS.h"
#include"BOSSBULLETS.h"
class CONTAINER{
	struct DATA {
		TITLE::DATA title;
		//CHARA::DATA charaPlayer;
		PLAYER::DATA player;
		MAP::DATA map;
	    CHARA::DATA charaBoss1;
		CHARA::DATA charaBoss2;
		CHARA::DATA charaBoss3;
		BOSS1::DATA boss1;
		BOSS2::DATA boss2;
		BOSS3::DATA boss3;
		ITEM::DATA itemHeal;
		HEAL::DATA heal;

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

