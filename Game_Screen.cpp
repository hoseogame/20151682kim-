#include "Game_Screen.h"

	static void InitScreen()
	{
		ScreenPrint(0, 0, "����������������������������������������������");
		ScreenPrint(0, 1, "��                                          ��");
		ScreenPrint(0, 2, "��             �ব������                   ��");
		ScreenPrint(0, 3, "��                                          ��");
		ScreenPrint(0, 4, "��                        ///.   ��~~~      ��");
		ScreenPrint(0, 5, "��                       (^.^)              ��");
		ScreenPrint(0, 6, "��                      ���� ����           ��");
		ScreenPrint(0, 7, "��                         ����             ��");
		ScreenPrint(0, 8, "��                     ��  ����             ��");
		ScreenPrint(0, 9, "��                                          ��");
		ScreenPrint(0, 10, "��                                          ��");
		ScreenPrint(0, 11, "��       �� ���� ����  Go! Go!              ��");
		ScreenPrint(0, 12, "��                                          ��");
		ScreenPrint(0, 13, "��                                          ��");
		ScreenPrint(0, 14, "��       j :���� l : ������ k :��           ��");
		ScreenPrint(0, 15, "��                                          ��");
		ScreenPrint(0, 16, "��                                          ��");
		ScreenPrint(0, 17, "��                                          ��");
		ScreenPrint(0, 18, "��        ���ܦ�  space Ű�� �����ּ���     ��");
		ScreenPrint(0, 19, "��                                          ��");
		ScreenPrint(0, 20, "��                                          ��");
		ScreenPrint(0, 21, "��                                          ��");
		ScreenPrint(0, 22, "����������������������������������������������");
	}

	void ReadyScreen()
	{
		char string[100];

		ScreenPrint(0, 0, "����������������������������������������������");
		ScreenPrint(0, 1, "�����������������������᦭");
		ScreenPrint(0, 2, "�����������������������᦭");
		ScreenPrint(0, 3, "�����������������������᦭");
		ScreenPrint(0, 4, "�����������������������᦭");
		ScreenPrint(0, 5, "�����������������������᦭");
		ScreenPrint(0, 6, "�����������������������᦭");
		ScreenPrint(0, 7, "�����������������������᦭");
		ScreenPrint(0, 8, "�����������������������᦭");
		ScreenPrint(0, 9, "�����������������������᦭");
		ScreenPrint(0, 10, "��������                    ������᦭");
		sprintf(string, "��������     %d   ��������   ������᦭", Singletone::GetInstance()->Getg_nStage() + 1);
		ScreenPrint(0, 11, string);
		ScreenPrint(0, 12, "��������                    ������᦭");
		ScreenPrint(0, 13, "�����������������������᦭");
		ScreenPrint(0, 14, "�����������������������᦭");
		ScreenPrint(0, 15, "�����������������������᦭");
		ScreenPrint(0, 16, "�����������������������᦭");
		ScreenPrint(0, 17, "�����������������������᦭");
		ScreenPrint(0, 18, "�����������������������᦭");
		ScreenPrint(0, 19, "�����������������������᦭");
		ScreenPrint(0, 20, "�����������������������᦭");
		ScreenPrint(0, 21, "�����������������������᦭");
		ScreenPrint(0, 22, "�����������������������᦭");
		ScreenPrint(0, 23, "����������������������������������������������");
	}

	void BackScreen()
	{
		char string[100];

		ScreenPrint(0, 0, "����������������������������������������������");
		ScreenPrint(0, 1, "��                                          ��");
		ScreenPrint(0, 2, "��                                          ��");
		ScreenPrint(0, 3, "��                                          ��");
		sprintf(string, "��                                          ����������: %d", Singletone::GetInstance()->Getg_nStage() + 1);
		ScreenPrint(0, 4, string);
		ScreenPrint(0, 5, "��                                          ��");
		sprintf(string, "�������������������������������������������������� �ð�: %d", Singletone::GetInstance()->Getg_sStageInfo(Singletone::GetInstance()->Getg_nStage()).LimitTime / 1000);
		ScreenPrint(0, 6, string);
		ScreenPrint(0, 7, "��                                          ��");
		sprintf(string, "��                                          ������ �ð�: %d", (clock() - Singletone::GetInstance()->Getg_GameStartTime()) / 1000);
		ScreenPrint(0, 8, string);
		ScreenPrint(0, 9, "��                                          ��");
		sprintf(string, "��                                          ����ǥ ����: %d ", Singletone::GetInstance()->Getg_sStageInfo(Singletone::GetInstance()->Getg_nStage()).nGoalBall);
		ScreenPrint(0, 10, string);
		ScreenPrint(0, 11, "��                                          ��");
		sprintf(string, "��                                          ������ �� ����: %d ", Singletone::GetInstance()->Getg_nBallCount());
		ScreenPrint(0, 12, string);

		ScreenPrint(0, 13, "��                                          ��");
		sprintf(string, "��                                          ��");
		ScreenPrint(0, 14, string);
		ScreenPrint(0, 15, "��                                          ��");
		sprintf(string, "��                                          ��");
		ScreenPrint(0, 16, string);
		ScreenPrint(0, 17, "��                                          ��");
		ScreenPrint(0, 18, "��                                          ��");
		ScreenPrint(0, 19, "��                                          ��");
		ScreenPrint(0, 20, "��                                          ��");
		ScreenPrint(0, 21, "��                                          ��");
		ScreenPrint(0, 22, "��                                          ��");
		ScreenPrint(0, 23, "����������������������������������������������");
	}

	void GoalMessage(int nX, int nY)
	{
		ScreenPrint(nX, nY, "�� )) ���� (( ��");
		ScreenPrint(nX, nY + 1, "��(^^')/ ��(\"*')/");
		ScreenPrint(nX, nY + 2, "   ��       ��");
		ScreenPrint(nX, nY + 3, "  ����    ����");
	}

	void SuccessScreen()
	{
		ScreenPrint(0, 0, "����������������������������������������������");
		ScreenPrint(0, 1, "��                                          ��");
		ScreenPrint(0, 2, "��                                          ��");
		ScreenPrint(0, 3, "��                                          ��");
		ScreenPrint(0, 4, "��                                          ��");
		ScreenPrint(0, 5, "��                                          ��");
		ScreenPrint(0, 6, "��                ////����                  ��");
		ScreenPrint(0, 7, "��               q ��  �� p                 ��");
		ScreenPrint(0, 8, "��               (��������)                 ��");
		ScreenPrint(0, 9, "��             �� �̼� ���� ��              ��");
		ScreenPrint(0, 10, "��                                          ��");
		ScreenPrint(0, 11, "��                                          ��");
		ScreenPrint(0, 12, "��                                          ��");
		ScreenPrint(0, 13, "��                                          ��");
		ScreenPrint(0, 14, "��                                          ��");
		ScreenPrint(0, 15, "��                                          ��");
		ScreenPrint(0, 16, "��                                          ��");
		ScreenPrint(0, 17, "��                                          ��");
		ScreenPrint(0, 18, "��                                          ��");
		ScreenPrint(0, 19, "��                                          ��");
		ScreenPrint(0, 20, "��                                          ��");
		ScreenPrint(0, 21, "��                                          ��");
		ScreenPrint(0, 22, "��                                          ��");
		ScreenPrint(0, 23, "����������������������������������������������");
	}

	void FailureScreen()
	{
		ScreenPrint(0, 0, "����������������������������������������������");
		ScreenPrint(0, 1, "��                                          ��");
		ScreenPrint(0, 2, "��                                          ��");
		ScreenPrint(0, 3, "��                                          ��");
		ScreenPrint(0, 4, "��                                          ��");
		ScreenPrint(0, 5, "��                                          ��");
		ScreenPrint(0, 6, "��                                          ��");
		ScreenPrint(0, 7, "��                                          ��");
		ScreenPrint(0, 8, "��                                          ��");
		ScreenPrint(0, 9, "��                                          ��");
		ScreenPrint(0, 10, "��                                          ��");
		ScreenPrint(0, 11, "��                    �̼� ���� !!!!        ��");
		ScreenPrint(0, 12, "��                                          ��");
		ScreenPrint(0, 13, "��                                          ��");
		ScreenPrint(0, 14, "��                 �ܦ�����                 ��");
		ScreenPrint(0, 15, "��                   ��  ��                 ��");
		ScreenPrint(0, 16, "��                  �����                ��");
		ScreenPrint(0, 17, "��                                          ��");
		ScreenPrint(0, 18, "��        �ٽ� �Ͻðڽ��ϱ�? (y/n)          ��");
		ScreenPrint(0, 19, "��                                          ��");
		ScreenPrint(0, 20, "��                                          ��");
		ScreenPrint(0, 21, "��                                          ��");
		ScreenPrint(0, 22, "����������������������������������������������");
	}

	void ResultScreen()
	{
		char string[100];
		ScreenPrint(0, 0, "����������������������������������������������");
		ScreenPrint(0, 1, "��                                          ��");
		ScreenPrint(0, 2, "��                                          ��");
		ScreenPrint(0, 3, "��             �ব������                   ��");
		ScreenPrint(0, 4, "��                                          ��");
		ScreenPrint(0, 5, "��                                          ��");
		ScreenPrint(0, 6, "��                                          ��");
		ScreenPrint(0, 7, "��                                          ��");
		sprintf(string, "��      ������ �������� :  %2d               ��", Singletone::GetInstance()->Getg_nStage() + 1);
		ScreenPrint(0, 8, string);
		ScreenPrint(0, 9, "��                                          ��");
		ScreenPrint(0, 10, "��                                          ��");
		ScreenPrint(0, 11, "��   ___�ƢƢ�___                           ��");
		ScreenPrint(0, 12, "��     (*^  ^*)                             ��");
		ScreenPrint(0, 13, "�� =====��==��=====                         ��");
		ScreenPrint(0, 14, "��                                          ��");
		ScreenPrint(0, 15, "��                                          ��");
		ScreenPrint(0, 16, "��                                          ��");
		ScreenPrint(0, 17, "��                                          ��");
		ScreenPrint(0, 18, "��                      ���ܦ�              ��");
		ScreenPrint(0, 19, "��                                          ��");
		ScreenPrint(0, 20, "��                                          ��");
		ScreenPrint(0, 21, "��                                          ��");
		ScreenPrint(0, 22, "����������������������������������������������");
	}
