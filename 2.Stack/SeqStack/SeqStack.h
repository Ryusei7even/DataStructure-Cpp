#ifndef SeqStack_H
#define SeqStack_H

class SeqStack
{
public:
    SeqStack(); //初始化栈
    ~SeqStack();
    bool IsEmpty();
    void Print();
    int GetLength();  //返回栈长度
    int GetTop();     //返回栈顶元素
    void Push(int x); //进栈
    int Pop();        //弹栈并返回栈顶元素值
    void Clear();     //清空

private:
    int *stack; //数组基址
    int top;    //栈顶指针
};


#endif