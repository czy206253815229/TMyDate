//——————————————继承自TMyDate类，增加星期和工作日相关计算——————————————
#pragma once
#include "TMyDate.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class TNewDate : public TMyDate
{
    //左移运算符重载，用于输出年月日星期信息
    friend ostream& operator<<(ostream& out, TNewDate& tnd);
    //等于运算符重载，在年月日均相等的情况下判定两对象相等
    friend bool operator==(TNewDate& tnd1, TNewDate& tnd2);

public:
    //无参构造函数
    TNewDate();
    //有参构造函数
    TNewDate(int y, int m, int d);
    
    //根据日期判断星期
    int CaculateWeekDay(int y, int m, int d);
    //获取当前日期的星期号
    int getWeekDayNumber();
    //获取当前星期的中文名称
    string getWeekDay();
    //返回m_isWorkDay的值
    bool isWorkDay();
    //通过星期判断当前天是否为工作日
    bool JudgeWorkDayByWeekDay();
    //设置当前日期是否为工作日
    void setWorkDay(bool x);
    //日期前进一天
    TMyDate& nextDay();
    //日期后退一天
    TMyDate& frontDay();
    //日期增加多天
    TMyDate& Increase(int days);
    //日期减少多天
    TMyDate& Decrease(int days);

protected:
    //标记：是否未周末，0：是， 1：否
    int m_weekDay;
    //标记：是否为工作日，1：是， 2：否
    bool m_isWorkDay;
};