#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//˳�����������ڴ˴��޸�
#define MAX_SIZE 1000

//˳���ģ���࣬DataTypeΪ��������
template <class DataType> class SeqList
{
public:
	//�޲ι��캯��
	SeqList() { length = 0; };
	//�вι��캯�� 
	SeqList(DataType a[], int n)
	{
		if (n > MAX_SIZE)
			throw "wrong parameter";
		for (int i = 0; i < n; i++)
			data[i] = a[i];
		length = n;
	};
	//��������
	~SeqList()
	{
		delete[] data;
	};
	//˳�����
	int Length()
	{
		return length;
	};
	//��λ����
	DataType Get(int i)
	{
		if (i<0 && i>length - 1)
			throw "Wrong Location";
		else
			return data[i];
	};
	//��ֵ����
	virtual int Locate(DataType x) = 0;

	//����
	void Insert(int i, DataType x)
	{
		if (length >= MAX_SIZE)
			throw "Overflow";
		if (i<0 || i>length)
			throw "Wrong Location";
		for (int j = length; j >= i + 1; j--)
			data[j] = data[j - 1];
		data[i] = x;
		length++;
	};
	//ɾ��
	void Delete(int i)
	{
		DataType x;
		if (length == 0)
			throw "Underflow";
		if (i<0 || i>length - 1)
			throw "Wrong Location";
		for (int j = i; j < length - 1; j++)
			data[j] = data[j + 1];
		length--;
	};
	//����
	void PrintList()
	{
		for (int i = 0; i < length; i++)
		{
			cout << data[i] << endl;
		}
	};


protected:
	//ʹ������ʵ��˳���
	DataType* data = new DataType[MAX_SIZE];
	//˳���ĳ���
	int length;
};

