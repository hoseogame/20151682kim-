#pragma once
#include <time.h>
#include "Player.h"

class BALL 
{
private:
	int nIsReady;        // 준비 상태(1), 슛상태(0)
	int nMoveX, nMoveY; // 이동 좌표
	clock_t MoveTime;    // 이동 시간 간격
	clock_t OldTime;     // 이전 이동 시각

public:

	void Init();


	int BALL::GetnIsReady()
	{
		return nIsReady;
	}
	int BALL::GetnMoveX()
	{
		return nMoveX;
	}
	int BALL::GetnMoveY()
	{
		return nMoveY;
	}
	clock_t BALL::GetMoveTime()
	{
		return MoveTime;
	}
	clock_t BALL::GetOldTime()
	{
		return OldTime;
	}
	clock_t BALL::SetOldTime(clock_t _OldTime)
	{
		OldTime = _OldTime;
		return _OldTime;
	}
	int BALL::SetnIsReady(int _nIsReady)
	{
		nIsReady = _nIsReady;
		return _nIsReady;
	}
	int BALL::SetnMoveX(int _nMoveX)
	{
		nMoveX = _nMoveX;
		return _nMoveX;
	}
	int BALL::SetnMoveY(int _nMoveY)
	{
		nMoveY = _nMoveY;
		return _nMoveY;
	}
};