#include "TNewDateList.h"

TNewDateList::TNewDateList()
{

}

TNewDateList::TNewDateList(TNewDate startTnd, TNewDate endTnd)
{
	m_startTnd = startTnd;
	m_endTnd = endTnd;

	bool flag = false;
	int count = 0;

	TNewDate *tndListTemp[MAX_SIZE];
	TNewDate tndTemp = TNewDate(startTnd);

	int interval = startTnd.Interval(endTnd);
	
	for(int i = 0 ; i <= interval ; i++)
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
		for (int i = 0; i < count; i++)
		{
			data[i] = *tndListTemp[i];
		}
		length = count;
		cout << "线性表创建成功" << endl;
		cout << "从" << startTnd << "到" << endTnd << "工作日一共有 " << count << " 天" << endl;
	}
	else
	{
		cout << "线性表初始化失败，可能是两天之间没有工作日" << endl;
		exit(0);
	}
}

TNewDateList::~TNewDateList()
{
	delete[] data;
}

TNewDate TNewDateList::getStartTnd()
{
	return m_startTnd;
}

TNewDate TNewDateList::getEndTnd()
{
	return m_endTnd;
}

int TNewDateList::Locate(TNewDate x)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == x)
			return i;
	}
	return -1;
};
