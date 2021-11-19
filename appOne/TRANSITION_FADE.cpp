#include "TRANSITION_FADE.h"
TRANSITION_FADE::TRANSITION_FADE(class GAME* game) :
	TRANSITION(game) {
}
void TRANSITION_FADE::create() {
	colorMode(RGB, 255);
	Transition.color = COLOR(0, 0, 0);
	Transition.time = 1.7f;
}
void TRANSITION_FADE::inTriggerProc() {
	rectMode(CORNER);
	colorMode(RGB, 255);
	noStroke();
	Transition.color.a = 255;
	fill(Transition.color);
	rect(0, 0, width, height);
}
bool TRANSITION_FADE::inProc() {
	rectMode(CORNER);
	colorMode(RGB, 255);
	noStroke();
	fill(Transition.color);
	rect(0, 0, width, height);
	Transition.color.a -= 255 / Transition.time * delta;
	if (Transition.color.a < 0.0f) {
		return true;
	}
	return false;
}
void TRANSITION_FADE::outtriggerProc() {
	Transition.color.a = 0.0f;
}
bool TRANSITION_FADE::outProc() {
	rectMode(CORNER);
	colorMode(RGB, 255);
	noStroke();
	fill(Transition.color);
	rect(0, 0, width, height);
	Transition.color.a += 255 / Transition.time * delta;
	if (Transition.color.a >= 255) {
		return true;
	}
	return false;
}