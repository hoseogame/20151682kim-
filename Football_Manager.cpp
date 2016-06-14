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
	// 공의 초기화
	g_sBall->Init();
	// 골대 초기화
	g_sGoalDae->Init();
	g_sEffect->Init();

	// 효과 
	// 2초 설정


	Singletone::GetInstance()->Setg_nGoal(0);      // 스테이지 완료 변수
	Singletone::GetInstance()->Setg_UpdateOldTime(clock());
	Singletone::GetInstance()->Setg_nBallCount(0);  // 골인한 공의 개수


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
		if (CurTime - Singletone::GetInstance()->Getg_UpdateOldTime() > 2000)  // 2초
		{
			Singletone::GetInstance()->Setg_GameState(RUNNING);
			Singletone::GetInstance()->Setg_GameStartTime(CurTime);


		}
		break;
	case RUNNING:
		if (CurTime - Singletone::GetInstance()->Getg_GameStartTime() > Singletone::GetInstance()->Getg_LimitTime()) // Note: 제한 시간
		{
			Singletone::GetInstance()->Setg_GameState(STOP);
			return;
		}
		else {
			// Note: 골대
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
					gd.SetnDist(gd.GetnDist() * -1); // -1 이 방향을 바꾸어 줌.
				}
			}

			if (b.GetnIsReady() == 0) // 이동 중일 때 
			{	// 이동 시간 간격에 의한 이동
				if ((CurTime - b.GetOldTime()) > b.GetMoveTime())
				{
					if (b.GetnMoveY() - 1 > 0)
					{
						b.SetnMoveY(b.GetnMoveY() - 1);
						b.SetOldTime(CurTime); // 다음 이동 시각과 비교하기 위해 현재 시간을 이전 시간 변수에 저장

						// 골대 라인 충돌
						if (b.GetnMoveX() >= gd.GetnLineX(0) && b.GetnMoveX() + 1 <= gd.GetnLineX(nLength - 1) + 1)
						{
							if (b.GetnMoveY() <= gd.GetnMoveY())
							{   // 공 초기화
								b.SetnIsReady(1);
								b.SetnMoveX(p.GetnMoveX());
								b.SetnMoveY(p.GetnMoveY() - 1);
								Singletone::GetInstance()->Setg_nBallCount(1);  // 골인한 공의 개수										

								if (Singletone::GetInstance()->Getg_nBallCount() == Singletone::GetInstance()->Getg_nGoalBallCount()) // 공과 목표 공과의 개수가 같으면 SUCCESS
								{
									Singletone::GetInstance()->Setg_GameState(STOP);
									Singletone::GetInstance()->Setg_nGoal(1);
									return;
								}

								// 효과 출력
								if (Singletone::GetInstance()->Getg_nIsGoal() == 0)
								{
									Singletone::GetInstance()->Setg_nIsGoal(1);
									e.SetStartTime(CurTime);
								}

								// 골인 사운드 출력

							}
							// 골대 충돌 
						}
						else if ((b.GetnMoveX() >= gd.GetnLineX(0) - 2 && b.GetnMoveX() <= gd.GetnLineX(0) - 1) ||
							(b.GetnMoveX() + 1 >= gd.GetnLineX(0) - 2 && b.GetnMoveX() + 1 <= gd.GetnLineX(0) - 1) ||
							(b.GetnMoveX() >= gd.GetnLineX(nLength - 1) + 2 && b.GetnMoveX() <= gd.GetnLineX(nLength - 1) + 3) ||
							(b.GetnMoveX() + 1 >= gd.GetnLineX(nLength - 1) + 2 && b.GetnMoveX() + 1 <= gd.GetnLineX(nLength - 1) + 3))
						{
							if (b.GetnMoveY() <= gd.GetnMoveY())
							{   // 공 초기화
								b.SetnIsReady(1);
								b.SetnMoveX(p.GetnMoveX());
								b.SetnMoveY(p.GetnMoveY() - 1);
							}
						}
					}
					else { // 공 초기화
						b.SetnIsReady(1);
						b.SetnMoveX(p.GetnMoveX());
						b.SetnMoveY(p.GetnMoveY() - 1);
					}
				}
			}
			else {
				b.SetnMoveX(p.GetnMoveX());
			}

			// 효과 
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
		ScreenPrint(gd.GetnMoveX(), gd.GetnMoveY(), "□");
		nLength = gd.GetnLength() * 2 + 1;

		for (i = 0; i < nLength; i++)
			ScreenPrint(gd.GetnLineX(i), gd.GetnMoveY(), "━");

		ScreenPrint(gd.GetnLineX(nLength - 1) + 2, gd.GetnMoveY(), "□");

		// Note: 효과 출력  	
		if (Singletone::GetInstance()->Getg_nIsGoal() == 1)
		{
			scr.GoalMessage(10, 10);
		}

		// Note: 2 컬럼씩 클리핑 
		if (p.GetnX() < 2)  //  왼쪽 클리핑 처리
			ScreenPrint(2, p.GetnMoveY(), (char*)p.Getplayer_str((p.GetnX() - 2)*-1));	 // 좌표를 배열 인덱스 
		else if (p.GetnMoveX() + (Singletone::GetInstance()->Getg_nLength() - g_sPlayer->GetnCenterX() + 1) > 43) // 오른쪽 클리핑 처리
		{
			strncat(string, (char*)p.player_str(), Singletone::GetInstance()->Getg_nLength() - ((p.GetnMoveX() + p.GetnCenterX() + 1) - 43));
			ScreenPrint(p.GetnX(), p.GetnMoveY(), string);
		}
		else { // 1 컬럼씩 이동
			ScreenPrint(p.GetnX(), p.GetnMoveY(), (char*)p.player_str());
		}

		ScreenPrint(b.GetnMoveX(), b.GetnMoveY(), "⊙");
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

	// Note: 렌더링 끝 
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
				if (p.GetnMoveX() > 2) // 왼쪽 충돌 경계 좌표 체크
				{
					p.SetnMoveXmin(1);
					nRemain = Singletone::GetInstance()->Getg_nLength() - p.GetnCenterX() + 1; // 전체 길이 - ( 중심 좌표 + 1 )은 남은 길이
					// Note: 2컬럼씩 이동하기 위한 부분 ( 팔이 걸친 경우 ) 
					if (p.GetnMoveX() - p.GetnCenterX() < 2 || p.GetnMoveX() + nRemain > 43)
						p.SetnMoveXmin(1);

					p.SetnX(p.GetnMoveX(), p.GetnCenterX());
				}
				break;
			case 'l':
				if (p.GetnMoveX() + 1 < 43) // 오른쪽 충돌 경계 좌표 체크
				{
					p.SetnMoveXplus(1);
					nRemain = Singletone::GetInstance()->Getg_nLength() - p.GetnCenterX() + 1; // 전체 길이 - ( 중심 좌표 + 1 )은 남은 길이
					// Note: 2컬럼씩 이동하기 위한 부분 ( 팔이 걸친 경우 )
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
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5]); // 슛 동작 소리 출력
				}
				break;

			case 'y':
			case 'Y':
				if (Singletone::GetInstance()->Setg_GameState(FAILED))
				{
					FBM.Init();
					Singletone::GetInstance()->Setg_GameState(READY);
					//FMOD_Channel_Stop( g_Channel[2] );  // 미션 실패 사운드 출력 중지 
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]);
				}
				break;
			case 'n':
			case 'N':
				if (Singletone::GetInstance()->Setg_GameState(FAILED))
				{
					Singletone::GetInstance()->Setg_GameState(RESULT);
					//FMOD_Channel_Stop( g_Channel[2] );  // 미션 실패 사운드 출력 중지							
				}
				break;

			case ' ':
				if (Singletone::GetInstance()->Getg_GameState() == INIT && Singletone::GetInstance()->Getg_nStage() == 0)
				{
					Singletone::GetInstance()->Setg_GameState(READY);
					Singletone::GetInstance()->Setg_UpdateOldTime(clock());  // ready를 일정시간 지속해 주기 위해 							
				}
				break;
			}
		}

		FBM.Update();    // 데이터 갱신
		FBM.Render();    // 화면 출력

	}



}
