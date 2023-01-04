#include "Counter.h"

void Counter::Increment()
{
	Increment(1);
}

void Counter::Increment(int sec)
{
	m_sec += sec;
	m_min = (m_min * c_max_sec + m_sec) / c_max_sec;
	m_hou = (m_hou * c_max_min + m_min) / c_max_min;
	m_min %= c_max_min;
	m_sec = m_sec % c_max_sec;
}

int Counter::GetSec() const
{
	return m_sec;
}

int Counter::GetMin() const
{
	return m_min;
}

int Counter::GetHou() const
{
	return m_hou;
}