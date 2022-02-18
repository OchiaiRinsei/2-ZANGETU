#include "BARRIER.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"ITEM.h"
void BARRIER::create() {
	Item = game()->container()->data().itemBarrier;
	Barrier = game()->container()->data().barrier;
}
void BARRIER::init() {
	Item.durability = game()->container()->data().itemBarrier.durability;
	Item.firstAppearFrag = 0;
	Item.firstSetPosFrag = 0;
	Item.possession = 0;
	Barrier.nowProgressTime = 0;
}
void BARRIER::update() {
	appear();
	if (Item.id == 1) {
		setPos();
		draw();
		hit();
	}
}
void BARRIER::draw() {
	if (Item.possession&& game()->player()->invincibility()) {
		EffectDraw();
	}
	if (Item.id != 0&&Item.possession==0) {
		//判定確認用
		fill(0);
		stroke(5);
		circle(Item.px, Item.py, Item.radius * 2);
		//--------------------------------
		image(Item.img, Item.px, Item.py, 0, Item.scale);
	}
	//ウィンドウにアイテム表示
	if (Item.possession == 1) {
		image(Item.img, 1800, 960, 0, Item.scale * 1.7f);
	}
	//-------------------------------------------
}
void BARRIER::appear() {
	if (game()->player()->itemId() == 2) {
		Item.id = 1;
	}
	else Item.id = 0;
}
int BARRIER::effect() {
	if (game()->player()->invincibility()) {
		Barrier.nowProgressTime += 1.0 * delta;
		if (Barrier.nowProgressTime >= Barrier.CompletionTime) {
			Item.durability--;
			Barrier.nowProgressTime = 0;
			return 0;
		}
		if (Item.durability == 0) {
			Item.possession = 0;
			Item.durability = game()->container()->data().itemBarrier.durability;
			return 1;
		}
	}
	return 0;
}
void BARRIER::EffectDraw() {
	VECTOR2 pPos = game()->player()->pos();
	image(Item.img, pPos.x, pPos.y, 0, 1.0f);
}

