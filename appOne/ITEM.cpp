#include "ITEM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
ITEM::ITEM(GAME* game) :
	GAME_OBJECT(game){
}
void ITEM::create(){
}
void ITEM::init() {
}
void ITEM::update() {
}
int ITEM::effect() {
	return 0;
}
void ITEM::draw() {
	if (Item.id != 0&&Item.possession==0) {
		//判定確認用
		fill(0);
		stroke(5);
		circle(Item.px, Item.py, Item.radius * 2);
		//--------------------------------
		image(Item.img, Item.px, Item.py, 0, Item.scale);
	}
	//ウィンドウにアイテム表示
	if (Item.possession == 1 ) {
		image(Item.img, 1800, 960, 0, Item.scale*1.75);
	}
	//-------------------------------------------
}
void ITEM::hit() {
	VECTOR2 pPos = game()->player()->pos();
	float pRadius = game()->player()->radius();
	float distanceX = pPos.x - Item.px;
	float distanceY = pPos.y - Item.py;
	float c = sqrt(distanceX * distanceX + distanceY * distanceY);
	if (c <= pRadius + Item.radius) {
		Item.id = 0;
		Item.possession = 1;
	}
}
void ITEM::appear() {
}
void ITEM::setPos() {
	if(Item.firstSetPosFrag == 0){
		Item.px = random(70, 1850);
		Item.py = random(70, 1010);
		Item.firstSetPosFrag = 1;
	}
}