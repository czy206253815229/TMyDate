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
		cout << "链表创建成功" << endl;
		//cout << *tndListTemp[0];
		//cout << head->next->data;
		cout << "从" << startTnd << "到" << endTnd << "工作日一共有 " << count << " 天" << endl;
	}
	else
	{
		cout << "线性表初始化失败，可能是两天之间没有工作日" << endl;
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
