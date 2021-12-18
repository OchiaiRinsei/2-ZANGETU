#include "PLAYERBULLETS.h"
#include"CONTAINER.h"
#include"GAME.h"
PLAYERBULLETS::PLAYERBULLETS(class GAME* game) :
	BULLETS(game) {

}
void PLAYERBULLETS::create() {
	SetBullets(game()->container()->data().playerBullets);
}