//——————————————日期存储和运算类——————————————
#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;


class TMyDate
{
	friend ostream& operator<<(ostream& out, TMyDate& tmd);

protected:
	int m_year;
	int m_month;
	int m_day;

public:
	//无参构造方法
	TMyDate();
	//有参构造方法
	TMyDate(int year, int month, int day);
	//获取年
	int getYear();
	//获取月
	int getMonth();
	//获取日
	int getDay();

	//日期前进一天
	TMyDate& nextDay();
	//日期后退一天
	TMyDate& frontDay();
	//日期增加多天
	TMyDate& Increase(int days);
	//日期减少多天
	TMyDate& Decrease(int days);
	//计算两天之间间隔
	int Interval(int year, int month, int day);
	int Interval(TMyDate tmd);
	//判断是否闰年
	static bool isLeap(int year);
	
};