#include <time.h>


class EFFECT
{
private:
	clock_t StartTime; // ȿ�� �߻� �ð�
	clock_t StayTime;  // ȿ�� ���� �ð�	
public:
	void Init();
	void update();
	clock_t EFFECT::GetStartTime()
	{
		return StartTime;
	}
	clock_t EFFECT::SetStartTime(clock_t _StartTime)
	{
		StartTime = _StartTime;
		return _StartTime;
	}
	clock_t EFFECT::GetStayTime()
	{
		return StayTime;
	}
};

\
	