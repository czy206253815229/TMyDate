//——————————————继承自LinkList类，用于日期的顺序表存储——————————————
#pragma once
#include "LinkList.h"
#include "TNewDate.h"
#include "TMyDate.h"

#define MAX_SIZE 1000

class TNewDateLinkList : public LinkList<TNewDate>
{
public:
	//无参构造
	TNewDateLinkList();
	//有参构造，startTnd：开始日期，endTnd：结束日期，将在这个时间段内初始化列表
	TNewDateLinkList(TNewDate startTnd, TNewDate endTnd);
	//析构函数
	~TNewDateLinkList();
	TNewDate getStartTnd();
	TNewDate getEndTnd();
	//重写父类纯虚函数Locate，给出日期（TNewDate）对象，查找在顺序表中的位置
	int Locate(TNewDate x);
	
private:
	TNewDate m_startTnd;
	TNewDate m_endTnd;
};