#include "Goal_Dae.h"


void GOAL_DAE::Init()
{

	nMoveX = Singletone::GetInstance()->Getg_sStageInfo(Singletone::GetInstance()->Getg_nStage()).nGoalDaeX;
	nMoveY = Singletone::GetInstance()->Getg_sStageInfo(Singletone::GetInstance()->Getg_nStage()).nGoalDaeY;
	nLength = Singletone::GetInstance()->Getg_sStageInfo(Singletone::GetInstance()->Getg_nStage()).nGoalDaeLength;
	MoveTime = Singletone::GetInstance()->Getg_sStageInfo(Singletone::GetInstance()->Getg_nStage()).MoveTime;
	OldTime = clock();
	nDist = Singletone::GetInstance()->Getg_sStageInfo(Singletone::GetInstance()->Getg_nStage()).nDist;
	nLength = nLength * 2 + 1; // Note: 배열의 최대 길이

	for (int i = 0; i < nLength; i++)
	{
		nLineX[i] = nMoveX + 2 * (i + 1);
	}
}

void GOAL_DAE::update()
{

	clock_t CurTime = clock();
	int nLength = nLength * 2 + 1; // Note: 배열의 최대 길이
	int i;

	if (CurTime - OldTime > MoveTime)
	{
		OldTime = CurTime;
		if (nMoveX + nDist >= 2 && ((nLineX[nLength - 1] + 3) + nDist) <= 43)
		{
			nMoveX += nDist;
			for (i = 0; i < nLength; i++)
			{
				nLineX[i] = nMoveX + 2 * (i + 1);
			}
		}
		else {
			nDist = nDist * -1; // -1 이 방향을 바꾸어 줌.
		}
	}
}