#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//顺序表最大容量在此处修改
#define MAX_SIZE 1000

//顺序表模板类，DataType为数据类型
template <class DataType> class SeqList
{
public:
	//无参构造函数
	SeqList() { length = 0; };
	//有参构造函数 
	SeqList(DataType a[], int n)
	{
		if (n > MAX_SIZE)
			throw "wrong parameter";
		for (int i = 0; i < n; i++)
			data[i] = a[i];
		length = n;
	};
	//析构函数
	~SeqList()
	{
		delete[] data;
	};
	//顺序表长度
	int Length()
	{
		return length;
	};
	//按位查找
	DataType Get(int i)
	{
		if (i<0 && i>length - 1)
			throw "Wrong Location";
		else
			return data[i];
	};
	//按值查找
	virtual int Locate(DataType x) = 0;

	//插入
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
	//删除
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
	//遍历
	void PrintList()
	{
		for (int i = 0; i < length; i++)
		{
			cout << data[i] << endl;
		}
	};


protected:
	//使用数组实现顺序表
	DataType* data = new DataType[MAX_SIZE];
	//顺序表的长度
	int length;
};

