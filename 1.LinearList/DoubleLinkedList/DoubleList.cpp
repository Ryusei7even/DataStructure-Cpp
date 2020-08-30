#include <iostream>
#include <algorithm>
using namespace std;

typedef struct DLNode
{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
} DLNode;

class DoubleList
{
public:
    DoubleList();
    ~DoubleList();
    void Create(int *a, int len); //尾插法建立
    bool IsEmpty();
    void Print();
    void ReversePrint();
    int GetLength();
    int GetElem(int i);                  //获取第i个位置元素值
    int LocateElem(int value);           //查找第一个值为value的元素，返回下标
    void InsertBefore(int i, int value); //第i个位置前插入值为value的元素
    void InsertAfter(int i, int value);  //第i个位置后插入值为value的元素
    void Reverse();                      //链表反转
    void DeleteElem(int i);              //删除第i个元素
    void Clear();

private:
    DLNode *head;
};

DoubleList::DoubleList()
{
    head = new DLNode;
    head->prior = NULL;
    head->next = NULL;
}

DoubleList::~DoubleList()
{
    DLNode *p = head;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

void DoubleList::Create(int *a, int len)
{
    DLNode *s, *r = head; //r指向终端结点，初始头结点也是尾结点
    int i;
    for (int i = 0; i < len; i++)
    {
        s = new DLNode;
        s->data = a[i];
        r->next = s;
        s->prior = r; //与单链表的区别
        r = s;
    }
    r->next = NULL;
}

bool DoubleList::IsEmpty()
{
    return head->next == NULL;
}

void DoubleList::Print()
{
    if (IsEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    DLNode *p = head->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void DoubleList::ReversePrint()
{
    if (IsEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    DLNode *p = head->next;
    while (p->next)
    {
        p = p->next;
    }
    while (p->prior)
    {
        cout << p->data << " ";
        p = p->prior;
    }
    cout << endl;
}

int DoubleList::GetLength()
{
    int len = 0;
    DLNode *p = head->next;
    while (p)
    {
        p = p->next;
        ++len;
    }
    return len;
}

int DoubleList::GetElem(int i)
{
    DLNode *p = head->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
    {
        cout << "Not in the list." << endl;
        return -1;
    }
    else
    {
        return p->data;
    }
}

int DoubleList::LocateElem(int value)
{
    DLNode *p = head->next;
    int j = 0;
    while (p && p->data != value)
    {
        p = p->next;
        ++j;
    }
    return j;
}

void DoubleList::InsertBefore(int i, int value)
{
    DLNode *p = head->next;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
    {
        cout << "Out of range!" << endl;
        return;
    }
    DLNode *s = new DLNode;
    s->data = value;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
}

void DoubleList::InsertAfter(int i, int value)
{
    DLNode *p = head->next;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
    {
        cout << "Out of range!" << endl;
        return;
    }
    DLNode *s = new DLNode;
    s->data = value;
    s->next = p->next;
    // p->next->prior = s;
    s->next->prior = s;
    s->prior = p;
    p->next = s;
}

void DoubleList::Reverse()
{
    if (IsEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    DLNode *p = head, *q = head->next, *r = NULL;
    while (q)
    {
        r = q->next;
        q->next = p;
        q->prior = r;
        p = q;
        q = r;
    }
    head->next->next = NULL;
    head->next = p;
}

void DoubleList::DeleteElem(int i)
{
    DLNode *p = head;
    int j = 0;
    if (i < 1 || i > GetLength())
    {
        cout << "Out of range!" << endl;
        return;
    }
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (i == GetLength())
    {
        p->prior->next = NULL;
        delete p;
        return;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
}

void DoubleList::Clear()
{
    DLNode *p = head->next, *q = head->next;
    head->next = NULL;
    while (p)
    {
        p = p->next;
        free(q);
        q = p;
    }
}

int main()
{
    int arr[] = {1, 8, 7, 2, 5, 3, 4, 6};
    DoubleList list;
    list.Create(arr, 8);

    cout << list.GetLength();
    cout << endl;
    //第1个位置前插入99
    list.InsertBefore(1, 99);
    //第8个位置后插入100
    list.InsertAfter(8, 100);
    list.Print();

    list.DeleteElem(10);
    list.ReversePrint();

    list.Reverse();
    list.Print();

    cout << list.LocateElem(100);
    cout<<endl;
    
    list.Clear();
    list.Print();

    return 0;
}