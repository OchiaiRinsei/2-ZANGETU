#pragma once
#include "TITLE.h"
#include"PLAYER.h"
#include"MAP.h"
#include"BOSS.h"
#include"BOSS1.h"
class CONTAINER{
	struct DATA {
		TITLE::DATA title;
		PLAYER::DATA player;
		MAP::DATA map;
	    BOSS::DATA bossBoss1;
		BOSS1::DATA boss1;
	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();
	const DATA& data() { return Data; }
};

