//�����������������������������̳���SeqList�࣬�������ڵ�˳���洢����������������������������
#pragma once
#include "SeqList.h"
#include "TNewDate.h"
#include "TMyDate.h"

class TNewDateList : public SeqList<TNewDate>
{
public:
	//�޲ι���
	TNewDateList();
	//�вι��죬startTnd����ʼ���ڣ�endTnd���������ڣ��������ʱ����ڳ�ʼ���б�
	TNewDateList(TNewDate startTnd, TNewDate endTnd);
	//��������
	~TNewDateList();
	//��д���ി�麯��Locate���������ڣ�TNewDate�����󣬲�����˳����е�λ��
	TNewDate getStartTnd();
	TNewDate getEndTnd();
	int Locate(TNewDate x);

private:
	TNewDate m_startTnd;
	TNewDate m_endTnd;
};