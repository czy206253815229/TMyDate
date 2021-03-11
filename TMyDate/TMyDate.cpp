#include "TMyDate.h"

int leapYearMonth[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int normalYearMonth[] = { 0 ,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

TMyDate::TMyDate() : m_year(1901), m_month(1), m_day(1)
{
}

TMyDate::TMyDate(int year, int month, int day) : m_year(year), m_month(month), m_day(day)
{
}

int TMyDate::getYear()
{
	return m_year;
}

int TMyDate::getMonth()
{
	return m_month;
}

int TMyDate::getDay()
{
	return m_day;
}

TMyDate& TMyDate::nextDay()
{
	//每年最后一天时
	if (m_day == 31 && m_month == 12)
	{
		m_year++;
		m_month = 1;
		m_day = 1;
		return *this;
	}
	//每月最后一天时
	if ((isLeap(m_year) && m_day == leapYearMonth[m_month]) ||
		!isLeap(m_year) && m_day == normalYearMonth[m_month])
	{
			m_month++;
			m_day = 1;
			return *this;
	}
	//不是年或月的最后一天时
	m_day++;
	return *this;
}

TMyDate& TMyDate::frontDay()
{
	//每年第一天时
	if (m_day == 1 && m_month == 1)
	{
		m_year--;
		m_month = 12;
		m_day = 31;
		return *this;
	}
	//每月第一天时
	if (m_day == 1)
	{
		m_month--;
		m_day = isLeap(m_year) ? leapYearMonth[m_month] : normalYearMonth[m_month];
		return *this;
	}
	//不是年或月的第一天时
	m_day--;
	return *this;
}

TMyDate& TMyDate::Increase(int days)
{
	for (int i = 0; i < days; i++)
	{
		nextDay();
	}
	return *this;
}

TMyDate& TMyDate::Decrease(int days)
{
	
	for (int i = 0; i < days; i++)
	{
		frontDay();
	}
	return *this;
}

int TMyDate::Interval(int year, int month, int day)
{
	TMyDate firstTmd = *this;
	int num = 0;
	while (true)
	{
		if (year == firstTmd.m_year && month == firstTmd.m_month && day == firstTmd.m_day)
			return num;
		if ((year > firstTmd.m_year) || (year == firstTmd.m_year && month > firstTmd.m_month) || (year == firstTmd.m_year && month == firstTmd.m_month && day > firstTmd.m_day))
		{
			firstTmd.nextDay();
			num++;
		}
		else
		{
			firstTmd.frontDay();
			num--;
		}
	}
}

int TMyDate::Interval(TMyDate tmd)
{
	return Interval(tmd.getYear(), tmd.getMonth(), tmd.getDay());
	
}

bool TMyDate::isLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}

ostream& operator<<(ostream& out, TMyDate& tmd)
{
	out << tmd.getYear() << "年" << tmd.getMonth() << "月" << tmd.getDay() << "日";
	return out;
}
