#pragma once
#include <string.h>
#include <time.h>
#include "Stage_Info.h"


class GOAL_DAE
{
private:
	int nMoveX, nMoveY;     // �̵� ��ǥ 
	int nLength;			// ��� ����	
	int nLineX[7];			// ���� ���� x ��ǥ (7��)
	clock_t	MoveTime;		// �̵� �ð� ����
	clock_t	OldTime;	    // ���� �̵� �ð�
	int	nDist;				// �̵� �Ÿ�

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