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

//��һ����ҵ������
void searchDate()
{
	cout << "�����������գ��м��ÿո�ָ�" << endl;
	cout << "����1901��1��1�����룺1901 1 1" << endl << endl;

	int year, month, day;
	cin >> year >> month >> day;
	TMyDate tmd(year, month, day);

	cout << "��ǰ����Ϊ" << tmd << endl;
	cout << "��ѡ�����:" << endl;
	cout << "1:������Ӧ������" << endl;
	cout << "2:��ȥ��Ӧ������" << endl;
	cout << "3:�����������" << endl;

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		int n;
		cout << "��������ϵ�����" << endl << endl;
		cin >> n;

		tmd.Increase(n);
	}
	case 2:
	{
		int n;
		cout << "�������ȥ������" << endl << endl;
		cin >> n;

		tmd.Decrease(n);
	}
	case 3:
	{
		cout << "��������һ�����ڣ���ʽ��֮ǰ��ͬ" << endl;
		int year, month, day;
		cin >> year >> month >> day;
		cout << endl;
		cout << "���" << tmd.Interval(year, month, day) << "��" << endl;
		cout << "(��������������ڵ�ǰ����֮ǰ)" << endl;
	}
	}

}

//������ǰ�б�
void Print(TNewDateList *tndl)
{
	tndl->PrintList();
}
void Print(TNewDateLinkList* tndl)
{
	tndl->PrintList();
}
//�жϸ��������Ƿ��趨Ϊ������
void isWorkDay(TNewDateList *tndl)
{
	cout << "������Ҫ��ѯ�����ڣ�";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);
	if (tndl->Locate(tndTemp) != -1)
		cout << "�������ǹ�����" << endl;
	else
		cout << "�����ڲ��ǹ����ջ����б���" << endl;
}
void isWorkDay(TNewDateLinkList* tndl)
{
	cout << "������Ҫ��ѯ�����ڣ�";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);
	if (tndl->Locate(tndTemp) != -1)
		cout << "�������ǹ�����" << endl;
	else
		cout << "�����ڲ��ǹ����ջ����б���" << endl;
}
//���б���ɾ�����ڣ����Ϊ�ǹ����գ�
void DeleteWorkDay(TNewDateList *tndl)
{
	cout << "������Ҫ��Ϊ�ǹ����յ����ڣ�";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);
	
	tndTemp = tndl->Get(tndl->Locate(tndTemp));
	
	if (!tndTemp.isWorkDay())
		cout << "�����ڲ����б��У��޸�ʧ��" << endl;
	else
	{
		int location = tndl->Locate(tndTemp);
		tndl->Get(location).setWorkDay(false);
		tndl->Delete(location);
		cout << "������Ϊ�ǹ�����" << endl;
	}
}
void DeleteWorkDay(TNewDateLinkList* tndl)
{
	cout << "������Ҫ��Ϊ�ǹ����յ����ڣ�";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);

	tndTemp = tndl->Get(tndl->Locate(tndTemp));

	if (!tndTemp.isWorkDay())
		cout << "�����ڲ����б��У��޸�ʧ��" << endl;
	else
	{
		int location = tndl->Locate(tndTemp);
		tndl->Get(location).setWorkDay(false);
		tndl->Delete(location);
		cout << "������Ϊ�ǹ�����" << endl;
	}
}
//���б��в���������Ϊ������
void InsertWorkDay(TNewDateList *tndl)
{
	cout << "������Ҫ��Ϊ�����յ����ڣ�";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);

	if (tndTemp.isWorkDay())
	{
		cout << "�����������б��л򳬳���Χ���޸�ʧ��" << endl;
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
				cout << "�������ѳɹ������б�" << endl;
				break;
			}
		}
		if (i == tndl->Length())
		{
			tndl->Insert(i, tndTemp);
			cout << "�������ѳɹ������б�ĩλ" << endl;
		}
	}
}
void InsertWorkDay(TNewDateLinkList* tndl)
{
	cout << "������Ҫ��Ϊ�����յ����ڣ�";
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp = TNewDate(y, m, d);

	if (tndTemp.isWorkDay())
	{
		cout << "�����������б��л򳬳���Χ���޸�ʧ��" << endl;
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
				cout << "�������ѳɹ������б�" << endl;
				break;
			}
		}
		if (i == tndl->Length())
		{
			tndl->Insert(i + 1, tndTemp);
			cout << "�������ѳɹ������б�ĩλ" << endl;
		}
	}
}
//һ��ʱ�����һ���м���������
void CountWorkDays(TNewDateList *tndl)
{
	cout << "�������������ڣ�" << endl;
	cout << "�������һ������:" << endl;
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp1 = TNewDate(y, m, d);
	if (tndTemp1.Interval(tndl->getStartTnd()) > 0)
	{
		cout << "�������ʼ���ڳ�����Χ��";
		return;
	}
	cout << "������ڶ�������:" << endl;
	cin >> y >> m >> d;
	TNewDate tndTemp2 = TNewDate(y, m, d);
	if (tndTemp2.Interval(tndl->getEndTnd()) < 0)
	{
		cout << "����Ľ������ڳ�����Χ��";
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
			cout << "����֮��û�й�����" << endl;
		}
		else
			cout << "����֮�乲��" << location2 - location1 + 1 << "�칤����" << endl;
	}
}
void CountWorkDays(TNewDateLinkList* tndl)
{
	cout << "�������������ڣ�" << endl;
	cout << "�������һ������:" << endl;
	int y, m, d;
	cin >> y >> m >> d;
	TNewDate tndTemp1 = TNewDate(y, m, d);
	if (tndTemp1.Interval(tndl->getStartTnd()) > 0)
	{
		cout << "�������ʼ���ڳ�����Χ��";
		return;
	}
	cout << "������ڶ�������:" << endl;
	cin >> y >> m >> d;
	TNewDate tndTemp2 = TNewDate(y, m, d);
	if (tndTemp2.Interval(tndl->getEndTnd()) < 0)
	{
		cout << "����Ľ������ڳ�����Χ��";
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
			cout << "����֮��û�й�����" << endl;
		}
		else
			cout << "����֮�乲��" << location2 - location1 + 1 << "�칤����" << endl;
	}
}
//��ѡ��
void menu(TNewDateList *tndl)
{
	cout << endl;

	cout << "����Ҫִ��ʲô������" << endl;
	cout << "1.��ӡ�������б�" << endl;
	cout << "2.�ж�ĳһ���Ƿ�Ϊ������" << endl;
	cout << "3.��һ����������Ϊ�ǹ�����" << endl;
	cout << "4.��һ����������Ϊ������" << endl;
	cout << "5.�����������ڼ�Ĺ���������" << endl;
	cout << endl;
	cout << "----���������ַ��˳�����----" << endl;
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

	cout << "����Ҫִ��ʲô������" << endl;
	cout << "1.��ӡ�������б�" << endl;
	cout << "2.�ж�ĳһ���Ƿ�Ϊ������" << endl;
	cout << "3.��һ����������Ϊ�ǹ�����" << endl;
	cout << "4.��һ����������Ϊ������" << endl;
	cout << "5.�����������ڼ�Ĺ���������" << endl;
	cout << endl;
	cout << "----���������ַ��˳�����----" << endl;
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
//��ʼ��˳���
TNewDateList* CreateSeqList()
{
	int y1, m1, d1;
	int y2, m2, d2;
	cout << "������һ�����ڷ�Χ�Դ������Ա�" << endl;
	cout << "�������һ������:" << endl;
	cin >> y1 >> m1 >> d1;
	cout << "������ڶ�������:" << endl;
	cin >> y2 >> m2 >> d2;
	cout << endl;

	TNewDateList *tndl = new TNewDateList(TNewDate(y1, m1, d1), TNewDate(y2, m2, d2));
	return tndl;
}
//��ʼ������
TNewDateLinkList* CreateLinkList()
{
	int y1, m1, d1;
	int y2, m2, d2;
	cout << "������һ�����ڷ�Χ�Դ������Ա�" << endl;
	cout << "�������һ������:" << endl;
	cin >> y1 >> m1 >> d1;
	cout << "������ڶ�������:" << endl;
	cin >> y2 >> m2 >> d2;
	cout << endl;

	TNewDateLinkList* tndl = new TNewDateLinkList(TNewDate(y1, m1, d1), TNewDate(y2, m2, d2));
	return tndl;
}

//������
int main()
{
	//��һ����ҵ�������ô��д���
	//searchDate();

	//ʹ��˳������ô��д���
	//TNewDateList *tndl = CreateSeqList();

	//ʹ���������ô��д���
	TNewDateLinkList* tndl = CreateLinkList();

	//���д���Ӧ����
	menu(tndl);
	return 0;
}