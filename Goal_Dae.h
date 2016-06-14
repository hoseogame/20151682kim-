#pragma once
#include <string.h>
#include <time.h>
#include "Stage_Info.h"


class GOAL_DAE
{
private:
	int nMoveX, nMoveY;     // 이동 좌표 
	int nLength;			// 골대 길이	
	int nLineX[7];			// 골인 라인 x 좌표 (7개)
	clock_t	MoveTime;		// 이동 시간 간격
	clock_t	OldTime;	    // 이전 이동 시간
	int	nDist;				// 이동 거리

public:
	void Init();
	void update();

	int GOAL_DAE::GetnMoveX()
	{
		return nMoveX;
	}
	int GOAL_DAE::GetnMoveY()
	{
		return nMoveY;
	}
	int GOAL_DAE::GetnLength()
	{
		return nLength;
	}
	int GOAL_DAE::GetnLineX(int _num)
	{
		return nLineX[_num];
	}

	int GOAL_DAE::SetnLineX(int _nLineX, int _num, int _nMoveX)
	{
		nLineX[_nLineX - _num] = _nMoveX;
		return _nMoveX;

	}
	int GOAL_DAE::SetnMoveX(int _nMoveX)
	{
		nMoveX += _nMoveX;
		return _nMoveX;
	}
	clock_t GOAL_DAE::GetMoveTime()
	{
		return MoveTime;
	}
	clock_t GOAL_DAE::GetOldTime()
	{
		return OldTime;
	}
	int GOAL_DAE::GetnDist()
	{
		return nDist;
	}
	clock_t GOAL_DAE::SetOldTime(clock_t _OldTime)
	{
		OldTime = _OldTime;
		return _OldTime;
	}
	int GOAL_DAE::SetnDist(int _nDist)
	{
		nDist = _nDist;
		return _nDist;
	}
};