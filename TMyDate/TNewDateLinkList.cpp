#include "TNewDateLinkList.h"

TNewDateLinkList::TNewDateLinkList()
{

}

TNewDateLinkList::TNewDateLinkList(TNewDate startTnd, TNewDate endTnd)
{
	bool flag = false;
	int count = 0;

	TNewDate *tndListTemp[MAX_SIZE];
	TNewDate tndTemp = TNewDate(startTnd);

	int interval = startTnd.Interval(endTnd);

	for (int i = 0; i <= interval; i++)
	{
		if (tndTemp.JudgeWorkDayByWeekDay())
		{
			tndListTemp[count++] = new TNewDate(tndTemp);
			flag = true;
		}
		(TMyDate)tndTemp = tndTemp.nextDay();
	}

	if (flag)
	{
		if (count > MAX_SIZE)
			throw "wrong parameter";
		CreateLinkList(tndListTemp, count);
		cout << "�������ɹ�" << endl;
		//cout << *tndListTemp[0];
		//cout << head->next->data;
		cout << "��" << startTnd << "��" << endTnd << "������һ���� " << count << " ��" << endl;
	}
	else
	{
		cout << "���Ա��ʼ��ʧ�ܣ�����������֮��û�й�����" << endl;
		exit(0);
	}
}

TNewDateLinkList::~TNewDateLinkList()
{
}

int TNewDateLinkList::Locate(TNewDate x)
{
	Node<TNewDate>* p = head->next;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == x) return count;
		p = p->next;
		count++;
	}
	return -1;
}
