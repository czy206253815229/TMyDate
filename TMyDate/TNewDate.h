//�����������������������������̳���TMyDate�࣬�������ں͹�������ؼ��㡪��������������������������
#pragma once
#include "TMyDate.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class TNewDate : public TMyDate
{
    //������������أ��������������������Ϣ
    friend ostream& operator<<(ostream& out, TNewDate& tnd);
    //������������أ��������վ���ȵ�������ж����������
    friend bool operator==(TNewDate& tnd1, TNewDate& tnd2);

public:
    //�޲ι��캯��
    TNewDate();
    //�вι��캯��
    TNewDate(int y, int m, int d);
    
    //���������ж�����
    int CaculateWeekDay(int y, int m, int d);
    //��ȡ��ǰ���ڵ����ں�
    int getWeekDayNumber();
    //��ȡ��ǰ���ڵ���������
    string getWeekDay();
    //����m_isWorkDay��ֵ
    bool isWorkDay();
    //ͨ�������жϵ�ǰ���Ƿ�Ϊ������
    bool JudgeWorkDayByWeekDay();
    //���õ�ǰ�����Ƿ�Ϊ������
    void setWorkDay(bool x);
    //����ǰ��һ��
    TMyDate& nextDay();
    //���ں���һ��
    TMyDate& frontDay();
    //�������Ӷ���
    TMyDate& Increase(int days);
    //���ڼ��ٶ���
    TMyDate& Decrease(int days);

protected:
    //��ǣ��Ƿ�δ��ĩ��0���ǣ� 1����
    int m_weekDay;
    //��ǣ��Ƿ�Ϊ�����գ�1���ǣ� 2����
    bool m_isWorkDay;
};