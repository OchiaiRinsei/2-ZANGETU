#pragma once
#include "TITLE.h"
#include"PLAYER.h"
#include"MAP.h"
#include"CHARA.h"
#include"BOSS1.h"
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
		BOSS1::DATA boss1;
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
	//
	int hit(VECTOR2 pos1, VECTOR2 pos2, float radius1, float radius2,int damage);
};

