#ifndef SeqQueue_H
#define SeqQueue_H

class SeqQueue
{
public:
    SeqQueue(); //初始化队列
    ~SeqQueue();
    bool IsEmpty();
    bool IsFull();
    void Print();
    int GetHead();       //返回队头元素
    int GetTail();       //返回队尾元素
    int GetLength();     //返回长度
    void EnQueue(int x); //进队列
    int DeQueue();       //出队列并返回队尾头元素值
    void Clear();        //清空

private:
    int *queue; //数组基址
    int front;  //队首指针
    int rear;   //队尾指针
};

#endif