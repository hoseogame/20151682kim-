#include "Effect.h"
#include "Stage_Info.h"

void EFFECT::Init()
{
	StayTime = 2000;
}

void EFFECT::update()
{
	clock_t CurTime = clock();
	

	if (Singletone::GetInstance()->Getg_nIsGoal()== 0)
	{
		Singletone::GetInstance()->Setg_nIsGoal(1);
		StartTime = CurTime;
	}
}


