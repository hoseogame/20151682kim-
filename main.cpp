#include "Football_Manager.h"


Singletone* Singletone::instance;







//Object - 부
//골대	 -
//공		  -
//플레이어 - 자

//Object Update Render 
//Obejct STL vector [] 
//STL vecotr [] = new 자식
// for() UPdate(); Render();

//class GOAL_DAE : private STAGE_INFO
//{
//private:
//	int nMoveX, nMoveY;     // 이동 좌표 
//	int nLength;			// 골대 길이	
//	int nLineX[7];			// 골인 라인 x 좌표 (7개)
//	clock_t	MoveTime;		// 이동 시간 간격
//	clock_t	OldTime;	    // 이전 이동 시간
//	int	nDist;				// 이동 거리
//	
//public:
//	void Init();
//	void update();
//
//	int GOAL_DAE::GetnMoveX()
//	{
//		return nMoveX;
//	}
//	int GOAL_DAE::GetnMoveY()
//	{
//		return nMoveY;
//	}
//	int GOAL_DAE::GetnLength()
//	{
//		return nLength;
//	}
//	int GOAL_DAE::GetnLineX(int _num)
//	{
//		return nLineX[_num];
//	}
//
//	int GOAL_DAE::SetnLineX(int _nLineX, int _num, int _nMoveX)
//	{
//		nLineX[_nLineX - _num] = _nMoveX;
//
//	}
//	int GOAL_DAE::SetnMoveX(int _nMoveX)
//	{
//		nMoveX += _nMoveX;
//	}
//	clock_t GOAL_DAE::GetMoveTime()
//	{
//		return MoveTime;
//	}
//	clock_t GOAL_DAE::GetOldTime()
//	{
//		return OldTime;
//	}
//	int GOAL_DAE::GetnDist()
//	{
//		return nDist;
//	}
//	clock_t GOAL_DAE::SetOldTime(clock_t _OldTime)
//	{
//		OldTime = _OldTime;
//	}
//	int GOAL_DAE::SetnDist(int _nDist)
//	{
//		nDist = _nDist;
//	}
//};
//
//void GOAL_DAE::Init() 
//{
//
//	nMoveX = g_sStageInfo[g_nStage].nGoalDaeX;
//	nMoveY = g_sStageInfo[g_nStage].nGoalDaeY;
//	nLength = g_sStageInfo[g_nStage].nGoalDaeLength;
//	MoveTime = g_sStageInfo[g_nStage].MoveTime;
//	OldTime = clock();
//	nDist = g_sStageInfo[g_nStage].nDist;
//	nLength = nLength * 2 + 1; // Note: 배열의 최대 길이
//
//	for (int i = 0; i < nLength; i++)
//	{
//		nLineX[i] = nMoveX + 2 * (i + 1);
//	}
//}
//
//void GOAL_DAE::update()
//{
//
//	clock_t CurTime = clock();
//	int nLength = nLength * 2 + 1; // Note: 배열의 최대 길이
//	int i;
//
//	if (CurTime - OldTime > MoveTime)
//	{
//		OldTime = CurTime;
//		if (nMoveX + nDist >= 2 && ((nLineX[nLength - 1] + 3) + nDist) <= 43)
//		{
//			nMoveX += nDist;
//			for (i = 0; i < nLength; i++)
//			{
//				nLineX[i] = nMoveX + 2 * (i + 1);
//			}
//		}
//		else {
//			nDist = nDist * -1; // -1 이 방향을 바꾸어 줌.
//		}
//	}
//}
//





//싱글톤 패턴 
/*
단 한개의 객체가 생성
전역 변수 돌아 갈 수 있다.
*/



int main(void)
{
	ScreenInit();

	FOOT_BALL_MANAGER* FBM = new FOOT_BALL_MANAGER();  // 초기화
	FBM->Init();
	
	FBM->Update();
	FBM->Render();
	FBM->Input();

	FBM->Release();
	
	delete FBM;
	// 해제
	ScreenRelease();
	return 0;
}
