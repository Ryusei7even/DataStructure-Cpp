#include <iostream>
#include "SeqQueue.h"
#define maxSize 20
using namespace std;

SeqQueue::SeqQueue()
{
    queue = new int[maxSize];
    front = rear = 0; //初始队空，首尾指针都指向0
}

SeqQueue::~SeqQueue()
{
    delete[] queue;
    queue = NULL;
}

bool SeqQueue::IsEmpty()
{
    return front == rear;  //队空即初始状态，front = rear
}

bool SeqQueue::IsFull()
{
    return (rear + 1) % maxSize == front; //循环队列要牺牲一个存储单元，位置差一格时即为队满，否则无法与队空区分
}

void SeqQueue::Print()
{
    if (IsEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    for (int i = front; i != rear;)
    {
        cout << queue[i] << " ";
        i = (i + 1) % maxSize;
    }
    cout << endl;
}

int SeqQueue::GetHead()
{
    return queue[front];
}

int SeqQueue::GetTail()
{
    return queue[(rear - 1 + maxSize) % maxSize];
}

int SeqQueue::GetLength()
{
    return ((rear - front + maxSize) % maxSize);
}

void SeqQueue::EnQueue(int x)
{
    if (IsFull())
    {
        cout << "Queue is full!" << endl;
        return;
    }
    queue[rear] = x;   //先赋值
    rear = (rear + 1) % maxSize;   //队尾指针再后移
}

int SeqQueue::DeQueue()
{
    if (IsEmpty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int x = queue[front];
    front = (front + 1) % maxSize;  //队首指针后移
    return x;
}

void SeqQueue::Clear()
{
    while (!IsEmpty())  //不为空就一直出队
    {
        DeQueue();
    }
}

int main()
{
    SeqQueue qu;
    for (int i = 0; i < maxSize - 1; i++)
    {
        qu.EnQueue(i);
    }
    qu.Print();

    for (int i = 0; i < 10; i++)
    {
        cout << qu.GetHead() << " ";
        qu.DeQueue();
    }
    cout << endl;

    cout << qu.GetLength() << endl;

    for (int i = maxSize - 1; i < maxSize + 10; i++) //最后一个元素不会入队
    {
        qu.EnQueue(i);
    }
    qu.Print();

    qu.Clear();
    qu.Print();

    return 0;
}