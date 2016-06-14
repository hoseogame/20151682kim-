#include "Ball.h"

void BALL::Init()
{
	PLAYER p;
	nIsReady = 1;
	nMoveX = p.GetnMoveX();
	nMoveY = p.GetnMoveY() - 1;
	MoveTime = 100;
}

