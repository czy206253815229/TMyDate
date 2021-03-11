//——————————————链表模板类——————————————
#pragma once
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template<class DataType>
struct Node
{
    DataType data;
    Node<DataType>* next;
};

template<class DataType>
class LinkList
{
public:
    //无参构造函数
    LinkList();
    //有参构造函数
    LinkList(DataType a[], int n);
    //析构函数
    ~LinkList();
    //创建链表
    void CreateLinkList(DataType* a[], int n);
    //链表长度
    int Length();
    //按位查找
    DataType Get(int i);
    //按值查找
    virtual int Locate(DataType x)  = 0 {};
    //插入
    void Insert(int i, DataType x);
    //删除
    DataType Delete(int i);
    //遍历
    void PrintList();
protected:
    Node<DataType>* head;
};

template<class DataType>
LinkList<DataType>::LinkList()
{
    head = new Node<DataType>;
    head->next = NULL;
}

template<class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
    CreateLinkList(a, n);
}

template<class DataType>
LinkList<DataType>::~LinkList()
{
    while (head != NULL)
    {
        Node<DataType>* q = head;
        head = head->next;
        delete q;
    }
}

template<class DataType>
inline void LinkList<DataType>::CreateLinkList(DataType* a[], int n)
{
    Node<DataType>* end, * node;
    head = new Node<DataType>;
    head->next = NULL;
    end = head;
    for (int i = 0; i < n; i++)
    {
        node = new Node<DataType>;
        node->data = *a[i];
        //cout << a[i];
        end->next = node;
        end = node;
        //cout << end->data;
    }
    end->next = NULL;
}

template<class DataType>
int LinkList<DataType>::Length()
{
    Node<DataType>* p = head->next;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

template<class DataType>
DataType LinkList<DataType>::Get(int i)
{
    Node<DataType>* p = head->next;
    int count = 1;
    while (p != NULL && count < i)
    {
        p = p->next;
        count++;
    }
    if (p == NULL) throw "Location";
    else return p->data;
}

template<class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
    Node<DataType>* p = head;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL) throw "Location";
    else {
        Node<DataType>* s = new Node<DataType>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
    Node<DataType>* p = head;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL || p->next == NULL) throw "Location";
    else {
        Node<DataType>* q = p->next;
        DataType x = q->data;
        p->next = q->next;
        return x;
    }
}

template<class DataType>
void LinkList<DataType>::PrintList()
{
    Node<DataType>* p = head->next;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}