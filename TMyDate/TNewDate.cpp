#include "TNewDate.h"

TNewDate::TNewDate()
{
	m_weekDay = CaculateWeekDay(m_year, m_month, m_day);
	m_isWorkDay = JudgeWorkDayByWeekDay();
}

TNewDate::TNewDate(int y, int m, int d) : TMyDate(y, m, d)
{
	m_weekDay = CaculateWeekDay(m_year, m_month, m_day);
	m_isWorkDay = JudgeWorkDayByWeekDay();
}

int TNewDate::CaculateWeekDay(int y, int m, int d)
{
	if (m == 1 || m == 2)
	{
		m += 12;
		y--;
	}
	int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
	return iWeek + 1;
}

int TNewDate::getWeekDayNumber()
{
	return m_weekDay;
}

string TNewDate::getWeekDay()
{
	switch (m_weekDay)
	{
	case 1:return "一"; break;
	case 2:return "二"; break;
	case 3:return "三"; break;
	case 4:return "四"; break;
	case 5:return "五"; break;
	case 6:return "六"; break;
	case 7:return "日"; break;
	}
}

bool TNewDate::isWorkDay()
{
	if (m_isWorkDay)
		return true;
	return false;
}

bool TNewDate::JudgeWorkDayByWeekDay()
{
	if (getWeekDayNumber() == 6 || getWeekDayNumber() == 7)
		return false;
	return true;
}

void TNewDate::setWorkDay(bool x)
{
	m_isWorkDay = x;
}

TMyDate& TNewDate::nextDay()
{
	TMyDate::nextDay();
	if (m_weekDay == 7)
		m_weekDay = 1;
	else
		m_weekDay++;
	m_isWorkDay = JudgeWorkDayByWeekDay();
	return *this;
}

TMyDate& TNewDate::frontDay()
{
	TMyDate::frontDay();
	if (m_weekDay == 1)
		m_weekDay = 7;
	else
		m_weekDay--;
	m_isWorkDay = JudgeWorkDayByWeekDay();
	return *this;
}

TMyDate& TNewDate::Increase(int days)
{
	for (int i = 0; i < days; i++)
	{
		nextDay();
	}
	return *this;
}

TMyDate& TNewDate::Decrease(int days)
{
	for (int i = 0; i < days; i++)
	{
		nextDay();
	}
	return *this;
}

ostream& operator<<(ostream& out, TNewDate& tnd)
{
	out << tnd.getYear() << "年" << tnd.getMonth() << "月" << tnd.getDay() << "日" << "  星期" << tnd.getWeekDay();
	return out;
}

bool operator==(TNewDate& tnd1, TNewDate& tnd2)
{
	if (tnd1.getYear() == tnd2.getYear() && tnd1.getMonth() == tnd2.getMonth() && tnd1.getDay() == tnd2.getDay())
		return true;
	else
		return false;
}