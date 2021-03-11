//�������������������������������ڴ洢�������ࡪ��������������������������
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
	//�޲ι��췽��
	TMyDate();
	//�вι��췽��
	TMyDate(int year, int month, int day);
	//��ȡ��
	int getYear();
	//��ȡ��
	int getMonth();
	//��ȡ��
	int getDay();

	//����ǰ��һ��
	TMyDate& nextDay();
	//���ں���һ��
	TMyDate& frontDay();
	//�������Ӷ���
	TMyDate& Increase(int days);
	//���ڼ��ٶ���
	TMyDate& Decrease(int days);
	//��������֮����
	int Interval(int year, int month, int day);
	int Interval(TMyDate tmd);
	//�ж��Ƿ�����
	static bool isLeap(int year);
	
};