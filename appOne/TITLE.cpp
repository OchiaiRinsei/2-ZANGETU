#include "TITLE.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"libOne.h"
#include"TRANSITION.h"
#include"GAME.h"
TITLE::TITLE(class GAME*game) :
	SCENE(game){
}
TITLE::~TITLE() {
}
void TITLE::init() {
	game()->transition()->inTrigger();
}
void TITLE::create() {
	Title = game()->container()->data().title;
}
void TITLE::update() {
	game()->cursor()->update();
}
void TITLE::draw() {
	clear(0);
	rectMode(CENTER);

	image(Title.mainImg, Title.mainPos.x, Title.mainPos.y);
	image(Title.logoImg, Title.logoPos.x, Title.logoPos.y);
	////Šm”F—p
	fill(255);
	circle(Title.startPos.x, Title.startPos.y, Title.radius*2);
	circle(Title.scorePos.x, Title.scorePos.y, Title.radius*2);
	//--------------------------
	image(Title.startImg, Title.startPos.x, Title.startPos.y);
	image(Title.scoreImg, Title.scorePos.x, Title.scorePos.y);

	game()->cursor()->draw();


	game()->transition()->draw();
}
void TITLE::nextScene() {
	//Œã‚Éupdate‚©collisionŠÖ”ì‚Á‚Ä‚¤‚Â‚·‚©‚à‚»‚ÌÛ‚ÍFlag“™‚ÅŠÇ—‚·‚é-------------------------------
	float cRadius = game()->cursor()->radius();
	float cpx = game()->cursor()->px();
	float cpy = game()->cursor()->py();
	float distanceX = Title.startPos.x - cpx;
	float distanceY = Title.startPos.y - cpy;
	float c = sqrt(distanceX * distanceX + distanceY * distanceY);
	//------------------------------------------------------------------------------------------------
	if (isTrigger(MOUSE_LBUTTON)&&
	    c <= cRadius + Title.radius){
		game()->transition()->outTrigger();
		Title.ID = 1;
	}
	if (game()->transition()->outEndFlag()&&Title.ID == 1) {
		game()->changeScene(GAME::STAGE_ID);
	}
	//---------------------------------------------------------------------------------------------------
	distanceX = Title.scorePos.x - cpx;
	distanceY = Title.scorePos.y - cpy;
	c = sqrt(distanceX * distanceX + distanceY * distanceY);
	//-----------------------------------------------------------------------------------------------
	if (isTrigger(MOUSE_LBUTTON) &&
		c <= cRadius + Title.radius) {
		game()->transition()->outTrigger();
		Title.ID = 2;
	}
	if (game()->transition()->outEndFlag()&&Title.ID == 2) {
		game()->changeScene(GAME::SCORE_ID);
	}
}