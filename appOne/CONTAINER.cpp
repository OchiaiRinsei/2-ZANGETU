#include "CONTAINER.h"
void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	Data.title.mainPos = VECTOR2(width/2, height/2);
	Data.title.logoPos = VECTOR2(width / 2-50, height / 2 - 200);
	Data.title.startPos = VECTOR2(400, 700);
	Data.title.scorePos = VECTOR2(1600, 700);
	Data.title.radius = 150;

	Data.player.pos.x = width / 2;
	Data.player.pos.y = height / 2;
	Data.player.vec.x = 0;
	Data.player.vec.y = 0;
	Data.player.adsSpeed = 500;
	Data.player.scale = 0.15f;
	//Data.player.hp = 10;
	Data.player.radius = 70;
	Data.player.ofsLaunchDist = 70;
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 0.15f;
 
	Data.playerBullets.totalNum = 20;
	Data.playerBullets.curNum = 0;
	Data.playerBullets.advSpeed = 800;
	Data.playerBullets.angSpeed = 5;
	Data.playerBullets.radius = 20;

	Data.bossBullets.totalNum = 20;
	Data.bossBullets.curNum = 0;
	Data.bossBullets.advSpeed = 800;
	Data.bossBullets.angSpeed = 0;
	Data.bossBullets.radius = 20;


	Data.map.pos.x = width / 2;
	Data.map.pos.y = height / 2;
	//Data.map.scale = 3.0f;
	Data.map.scale = 1.0f;
	Data.map.AlimmitX = 0;
	Data.map.DlimmitX = 1920;
	Data.map.WlimmitY = 0;
	Data.map.SlimmitY = 1080;



	Data.charaBoss1.px = width/2;
	Data.charaBoss1.py = height/2;
	Data.charaBoss1.vx = 0;
	Data.charaBoss1.vy = 0;
	Data.charaBoss1.speed = 300.0f;
	Data.charaBoss1.scale = 0.15f;
	Data.charaBoss1.hp = 30;
	Data.charaBoss1.radius = 60;

	Data.boss1.theta = 0;
	Data.boss1.rollDistance = 300;
	Data.boss1.triggerInterval = 0.2f;
	Data.boss1.ofsLaunchDist = 50;
	Data.boss1.triggerErapsedTime = -3.0f;

	Data.cursor.px = MouseX;
	Data.cursor.py = MouseY;
	Data.cursor.scale = 0.15f;
	Data.cursor.radius = 50;

}
void CONTAINER::loadGraphic() {
	Data.title.mainImg = loadImage("assets\\main.png");
	Data.title.logoImg = loadImage("assets\\logo.png");
	Data.title.startImg = loadImage("assets\\start.png");
	Data.title.scoreImg = loadImage("assets\\score.png");

	Data.player.img = loadImage("assets\\player.png");
	Data.map.img = loadImage("assets\\map.png");
	Data.charaBoss1.img = loadImage("assets\\boss1.png");
	Data.cursor.img = loadImage("assets\\target.png");
	Data.playerBullets.img = loadImage("assets\\playerBullet.png");
	Data.bossBullets.img = loadImage("assets\\bossBullet.png");
}
//ìñÇΩÇËîªíËä÷êî
int CONTAINER::hit(VECTOR2 pos1,VECTOR2 pos2,float radius1,float radius2,int damage) {
	float distanceX = pos2.x - pos1.x;
	float distanceY = pos2.y - pos2.y;
	float c = sqrt(distanceX * distanceX + distanceY * distanceY);
	if (c <= radius1 + radius2) {
		return damage;
	}
	else return 0;
}