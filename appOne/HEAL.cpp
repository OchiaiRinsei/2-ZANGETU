#include "HEAL.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"ITEM.h"
void HEAL::create() {
	Item = game()->container()->data().itemHeal;
	Heal = game()->container()->data().heal;
}
void HEAL::update() {
	appear();
	if (Item.id == 1 ) {
		setPos();
		draw();
		hit();
	}
}

void HEAL::appear(){
	int itemId = game()->player()->appearItem();
	if (itemId == 1) {
		Item.id = 1;
	}
}
int HEAL::effect() {
	Heal.nowProgressTime += 1.0 * delta;
	if (Heal.nowProgressTime >= Heal.CompletionTime ) {
		Item.durability--;
		Heal.nowProgressTime = 0;
		return 1;
	}
	if (Item.durability == 0) {
		Item.possession = 0;
		Item.durability = 2;
		return 2;
	}
	return 0;
}
