#include "CURSOR.h"
#include"GAME.h"
#include"CONTAINER.h"
CURSOR::CURSOR(class GAME* game) :
	GAME_OBJECT(game){
}
void CURSOR::create() {
Cursor = game()->container()->data().cursor;
}
void CURSOR::init() {

}
void CURSOR::update() {
	Cursor.px = mouseX;
	Cursor.py = mouseY;
}
void CURSOR::draw() {
	fill(0);
	circle(Cursor.px, Cursor.py, Cursor.radius*2);
	image(Cursor.img, Cursor.px, Cursor.py, 0, Cursor.scale);
}