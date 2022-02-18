#include "PENETRATE.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"ITEM.h"
void PENETRATE::create() {
	Item = game()->container()->data().itemPenetrate;
	Penetrate = game()->container()->data().penetrate;
}
void PENETRATE::init() {
	Item.durability = game()->container()->data().itemPenetrate.durability;
	Item.firstAppearFrag = 0;
	Item.firstSetPosFrag = 0;
	Item.possession = 0;
	Penetrate.CompletionTime = 0;
}
void PENETRATE::update() {
	appear();
	if (Item.id == 1) {
		setPos();
		draw();
		hit();
	}
}
void PENETRATE::appear() {
	if (game()->player()->itemId() == 3) {
		Item.id = 1;
	}
	else Item.id = 0;
}
int PENETRATE::effect() {
	if (game()->player()->buffBullet()) {
		Penetrate.nowProgressTime += 1.0 * delta;
		if (Item.durability == 0) {
			Item.possession = 0;
			Item.durability = game()->container()->data().itemPenetrate.durability;
			return 2;
		}
		if (Penetrate.nowProgressTime >= Penetrate.CompletionTime) {
			Item.durability--;
			Penetrate.nowProgressTime = 0;
			return 1;
		}
	}
	return 0;
}

