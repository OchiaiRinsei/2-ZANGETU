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

	Data.map.pos.x = width / 2;
	Data.map.pos.y = height / 2;
	//Data.map.scale = 3.0f;
	Data.map.scale = 1.0f;
	Data.map.AlimmitX = 0;
	Data.map.DlimmitX = 1920;
	Data.map.WlimmitY = 0;
	Data.map.SlimmitY = 1080;

	Data.cursor.px = MouseX;
	Data.cursor.py = MouseY;
	Data.cursor.scale = 0.15f;
	Data.cursor.radius = 50;

	Data.player.pos.x = width / 2;
	Data.player.pos.y = height / 2;
	Data.player.vec.x = 0;
	Data.player.vec.y = 0;
	Data.player.adsSpeed = 500;
	Data.player.angle = 0;
	Data.player.scale = 0.6f;
	Data.player.hp = 1000;
	Data.player.radius = 70;
	Data.player.ofsLaunchDist = 70;
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 0.25f;
	Data.player.itemId = 0;
	Data.player.firstItemFrag = 0;
	Data.player.invincibility = 0;
	
 
	Data.playerBullets.totalNum = 20;
	Data.playerBullets.curNum = 0;
	Data.playerBullets.advSpeed = 800;
	Data.playerBullets.angSpeed = 5;
	Data.playerBullets.radius = 20;
	Data.playerBullets.damage = 1;

	Data.bossBullets.totalNum = 20;
	Data.bossBullets.curNum = 0;
	Data.bossBullets.advSpeed = 800;
	Data.bossBullets.angSpeed = 0;
	Data.bossBullets.radius = 20;
	Data.bossBullets.damage = 10;


	



	Data.charaBoss1.px = width/2;
	Data.charaBoss1.py = height/2;
	Data.charaBoss1.vx = 0;
	Data.charaBoss1.vy = 0;
	Data.charaBoss1.speed = 0;
	Data.charaBoss1.scale = 0.5f;
	Data.charaBoss1.hp = 500;
	Data.charaBoss1.radius = 60;

	Data.boss1.theta = 0;
	Data.boss1.rollDistance = 300;
	Data.boss1.triggerInterval = 0.3f;
	Data.boss1.ofsLaunchDist = 50;
	Data.boss1.triggerErapsedTime = -3.0f;

	Data.charaBoss2.px = width / 2;
	Data.charaBoss2.py = height / 2;
	Data.charaBoss2.vx = 0;
	Data.charaBoss2.vy = 0;
	Data.charaBoss2.speed = 0;
	Data.charaBoss2.scale = 1.0f;
	Data.charaBoss2.hp = 1500;
	Data.charaBoss2.radius = 120;

	Data.boss2.theta = 0;
	Data.boss2.triggerInterval = 0.01f;
	Data.boss2.ofsLaunchDist = 100;
	Data.boss2.triggerErapsedTime = -1.5f;

	Data.charaBoss3.px = 0;
	Data.charaBoss3.py = 0 ;
	Data.charaBoss3.vx = 0;
	Data.charaBoss3.vy = 0;
	Data.charaBoss3.speed = 25.0f;
	Data.charaBoss3.scale = 1.0f;
	Data.charaBoss3.hp = 400;
	Data.charaBoss3.radius = 120;

	Data.boss3.theta = 0;
	Data.boss3.triggerInterval = 0.2f;
	Data.boss3.ofsLaunchDist = 100;
	Data.boss3.triggerErapsedTime = -3.0f;

	Data.boss3.angle = 0;
	Data.boss3.RotSpeed = 0;
	//Data.boss3.Vel=VECTOR2(0,0);
	//Data.boss3.Acc=VECTOR2(0,0);
	//Data.boss3.V= VECTOR2(0,0);
	Data.boss3.MaxSpeed = 15.0f;
	Data.boss3.MaxForce = 1.5f;
	Data.boss3.NearDistance = 200.0f;

	Data.itemHeal.px = 0;
	Data.itemHeal.py = 0;
	Data.itemHeal.radius = 40;
	Data.itemHeal.scale = 0.07f;
	Data.itemHeal.id = 0;
	Data.itemHeal.through = 0;
	Data.itemHeal.firstSetPosFrag = 0;
	Data.itemHeal.firstAppearFrag = 0;
	Data.itemHeal.possession = 0;
	Data.itemHeal.durability = 2;
	
	Data.heal.CompletionTime = 4.0f;
	Data.heal.nowProgressTime = 0;
	Data.heal.healAmount = 250;


	Data.itemBarrier.px = 0;
	Data.itemBarrier.py = 0;
	Data.itemBarrier.radius = 40;
	Data.itemBarrier.scale = 0.07f;
	Data.itemBarrier.id = 0;
	Data.itemBarrier.through = 0;
	Data.itemBarrier.firstSetPosFrag = 0;
	Data.itemBarrier.firstAppearFrag = 0;
	Data.itemBarrier.possession = 0;
	Data.itemBarrier.durability = 1;

	Data.barrier.CompletionTime = 7.0f;
	Data.barrier.nowProgressTime = 0;
	Data.barrier.invincibility = 0;

}
void CONTAINER::loadGraphic() {
	Data.title.mainImg = loadImage("assets\\main.png");
	Data.title.logoImg = loadImage("assets\\logo.png");
	Data.title.startImg = loadImage("assets\\start.png");
	Data.title.scoreImg = loadImage("assets\\score.png");

	Data.player.sImg = loadImage("assets\\playerS.png");//�k
	Data.player.nImg = loadImage("assets\\playerN.png");//��
	Data.player.eImg = loadImage("assets\\playerE.png");//��
	Data.player.wImg = loadImage("assets\\playerW.png");//��
	Data.player.img = Data.player.sImg;
	Data.map.img = loadImage("assets\\map.png");
	Data.charaBoss1.img = loadImage("assets\\boss1.png");
	Data.charaBoss2.img = loadImage("assets\\boss2.png");
	Data.charaBoss3.img = loadImage("assets\\boss3.png");
	Data.cursor.img = loadImage("assets\\target.png");
	Data.playerBullets.img = loadImage("assets\\playerBullet.png");
	Data.bossBullets.img = loadImage("assets\\bossBullet.png");
	Data.itemHeal.img = loadImage("assets\\heal.jpg");
	Data.itemBarrier.img = loadImage("assets\\barrier.jpg");
}