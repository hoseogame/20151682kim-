#include <string>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "Ball.h"
#include "Player.h"
#include "Goal_Dae.h"
#include  "Effect.h"

#include "Game_Screen.h"
#include "Stage_Info.h"


class FOOT_BALL_MANAGER
{
private:
	GOAL_DAE *g_sGoalDae;
	BALL *g_sBall;
	PLAYER *g_sPlayer;
	EFFECT *g_sEffect;

	clock_t CurTime = clock();
	int nLength = nLength * 2 + 1; // Note: 배열의 최대 길이

public:
	void Init();
	void Update();
	void Render();
	void Input();
	void Release();

};