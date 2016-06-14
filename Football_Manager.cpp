#include "Football_Manager.h"



void FOOT_BALL_MANAGER::Init()
{
	int nLength, i;

	if (Singletone::GetInstance()->Getg_nStage() == -1)
	{
		g_sGoalDae = new GOAL_DAE();
		g_sBall = new BALL();
		g_sPlayer = new PLAYER();
		g_sEffect = new EFFECT();

		Singletone::GetInstance()->Setg_nStage(0);
	}

	//g_sPlayer->Init();
	Singletone::GetInstance()->Setg_nLength(g_sPlayer->player_str());
	// ���� �ʱ�ȭ
	g_sBall->Init();
	// ��� �ʱ�ȭ
	g_sGoalDae->Init();
	g_sEffect->Init();

	// ȿ�� 
	// 2�� ����


	Singletone::GetInstance()->Setg_nGoal(0);      // �������� �Ϸ� ����
	Singletone::GetInstance()->Setg_UpdateOldTime(clock());
	Singletone::GetInstance()->Setg_nBallCount(0);  // ������ ���� ����


}
void FOOT_BALL_MANAGER::Update()
{
	PLAYER p;
	BALL b;
	GOAL_DAE gd;
	EFFECT e;



	switch (Singletone::GetInstance()->Getg_GameState())
	{
	case READY:
		if (CurTime - Singletone::GetInstance()->Getg_UpdateOldTime() > 2000)  // 2��
		{
			Singletone::GetInstance()->Setg_GameState(RUNNING);
			Singletone::GetInstance()->Setg_GameStartTime(CurTime);


		}
		break;
	case RUNNING:
		if (CurTime - Singletone::GetInstance()->Getg_GameStartTime() > Singletone::GetInstance()->Getg_LimitTime()) // Note: ���� �ð�
		{
			Singletone::GetInstance()->Setg_GameState(STOP);
			return;
		}
		else {
			// Note: ���
			if (CurTime - gd.GetOldTime() > gd.GetMoveTime())
			{
				gd.SetOldTime(CurTime);
				if (gd.GetnMoveX() + gd.GetnDist() >= 2 && ((gd.GetnLineX(nLength - 1) + 3) + gd.GetnDist()) <= 43)
				{
					gd.SetnMoveX(gd.GetnDist());
					for (int i = 0; i < nLength; i++)
					{
						gd.SetnLineX(i, 0, gd.GetnMoveX() + 2 * (i + 1));
					}
				}
				else {
					gd.SetnDist(gd.GetnDist() * -1); // -1 �� ������ �ٲپ� ��.
				}
			}

			if (b.GetnIsReady() == 0) // �̵� ���� �� 
			{	// �̵� �ð� ���ݿ� ���� �̵�
				if ((CurTime - b.GetOldTime()) > b.GetMoveTime())
				{
					if (b.GetnMoveY() - 1 > 0)
					{
						b.SetnMoveY(b.GetnMoveY() - 1);
						b.SetOldTime(CurTime); // ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����

						// ��� ���� �浹
						if (b.GetnMoveX() >= gd.GetnLineX(0) && b.GetnMoveX() + 1 <= gd.GetnLineX(nLength - 1) + 1)
						{
							if (b.GetnMoveY() <= gd.GetnMoveY())
							{   // �� �ʱ�ȭ
								b.SetnIsReady(1);
								b.SetnMoveX(p.GetnMoveX());
								b.SetnMoveY(p.GetnMoveY() - 1);
								Singletone::GetInstance()->Setg_nBallCount(1);  // ������ ���� ����										

								if (Singletone::GetInstance()->Getg_nBallCount() == Singletone::GetInstance()->Getg_nGoalBallCount()) // ���� ��ǥ ������ ������ ������ SUCCESS
								{
									Singletone::GetInstance()->Setg_GameState(STOP);
									Singletone::GetInstance()->Setg_nGoal(1);
									return;
								}

								// ȿ�� ���
								if (Singletone::GetInstance()->Getg_nIsGoal() == 0)
								{
									Singletone::GetInstance()->Setg_nIsGoal(1);
									e.SetStartTime(CurTime);
								}

								// ���� ���� ���

							}
							// ��� �浹 
						}
						else if ((b.GetnMoveX() >= gd.GetnLineX(0) - 2 && b.GetnMoveX() <= gd.GetnLineX(0) - 1) ||
							(b.GetnMoveX() + 1 >= gd.GetnLineX(0) - 2 && b.GetnMoveX() + 1 <= gd.GetnLineX(0) - 1) ||
							(b.GetnMoveX() >= gd.GetnLineX(nLength - 1) + 2 && b.GetnMoveX() <= gd.GetnLineX(nLength - 1) + 3) ||
							(b.GetnMoveX() + 1 >= gd.GetnLineX(nLength - 1) + 2 && b.GetnMoveX() + 1 <= gd.GetnLineX(nLength - 1) + 3))
						{
							if (b.GetnMoveY() <= gd.GetnMoveY())
							{   // �� �ʱ�ȭ
								b.SetnIsReady(1);
								b.SetnMoveX(p.GetnMoveX());
								b.SetnMoveY(p.GetnMoveY() - 1);
							}
						}
					}
					else { // �� �ʱ�ȭ
						b.SetnIsReady(1);
						b.SetnMoveX(p.GetnMoveX());
						b.SetnMoveY(p.GetnMoveY() - 1);
					}
				}
			}
			else {
				b.SetnMoveX(p.GetnMoveX());
			}

			// ȿ�� 
			if (Singletone::GetInstance()->Getg_nIsGoal() == 1)
			{
				if (CurTime - e.GetStartTime() > e.GetStayTime())
					Singletone::GetInstance()->Setg_nIsGoal(0);
			}
		}
		break;
	case STOP:
		if (Singletone::GetInstance()->Getg_nGoal() == 1)
		{
			Singletone::GetInstance()->Setg_GameState(SUCCESS);
			Singletone::GetInstance()->Setg_UpdateOldTime(CurTime);



		}
		else {
			Singletone::GetInstance()->Setg_GameState(FAILED);

		}
		break;
	case SUCCESS:
		if (CurTime - Singletone::GetInstance()->Getg_UpdateOldTime() > 3000)
		{
			Singletone::GetInstance()->Setg_UpdateOldTime(CurTime);
			Singletone::GetInstance()->Setg_nStage(1);
			Init();
			Singletone::GetInstance()->Setg_GameState(READY);
		}
		break;
	}
}
void FOOT_BALL_MANAGER::Render()
{
	SCREEN scr;
	PLAYER p;
	BALL b;
	GOAL_DAE gd;

	char string[100] = { 0, };
	int nLength, i;

	ScreenClear();

	switch (Singletone::GetInstance()->Getg_GameState())
	{
	case INIT:
		if (Singletone::GetInstance()->Getg_nStage() == 0)
			scr.InitScreen();
		break;
	case READY:
		scr.ReadyScreen();

		break;
	case RUNNING:
		scr.BackScreen();
		ScreenPrint(gd.GetnMoveX(), gd.GetnMoveY(), "��");
		nLength = gd.GetnLength() * 2 + 1;

		for (i = 0; i < nLength; i++)
			ScreenPrint(gd.GetnLineX(i), gd.GetnMoveY(), "��");

		ScreenPrint(gd.GetnLineX(nLength - 1) + 2, gd.GetnMoveY(), "��");

		// Note: ȿ�� ���  	
		if (Singletone::GetInstance()->Getg_nIsGoal() == 1)
		{
			scr.GoalMessage(10, 10);
		}

		// Note: 2 �÷��� Ŭ���� 
		if (p.GetnX() < 2)  //  ���� Ŭ���� ó��
			ScreenPrint(2, p.GetnMoveY(), (char*)p.Getplayer_str((p.GetnX() - 2)*-1));	 // ��ǥ�� �迭 �ε��� 
		else if (p.GetnMoveX() + (Singletone::GetInstance()->Getg_nLength() - g_sPlayer->GetnCenterX() + 1) > 43) // ������ Ŭ���� ó��
		{
			strncat(string, (char*)p.player_str(), Singletone::GetInstance()->Getg_nLength() - ((p.GetnMoveX() + p.GetnCenterX() + 1) - 43));
			ScreenPrint(p.GetnX(), p.GetnMoveY(), string);
		}
		else { // 1 �÷��� �̵�
			ScreenPrint(p.GetnX(), p.GetnMoveY(), (char*)p.player_str());
		}

		ScreenPrint(b.GetnMoveX(), b.GetnMoveY(), "��");
		break;
	case SUCCESS:
		scr.SuccessScreen();
		break;
	case FAILED:
		scr.FailureScreen();
		break;
	case RESULT:
		scr.ResultScreen();
		break;
	}

	// Note: ������ �� 
	ScreenFlipping();
}

void FOOT_BALL_MANAGER::Input()
{

	PLAYER p;
	BALL b;
	GOAL_DAE gd;
	FOOT_BALL_MANAGER FBM;

	int nKey, nRemain;


	while (1)
	{
		if (_kbhit())
		{
			if (Singletone::GetInstance()->Setg_GameState(RESULT))
				break;

			nKey = _getch();

			switch (nKey)
			{
			case 'j':
				if (p.GetnMoveX() > 2) // ���� �浹 ��� ��ǥ üũ
				{
					p.SetnMoveXmin(1);
					nRemain = Singletone::GetInstance()->Getg_nLength() - p.GetnCenterX() + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
					// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� ) 
					if (p.GetnMoveX() - p.GetnCenterX() < 2 || p.GetnMoveX() + nRemain > 43)
						p.SetnMoveXmin(1);

					p.SetnX(p.GetnMoveX(), p.GetnCenterX());
				}
				break;
			case 'l':
				if (p.GetnMoveX() + 1 < 43) // ������ �浹 ��� ��ǥ üũ
				{
					p.SetnMoveXplus(1);
					nRemain = Singletone::GetInstance()->Getg_nLength() - p.GetnCenterX() + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
					// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� )
					if (p.GetnMoveX() + nRemain > 43 || (p.GetnMoveX() - p.GetnCenterX() < 2))
						p.SetnMoveXplus(1);

					p.SetnX(p.GetnMoveX(), p.GetnCenterX());
				}
				break;
			case 'k':
				if (b.GetnIsReady() && Singletone::GetInstance()->Setg_GameState(RUNNING))
				{
					b.SetnMoveX(p.GetnMoveX());
					b.SetnMoveY(p.GetnMoveY() - 1);
					b.SetOldTime(clock());
					b.SetnIsReady(0);
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5]); // �� ���� �Ҹ� ���
				}
				break;

			case 'y':
			case 'Y':
				if (Singletone::GetInstance()->Setg_GameState(FAILED))
				{
					FBM.Init();
					Singletone::GetInstance()->Setg_GameState(READY);
					//FMOD_Channel_Stop( g_Channel[2] );  // �̼� ���� ���� ��� ���� 
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]);
				}
				break;
			case 'n':
			case 'N':
				if (Singletone::GetInstance()->Setg_GameState(FAILED))
				{
					Singletone::GetInstance()->Setg_GameState(RESULT);
					//FMOD_Channel_Stop( g_Channel[2] );  // �̼� ���� ���� ��� ����							
				}
				break;

			case ' ':
				if (Singletone::GetInstance()->Getg_GameState() == INIT && Singletone::GetInstance()->Getg_nStage() == 0)
				{
					Singletone::GetInstance()->Setg_GameState(READY);
					Singletone::GetInstance()->Setg_UpdateOldTime(clock());  // ready�� �����ð� ������ �ֱ� ���� 							
				}
				break;
			}
		}

		FBM.Update();    // ������ ����
		FBM.Render();    // ȭ�� ���

	}



}
