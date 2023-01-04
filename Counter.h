#pragma once
class Counter
{
public:
	void Increment();
	void Increment(int sec);
	Counter() :Counter(0, 0, 0) {};
	Counter(int hou, int min, int sec) : m_hou(hou), m_min(min), m_sec(sec) {};
	int GetSec() const;
	int GetMin() const;
	int GetHou() const;
private:
	int m_sec;
	int m_min;
	int m_hou;

	static const int c_max_sec = 60;
	static const int c_max_min = 60;
};

