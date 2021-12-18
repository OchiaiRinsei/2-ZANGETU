#include"GAME.h"
#include"CHARA.h"
#include "BOSS1.h"
#include"CONTAINER.h"
void BOSS1::create() {
	Chara = game()->container()->data().charaBoss1;
	Boss1 = game()->container()->data().boss1;
}
void BOSS1::update() {
	Move();
}
void BOSS1::Move() {
	Chara.px = game()->container()->data().charaBoss1.px;
	Chara.py = game()->container()->data().charaBoss1.py;
	Boss1.theta += 0.03333;
	Chara.px = Chara.px +cos(Boss1.theta) * Boss1.rollDistance + sin(Boss1.theta)*Boss1.rollDistance;
	Chara.py = Chara.py -sin(Boss1.theta) * Boss1.rollDistance + cos(Boss1.theta)*Boss1.rollDistance;
	
}
void BOSS1::damage() {
}