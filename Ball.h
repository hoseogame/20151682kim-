#pragma once
#include <time.h>
#include "Player.h"

class BALL 
{
private:
	int nIsReady;        // �غ� ����(1), ������(0)
	int nMoveX, nMoveY; // �̵� ��ǥ
	clock_t MoveTime;    // �̵� �ð� ����
	clock_t OldTime;     // ���� �̵� �ð�

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