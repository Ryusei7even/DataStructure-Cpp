#include <iostream>
#include <algorithm>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

class SinglyList
{
public:
    SinglyList();
    ~SinglyList();
    void TailInsert();                //尾插法1
    void CreateTail(int *a, int len); //尾插法2
    void HeadInsert();                //头插法1
    void CreateHead(int *a, int len); //头插法2
    bool IsEmpty();
    void Print();                          
    int GetLength();
    int GetElem(int i);               //获取第i个位置元素值
    int LocateElem(int value);        //查找第一个值为value的元素，返回下标
    void Insert(int i, int value);    //第i个位置前插入值为value的元素
    void Reverse();                   //链表反转法1
    void Reverse2();                  //链表反转法2(头插法思想)
    void DeleteElem(int i);           //删除第i个元素
    void Clear();                     //清空（只剩头结点）
    SinglyList Merge(SinglyList A, SinglyList B); //返回两个非递减有序链表A、B合并成的新链表

private:
    LNode *head;
};

SinglyList::SinglyList()
{
    LNode *p = new LNode;
    p->next = NULL;
    head = p; //head指向p
}

SinglyList::~SinglyList()
{
    LNode *p = head;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

void SinglyList::TailInsert()
{
    int x;
    LNode *s, *r = head;
    while (~scanf("%d", &x))
    {
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void SinglyList::CreateTail(int *a, int len)
{
    LNode *s, *r; //s指向新申请节点， r始终指向终端节点
    r = head;
    for (int i = 0; i < len; i++)
    {
        s = new LNode;
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void SinglyList::HeadInsert()
{
    int x;
    LNode *s;
    while (~scanf("%d", &x))
    {
        s = new LNode;
        s->data = x;
        s->next = head->next;
        head->next = s;
    }
}

void SinglyList::CreateHead(int *a, int len)
{
    LNode *s;
    for (int i = 0; i < len; i++)
    {
        s = new LNode;
        s->data = a[i];
        s->next = head->next;
        head->next = s;
    }
}

bool SinglyList::IsEmpty()
{
    return head->next == NULL;
}

void SinglyList::Print()
{
    if (IsEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    LNode *p = head->next;
    while (p) //等同于 while(p != NULL)，以下均略写
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}



int SinglyList::GetLength()
{
    int len = 0;
    LNode *p = head->next; //p指向第一个结点
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int SinglyList::GetElem(int i)
{
    LNode *p = head->next;
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

int SinglyList::LocateElem(int value)
{
    LNode *p = head->next;
    int j = 0;
    while (p && p->data != value)
    {
        p = p->next;
        ++j;
    }
    return j;
}

void SinglyList::Insert(int i, int value)
{
    LNode *p = head;
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
    LNode *s = new LNode;
    s->data = value;
    s->next = p->next;
    p->next = s;
}

void SinglyList::Reverse()
{
    if (IsEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    LNode *p = head, *q = head->next, *r = NULL;
    while (q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head->next->next = NULL;
    head->next = p;
}

void SinglyList::Reverse2(){
    if (IsEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    LNode *p=head->next, *q;
    head->next=NULL;
    while (p)
    {
        q=p->next;
        p->next=head->next;
        head->next=p;
        p=q;
    }
}

void SinglyList::DeleteElem(int i)
{
    LNode *p = head;
    int j = 0;

    while (p->next && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
    {
        cout << "Out of range!" << endl;
        return;
    }
    LNode *q = p->next;
    p->next = p->next->next;
    delete q;
}

void SinglyList::Clear()
{
    LNode *p = head->next;
    while (p)
    {
        LNode *q = p->next;
        delete p;
        p = q;
    }
    head->next = NULL;
}

SinglyList SinglyList::Merge(SinglyList A, SinglyList B)
{
    LNode *p = A.head->next;
    LNode *q = B.head->next;
    LNode *r;
    head = A.head; //用A的头结点作为C的头结点
    head->next = NULL;
    r = head;
    delete B.head;
    while (p && q)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            p = p->next;
            r = r->next;
        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    r->next = p ? p : q; //插入剩余节点
    // if (p)
    //     r->next = p;
    // if (q)
    //     r->next = q;

    
    return *this;
}

int main()
{
    int arr[] = {1, 8, 7, 2, 5, 3, 4, 6};
    SinglyList list;
    list.CreateTail(arr, 8);
    //头插为倒序
    // list.CreateHead(arr, 8);

    list.Reverse();
    list.Reverse2();
    list.Print();

    cout << "Length: " << list.GetLength() << endl;

    list.DeleteElem(8);
    cout << "After delete: ";
    list.Print();

    cout << "Value: " << list.GetElem(1) << endl;

    //在第一个位置插入0
    list.Insert(1, 0);
    list.Print();

    list.Clear();
    list.Print();

    int arr1[3], arr2[3];
    for (int i = 0; i < 3; i++)
    {
        arr1[i] = i;
        arr2[i] = arr1[i] + i;
    }
    SinglyList list1, list2, list3, list4;
    list1.CreateTail(arr1, 3);
    list2.CreateTail(arr2, 3);

    //删除第一个元素
    list1.DeleteElem(1);
    cout << "list1: ";
    list1.Print();
    cout << "list2: ";
    list2.Print();

    list4=list3.Merge(list1, list2);
    cout << "Merge list1 and list2: ";
    list4.Print();

    //查找list3中第一个值为3的元素的下标
    cout << "index: " << list4.LocateElem(3);
    cout << endl;

    //输入测试 ctrl+z停止
    // SinglyList list4;
    // cout << "Input element: " << endl;
    // list4.TailInsert();
    // list4.Print();

    return 0;
}
