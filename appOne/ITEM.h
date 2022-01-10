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
		int id;//アイテムごとの番号
		int through;//出現させるかどうか
		int firstSetPosFrag;
		int firstAppearFrag;
		int possession;//所持状態
		int durability;//耐久値
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
	virtual int effect();
	int possession() { return Item.possession; }
};

