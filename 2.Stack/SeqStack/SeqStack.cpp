#include <iostream>
#include "SeqStack.h"
using namespace std;
#define maxSize 30

SeqStack::SeqStack()
{
    stack = new int[maxSize];
    top = -1; //规定top为-1时，栈为空
}

SeqStack::~SeqStack()
{
    delete[] stack;
    stack = NULL;
}

bool SeqStack::IsEmpty()
{
    return top == -1;
}

void SeqStack::Print()
{
    if (IsEmpty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    while (!IsEmpty())
    {
        cout << stack[top--] << " ";
    }
    cout << endl;
}

int SeqStack::GetLength()
{
    return top + 1;
}

int SeqStack::GetTop()
{
    return stack[top];
}

void SeqStack::Push(int x)
{
    if (GetLength() >= maxSize)   //栈满不能进栈
    {
        cout << "Stack over flow!" << endl;
        return;
    }
    stack[++top] = x;   //先移动栈顶指针再进栈
}

int SeqStack::Pop()
{
    if (IsEmpty())  //栈空不能弹栈
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    int x = stack[top--];  //先取出元素再移动栈顶指针
    return x;
}

void SeqStack::Clear()
{
    while (!IsEmpty())
    {
        Pop();
    }
}

int main()
{
    SeqStack st;
    for (int i = 0; i < maxSize; i++)
    {
        st.Push(i);
    }
    cout << "Length: " << st.GetLength() << endl;
    st.Push(100);  //栈溢出，进栈失败

    st.Pop();
    cout << "Pop one element: " << st.GetTop() << endl;
    st.Print();

    st.Clear();
    st.Pop();     //栈空，弹栈失败

    return 0;
}