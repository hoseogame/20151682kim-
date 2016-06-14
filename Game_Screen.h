#include "Stage_Info.h"
#include <string>
#include "Screen.h"
class SCREEN
{
public:
	static void InitScreen();
	void ReadyScreen();
	void BackScreen();
	void GoalMessage(int nX, int nY);
	void SuccessScreen();
	void FailureScreen();
	void ResultScreen();

};