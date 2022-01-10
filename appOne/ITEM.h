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
		int id;//�A�C�e�����Ƃ̔ԍ�
		int through;//�o�������邩�ǂ���
		int firstSetPosFrag;
		int firstAppearFrag;
		int possession;//�������
		int durability;//�ϋv�l
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

