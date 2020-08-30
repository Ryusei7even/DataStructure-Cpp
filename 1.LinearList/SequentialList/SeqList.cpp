#include <iostream>
#include <algorithm>
using namespace std;
#define maxSize 100

class SeqList
{
public:
    SeqList();
    ~SeqList();
    void Create(int *a, int n);
    int GetLength();
    void Print();
    int GetElem(int i);        //获取第i个位置元素值
    int LocateElem(int value); //查找第一个值为value的元素，返回下标
    bool IsEmpty();
    bool Insert(int i, int value); //第i个位置前插入值为value的元素
    void Reverse();                //顺序表反转
    void ReversePointer();         //顺序表反转法2
    void DeleteElem(int i);        //删除第i个元素

private:
    int *elem; //存储空间基址
    int len;
};

SeqList::SeqList()
{
    elem = new int[maxSize];
    len = 0;
}

SeqList::~SeqList()
{
    delete[] elem;
}

void SeqList::Create(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        elem[i] = a[i];
    }
    len = n;
}

int SeqList::GetLength()
{
    return len;
}

void SeqList::Print()
{
    if (IsEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    for (int i = 0; i < len; i++)
    {
        cout << elem[i] << " ";
    }
    cout << endl;
}

int SeqList::GetElem(int i)
{
    if (i < 0 || i > len)
    {
        cout << "Out of range!" << endl;
    }
    return elem[i];
}

int SeqList::LocateElem(int value)
{
    int j = 0;
    while (j < len && elem[j] != value)
        ++j;
    if (j == len)
        return -1; //未找到
    return j;
}

bool SeqList::IsEmpty()
{
    return len == 0;
}

bool SeqList::Insert(int i, int value)
{
    if (i < 1 || i > len)
    {
        cout << "Out of range!" << endl;
        return -1;
    }
    ++len;
    for (int j = len - 1; j >= i; j--)
    {
        elem[j] = elem[j - 1];
    }
    elem[i - 1] = value;
    return 1;
}

void SeqList::Reverse()
{
    if (IsEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    for (int i = 0; i < len / 2; i++)
    {
        swap(elem[i], elem[len - i - 1]);
    }
}

void SeqList::ReversePointer()
{
    if (IsEmpty())
    {
        cout << "List is empty!" << endl;
        return;
    }
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        swap(elem[i], elem[j]);
    }
}

void SeqList::DeleteElem(int i)
{
    if (i < 0 || i > len)
    {
        cout << "Out of range!" << endl;
    }
    for (int j = i - 1; j < len - 1; j++)
    {
        elem[j] = elem[j + 1]; //从p-1位置开始前移
    }
    --len;
}

int main()
{
    int arr[] = {1, 8, 7, 2, 5, 3, 4, 6};
    // int arr[] = {1};
    SeqList slist;
    slist.Create(arr, 8);

    slist.DeleteElem(3);
    cout << slist.GetLength() << endl;
    slist.Print();

    cout << slist.LocateElem(8); //8的下标为1
    cout << endl;

    slist.Insert(1, 99);
    slist.Print();

    // slist.Reverse();
    slist.ReversePointer();

    slist.Print();

    return 0;
}