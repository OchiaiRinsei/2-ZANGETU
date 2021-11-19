#include "MAP.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER.h"
MAP::MAP(GAME* game) :
	GAME_OBJECT(game) {
}
void MAP::create() {
	Map = game()->container()->data().map;
}
void MAP::update() {
	VECTOR2 v = game()->player()->vec();
	if (isPress(KEY_W)) {v.y = 1; }
	if (isPress(KEY_S)) {v.y = -1; }
	if (isPress(KEY_A)) {v.x = 1; }
	if (isPress(KEY_D)) {v.x = -1; }

	Map.pos.x += v.x * 500 * delta;
	Map.pos.y += v.y * 500 * delta;
	v.x = 0;
	v.y = 0;
	 
	//§ŒÀ
	if (Map.pos.x > width*2-width/2) {
		Map.pos.x = width*2-width/2;
	}
	if (Map.pos.x < -width+width/2) {
		Map.pos.x = -width+width/2;
	}
	if (Map.pos.y > height*2-height/2) {
		Map.pos.y = height*2-height/2;
	}
	if (Map.pos.y < -height+height/2) {
		Map.pos.y = -height+height/2;
	}
}
void MAP::draw() {
	image(Map.img, Map.pos.x, Map.pos.y, 0, Map.scale);
}