//�����������������������������̳���LinkList�࣬�������ڵ�˳���洢����������������������������
#pragma once
#include "LinkList.h"
#include "TNewDate.h"
#include "TMyDate.h"

#define MAX_SIZE 1000

class TNewDateLinkList : public LinkList<TNewDate>
{
public:
	//�޲ι���
	TNewDateLinkList();
	//�вι��죬startTnd����ʼ���ڣ�endTnd���������ڣ��������ʱ����ڳ�ʼ���б�
	TNewDateLinkList(TNewDate startTnd, TNewDate endTnd);
	//��������
	~TNewDateLinkList();
	TNewDate getStartTnd();
	TNewDate getEndTnd();
	//��д���ി�麯��Locate���������ڣ�TNewDate�����󣬲�����˳����е�λ��
	int Locate(TNewDate x);
	
private:
	TNewDate m_startTnd;
	TNewDate m_endTnd;
};