#include "BARRIER.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"ITEM.h"
void BARRIER::create() {
	Item = game()->container()->data().itemBarrier;
	Heal = game()->container()->data().barrier;
}
void BARRIER::update() {
	appear();
	if (Item.id == 1) {
		setPos();
		draw();
		hit();
	}
}

void BARRIER::appear() {
	int itemId = game()->player()->appearItem();
	if (itemId == 2) {
		Item.id = 1;
	}
}
