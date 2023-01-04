#include <iostream>
#include <chrono> 
#include "Counter.h"

using namespace std;

uint64_t timeSinceEpochMillisec()
{
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int main()
{
	bool flag = true;
	Counter cnt;
	time_t const updateTime = 1000;
	auto start = timeSinceEpochMillisec();
	for (int i = 0; i < 1000;)
	{
		auto curTime = timeSinceEpochMillisec();
		auto spendTime = curTime - start;
		
		if (flag && spendTime % updateTime == 0)
		{
			if (i && i % 5 == 0)
			{
				system("cls");
			}
			flag = false;
			cnt.Increment();
			cout << cnt.GetHou() << " : " << cnt.GetMin() << " : " << cnt.GetSec() << endl;
			i++;
		}
		else if (spendTime % updateTime)
		{
			flag = true;
		}
	}
}