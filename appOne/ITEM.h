#pragma once
#include"GAME_OBJECT.h"
class ITEM :
	public GAME_OBJECT
{
public:
	struct DATA {
		int img;
		float px;
		float py;
		float scale;
		float radius;
		int id;
		int itemId;
		int firstSetPosFrag;
		int firstAppearFrag;
	};
protected:
	DATA Item;
public:
	ITEM(class GAME* game);
	virtual void create();
	virtual void init();
	virtual void update();
	virtual void draw();
	virtual void appear();
	virtual void hit();
	virtual void setPos();
};

