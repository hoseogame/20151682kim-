#include "Football_Manager.h"


Singletone* Singletone::instance;







//Object - ��
//���	 -
//��		  -
//�÷��̾� - ��

//Object Update Render 
//Obejct STL vector [] 
//STL vecotr [] = new �ڽ�
// for() UPdate(); Render();

//class GOAL_DAE : private STAGE_INFO
//{
//private:
//	int nMoveX, nMoveY;     // �̵� ��ǥ 
//	int nLength;			// ��� ����	
//	int nLineX[7];			// ���� ���� x ��ǥ (7��)
//	clock_t	MoveTime;		// �̵� �ð� ����
//	clock_t	OldTime;	    // ���� �̵� �ð�
//	int	nDist;				// �̵� �Ÿ�
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
//	nLength = nLength * 2 + 1; // Note: �迭�� �ִ� ����
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
//	int nLength = nLength * 2 + 1; // Note: �迭�� �ִ� ����
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
//			nDist = nDist * -1; // -1 �� ������ �ٲپ� ��.
//		}
//	}
//}
//





//�̱��� ���� 
/*
�� �Ѱ��� ��ü�� ����
���� ���� ���� �� �� �ִ�.
*/



int main(void)
{
	ScreenInit();

	FOOT_BALL_MANAGER* FBM = new FOOT_BALL_MANAGER();  // �ʱ�ȭ
	FBM->Init();
	
	FBM->Update();
	FBM->Render();
	FBM->Input();

	FBM->Release();
	
	delete FBM;
	// ����
	ScreenRelease();
	return 0;
}
