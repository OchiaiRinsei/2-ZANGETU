#include "CONTAINER.h"
void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	Data.title.pos = VECTOR2(0, 0);

	Data.player.pos = VECTOR2(width / 2, height / 2 + 300);
	Data.player.adsSpeed = 500.0f;
	Data.player.vec = VECTOR2(0, 0);
	Data.player.scale = 0.15f;

	Data.map.pos.x = width / 2;
	Data.map.pos.y = height / 2;
	Data.map.scale = 3.0f;
	Data.map.AlimmitX = 0;
	Data.map.DlimmitX = 1920;
	Data.map.WlimmitY = 0;
	Data.map.SlimmitY = 1080;

	//Data.boss1.pos = VECTOR2(width / 2, height / 2 - 300);
	//Data.boss1.adsSpeed = 300.0f;
	//Data.boss1.vec = VECTOR2(0, 0);
	//Data.boss1.scale = 0.15f;

	Data.bossBoss1.px = width / 2;
	Data.bossBoss1.py = height / 2 - 300;
	Data.bossBoss1.vx = 0;
	Data.bossBoss1.vy = 0;
	Data.bossBoss1.speed = 300.0f;
	Data.bossBoss1.scale = 0.15f;
	Data.bossBoss1.hp = 30;

	Data.cursor.px = MouseX;
	Data.cursor.py = MouseY;
	Data.cursor.scale = 1;
}
void CONTAINER::loadGraphic() {
	Data.title.mainImg = loadImage("assets\\main.png");
	Data.player.img = loadImage("assets\\player.png");
	Data.map.img = loadImage("assets\\map.png");
	Data.bossBoss1.img = loadImage("assets\\boss1.png");
	Data.cursor.img = loadImage("assets\\OIP.JPG");
}
