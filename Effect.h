#include <time.h>


class EFFECT
{
private:
	clock_t StartTime; // 효과 발생 시각
	clock_t StayTime;  // 효과 지속 시간	
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
	