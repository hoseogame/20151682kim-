#include "Player.h"

PLAYER::PLAYER() : 
nCenterX(4), nCenterY(0), nMoveX(20), nMoveY(22), nX(nMoveX - nCenterX), g_strPlayer("¦±¦¬¡Ü¦¬¦°")
{}

void PLAYER::Init()
{
	nCenterX = 4;
	nCenterY = 0;
	nMoveX = 20;
	nMoveY = 22;
	nX = nMoveX - nCenterX;
}