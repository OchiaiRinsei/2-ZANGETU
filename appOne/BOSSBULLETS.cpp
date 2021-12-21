#include "BOSSBULLETS.h"
#include"CONTAINER.h"
#include"GAME.h"
BOSSBULLETS::BOSSBULLETS(class GAME* game) :
	BULLETS(game) {
}
void BOSSBULLETS::create() {
	SetBullets(game()->container()->data().bossBullets);
}