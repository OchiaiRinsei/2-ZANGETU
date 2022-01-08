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
	if (Item.id == 1) {
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
