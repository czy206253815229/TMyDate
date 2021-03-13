#include <iostream>
#include <Windows.h>
#include "TMyDate.h"
#include "SeqList.h"
#include "TNewDate.h"
#include "TNewDateList.h"
#include "TNewDateLinkList.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

//第一次作业的内容
void searchDate()
{
	cout << "请输入年月日，中间用空格分割" << endl;
	cout << "例如1901年1月1日输入：1901 1 1" << endl << endl;

	int year, month, day;
	cin >> year >> month >> day;
	TMyDate tmd(year, month, day);

	cout << "当前日期为" << tmd << endl;
	cout << "请选择操作:" << endl;
	cout << "1:加上相应的天数" << endl;
	cout << "2:减去相应的天数" << endl;
	cout << "3:计算相差天数" << endl;

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		int n;
		cout << "请输入加上的天数" << endl << endl;
		cin >> n;

		tmd.Increase(n);
	}
	case 2:
	{
		int n;
		cout << "请输入减去的天数" << endl << endl;
		cin >> n;

		tmd.Decrease(n);
	}
	case 3:
	{
		cout << "请再输入一个日期，格式和之前相同" << endl;
		int year, month, day;
		cin >> year >> month >> day;
		cout << endl;
		cout << "相差" << tmd.Interval(year, month, day) << "天" << endl;
		cout << "(负数代表该日期在当前日期之前)" << endl;
	}
	}

}

//遍历当前列表
void Print(TNewDateList *tndl)
{
	tndl->PrintList();
}
void Print(TNewDateLinkList* tndl)
{
	tndl->PrintList();
}
//判断给定日期是否设定为工作日
void isWorkDay(TNewDateList *tndl)
{
	cout << "请输入要查询的日期：";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);
	if (tndl->Locate(tndTemp) != -1)
		cout << "该日期是工作日" << endl;
	else
		cout << "该日期不是工作日或不在列表中" << endl;
}
void isWorkDay(TNewDateLinkList* tndl)
{
	cout << "请输入要查询的日期：";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);
	if (tndl->Locate(tndTemp) != -1)
		cout << "该日期是工作日" << endl;
	else
		cout << "该日期不是工作日或不在列表中" << endl;
}
//在列表中删除日期（标记为非工作日）
void DeleteWorkDay(TNewDateList *tndl)
{
	cout << "请输入要改为非工作日的日期：";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);
	
	tndTemp = tndl->Get(tndl->Locate(tndTemp));
	
	if (!tndTemp.isWorkDay())
		cout << "该日期不在列表中，修改失败" << endl;
	else
	{
		int location = tndl->Locate(tndTemp);
		tndl->Get(location).setWorkDay(false);
		tndl->Delete(location);
		cout << "已设置为非工作日" << endl;
	}
}
void DeleteWorkDay(TNewDateLinkList* tndl)
{
	cout << "请输入要改为非工作日的日期：";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);

	tndTemp = tndl->Get(tndl->Locate(tndTemp));

	if (!tndTemp.isWorkDay())
		cout << "该日期不在列表中，修改失败" << endl;
	else
	{
		int location = tndl->Locate(tndTemp);
		tndl->Get(location).setWorkDay(false);
		tndl->Delete(location);
		cout << "已设置为非工作日" << endl;
	}
}
//在列表中插入日期作为工作日
void InsertWorkDay(TNewDateList *tndl)
{
	cout << "请输入要改为工作日的日期：";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);

	if (tndTemp.isWorkDay())
	{
		cout << "该日期已在列表中或超出范围，修改失败" << endl;
		return;
	}
	else
	{
		tndTemp.setWorkDay(true);
		int i;
		for (i = 0; i < tndl->Length(); i++)
		{
			if (tndl->Get(i).Interval(tndTemp) < 0)
			{
				tndl->Insert(i, tndTemp);
				cout << "该日期已成功插入列表" << endl;
				break;
			}
		}
		if (i == tndl->Length())
		{
			tndl->Insert(i, tndTemp);
			cout << "该日期已成功插入列表末位" << endl;
		}
	}
}
void InsertWorkDay(TNewDateLinkList* tndl)
{
	cout << "请输入要改为工作日的日期：";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);

	if (tndTemp.isWorkDay())
	{
		cout << "该日期已在列表中或超出范围，修改失败" << endl;
		return;
	}
	else
	{
		tndTemp.setWorkDay(true);
		int i;
		for (i = 0; i < tndl->Length(); i++)
		{
			if (tndl->Get(i).Interval(tndTemp) < 0)
			{
				tndl->Insert(i, tndTemp);
				cout << "该日期已成功插入列表" << endl;
				break;
			}
		}
		if (i == tndl->Length())
		{
			tndl->Insert(i + 1, tndTemp);
			cout << "该日期已成功插入列表末位" << endl;
		}
	}
}
//一个时间段内一共有几个工作日
void CountWorkDays(TNewDateList *tndl)
{
	cout << "请输入两个日期：" << endl;
	cout << "请输入第一个日期:" << endl;
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp1 = TNewDate(y, m, d);
	if (tndTemp1.Interval(tndl->getStartTnd()) > 0)
	{
		cout << "输入的起始日期超出范围！";
		return;
	}
	cout << "请输入第二个日期:" << endl;
	cin >> y >> m >> d;
	TNewDate tndTemp2 = TNewDate(y, m, d);
	if (tndTemp2.Interval(tndl->getEndTnd()) < 0)
	{
		cout << "输入的结束日期超出范围！";
		return;
	}
	else
	{
		int location1, location2;
		while (!tndTemp1.isWorkDay())
		{
			tndTemp1.nextDay();
		}
		while (!tndTemp2.isWorkDay())
		{
			tndTemp2.frontDay();
		}
		location1 = tndl->Locate(tndTemp1);
		location2 = tndl->Locate(tndTemp2);
		if (location1 > location2)
		{
			cout << "两天之间没有工作日" << endl;
		}
		else
			cout << "两天之间共有" << location2 - location1 + 1 << "天工作日" << endl;
	}
}
void CountWorkDays(TNewDateLinkList* tndl)
{
	cout << "请输入两个日期：" << endl;
	cout << "请输入第一个日期:" << endl;
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp1 = TNewDate(y, m, d);
	if (tndTemp1.Interval(tndl->getStartTnd()) > 0)
	{
		cout << "输入的起始日期超出范围！";
		return;
	}
	cout << "请输入第二个日期:" << endl;
	cin >> y >> m >> d;
	TNewDate tndTemp2 = TNewDate(y, m, d);
	if (tndTemp2.Interval(tndl->getEndTnd()) < 0)
	{
		cout << "输入的结束日期超出范围！";
		return;
	}
	else
	{
		int location1, location2;
		while (!tndTemp1.isWorkDay())
		{
			tndTemp1.nextDay();
		}
		while (!tndTemp2.isWorkDay())
		{
			tndTemp2.frontDay();
		}
		location1 = tndl->Locate(tndTemp1);
		location2 = tndl->Locate(tndTemp2);
		if (location1 > location2)
		{
			cout << "两天之间没有工作日" << endl;
		}
		else
			cout << "两天之间共有" << location2 - location1 + 1 << "天工作日" << endl;
	}
}
//主选单
void menu(TNewDateList *tndl)
{
	cout << endl;

	cout << "您需要执行什么操作？" << endl;
	cout << "1.打印工作日列表" << endl;
	cout << "2.判断某一天是否为工作日" << endl;
	cout << "3.将一个日期设置为非工作日" << endl;
	cout << "4.将一个日期设置为工作日" << endl;
	cout << "5.计算两个日期间的工作日天数" << endl;
	cout << endl;
	cout << "----输入其它字符退出程序----" << endl;
	cout << endl;

	int choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1: {Print(tndl); Sleep(2000); menu(tndl); } break;
	case 2: {isWorkDay(tndl); Sleep(2000); menu(tndl); } break;
	case 3: {DeleteWorkDay(tndl); Sleep(2000); menu(tndl); } break;
	case 4: {InsertWorkDay(tndl); Sleep(2000); menu(tndl); } break;
	case 5: {CountWorkDays(tndl); Sleep(2000); menu(tndl); } break;
	default: exit(0); break;
	}
}
void menu(TNewDateLinkList* tndl)
{
	cout << endl;

	cout << "您需要执行什么操作？" << endl;
	cout << "1.打印工作日列表" << endl;
	cout << "2.判断某一天是否为工作日" << endl;
	cout << "3.将一个日期设置为非工作日" << endl;
	cout << "4.将一个日期设置为工作日" << endl;
	cout << "5.计算两个日期间的工作日天数" << endl;
	cout << endl;
	cout << "----输入其它字符退出程序----" << endl;
	cout << endl;

	int choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1: {Print(tndl); Sleep(2000); menu(tndl); } break;
	case 2: {isWorkDay(tndl); Sleep(2000); menu(tndl); } break;
	case 3: {DeleteWorkDay(tndl); Sleep(2000); menu(tndl); } break;
	case 4: {InsertWorkDay(tndl); Sleep(2000); menu(tndl); } break;
	case 5: {CountWorkDays(tndl); Sleep(2000); menu(tndl); } break;
	default: exit(0); break;
	}
}
//初始化顺序表
TNewDateList* CreateSeqList()
{
	int y1, m1, d1;
	int y2, m2, d2;
	cout << "请输入一个日期范围以创建线性表：" << endl;
	cout << "请输入第一个日期:" << endl;
	cin >> y1 >> m1 >> d1;
	cout << "请输入第二个日期:" << endl;
	cin >> y2 >> m2 >> d2;
	cout << endl;

	TNewDateList *tndl = new TNewDateList(TNewDate(y1, m1, d1), TNewDate(y2, m2, d2));
	return tndl;
}
//初始化链表
TNewDateLinkList* CreateLinkList()
{
	int y1, m1, d1;
	int y2, m2, d2;
	cout << "请输入一个日期范围以创建线性表：" << endl;
	cout << "请输入第一个日期:" << endl;
	cin >> y1 >> m1 >> d1;
	cout << "请输入第二个日期:" << endl;
	cin >> y2 >> m2 >> d2;
	cout << endl;

	TNewDateLinkList* tndl = new TNewDateLinkList(TNewDate(y1, m1, d1), TNewDate(y2, m2, d2));
	return tndl;
}

//主函数
int main()
{
	//第一次作业内容启用此行代码
	//searchDate();

	//使用顺序表启用此行代码
	//TNewDateList *tndl = CreateSeqList();

	//使用链表启用此行代码
	TNewDateLinkList* tndl = CreateLinkList();

	//此行代码应启用
	menu(tndl);
	return 0;
}