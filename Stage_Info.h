#pragma once
#include <string.h>
#include <time.h>

typedef enum GAME_STATE { INIT, READY, RUNNING, STOP, SUCCESS, FAILED, RESULT };

struct STAGE_INFO
{
	int nGoalBall;			// °ñÀÎÇØ¾ß ÇÒ º¼ÀÇ °³¼ö 
	clock_t LimitTime;      // Á¦ÇÑ ½Ã°£ 
	int nGoalDaeLength;		// °ñ´ë ±æÀÌ 
	int nGoalDaeX;			// °ñ´ë ÀÌµ¿ X ÁÂÇ¥
	int nGoalDaeY;			// °ñ´ë ÀÌµ¿ Y ÁÂÇ¥ 
	clock_t MoveTime;		// °ñ´ë ÀÌµ¿ ½Ã°£ °£°Ý
	int nDist;				// °ñ´ë ÀÌµ¿ °Å¸®
};

class Singletone
{
private:
	STAGE_INFO g_sStageInfo[2];
	int g_nLength, g_nGoal, g_nBallCount, g_nGoalBallCount, g_nStage = -1, g_nIsGoal;
	clock_t g_LimitTime, g_GameStartTime, g_UpdateOldTime;
	GAME_STATE g_GameState = INIT;

	Singletone(){};
	static Singletone* instance;
public:
	static Singletone* GetInstance()
	{
		
		if (!instance)
		{
			instance = new Singletone();

			instance->g_sStageInfo[0] = { 3, 1000 * 20, 1, 20, 3, 300, 1 };
			instance->g_sStageInfo[1] = { 10, 1000 * 30, 2, 20, 5, 300, 1 };
		}
		return instance;
	}

	STAGE_INFO Getg_sStageInfo(int index)
	{
		return g_sStageInfo[index];
	}

	int Getg_nLength()
	{
		return g_nLength;
	}

	int Setg_nLength(int _g_nLength)
	{
		g_nLength = _g_nLength;
		return _g_nLength;
	}
	
	int Getg_nGoal()
	{
		return g_nGoal;
	}

	int Setg_nGoal(int _g_nGoal)
	{
		g_nGoal = _g_nGoal;
		return _g_nGoal;
	}

	int Getg_nBallCount()
	{
		return g_nBallCount;
	}

	int Setg_nBallCount(int _g_nBallCount)
	{
		g_nBallCount += _g_nBallCount;
		return _g_nBallCount;
	}

	int Getg_nGoalBallCount()
	{
		return g_nGoalBallCount;
	}

	int Getg_nStage()
	{
		return g_nStage;
	}

	
	int Setg_nStage(int _g_nStage)
	{
		g_nStage += _g_nStage;
		return _g_nStage;
	}

	int Getg_nIsGoal()
	{
		return g_nIsGoal;
	}
	
	int Setg_nIsGoal(int _g_nIsGoal)
	{
		g_nIsGoal = _g_nIsGoal;
		return _g_nIsGoal;
	}

	clock_t Getg_LimitTime()
	{
		return g_LimitTime;
	}

	clock_t Getg_GameStartTime()
	{
		return g_GameStartTime;
	}

	clock_t Setg_GameStartTime(clock_t _g_GameStartTime)
	{
		g_GameStartTime = _g_GameStartTime;
		return _g_GameStartTime;
	}

	clock_t Getg_UpdateOldTime()
	{
		return g_UpdateOldTime;
	}

	clock_t Setg_UpdateOldTime(clock_t _g_UpdateOldTime)
	{
		g_UpdateOldTime = _g_UpdateOldTime;
		return _g_UpdateOldTime;
	}

	GAME_STATE Getg_GameState()
	{
		return g_GameState;
	}

	GAME_STATE Setg_GameState(GAME_STATE _g_GameState)
	{
		g_GameState = _g_GameState;
		return _g_GameState;
	}
};
