#include "../StringClass/String.h" //引入已实现的String类头文件
#define maxSize 100

//简单模式匹配(Brute-Force)
int Index(String str, String subStr)
{
    if (str.GetLength() < subStr.GetLength())
    {
        return -1; //主串不能比模式串（子串）短，显然匹配失败
    }
    int i = 0, j = 0, k = i; //k用来记录上一次匹配的初始位置
    while (i < str.GetLength() && j < subStr.GetLength())
    {
        if (str[i] == subStr[j]) //""[]"操作符重载，实际上是s.ch[i] == subStr.ch[j]
        {
            ++i, ++j;
        }
        else
        {
            j = 0;
            i = ++k; //不匹配，i从主串的下一位置开始重新匹配
        }
    }
    if (j + 1 > subStr.GetLength())
    {
        return k; //匹配成功，返回模式串在主串中的位置
    }
    return -1; //匹配失败
}

//求next数组（KMP算法核心）
void GetNext(String subStr, int *next)
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < subStr.GetLength())
    {
        //j==0: 模式串的第一个字符和主串不匹配
        if (j == 0 || subStr[i - 1] == subStr[j - 1])
        {
            ++i, ++j;
            next[i] = j; //next[i]赋值为最长公共前后缀长度+1
        }
        else
        {
            j = next[j]; //模式串中第j个字符发生不匹配，从next[j]处的字符开始重新比较
        }
    }
}

//求nextVal数组（KMP算法改进）
void GetNextVal(String subStr, int *next)
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < subStr.GetLength())
    {
        //j==0: 模式串的第一个字符和主串不匹配
        if (j == 0 || subStr[i - 1] == subStr[j - 1])
        {
            ++i, ++j;
            if (subStr[i - 1] != subStr[j]) //在解决大量重复字段情况下（e.g. ohhhhhhhhh），避免不必要的判断
            {
                next[i] = j;
            }
            else
            {
                next[i] = next[j];
            }
        }
        else
        {
            j = next[j];
        }
    }
}

//基于next或nextval数组的KMP算法
int KMP(String str, String subStr, int *next)
{
    int i = 1;
    int j = 1;
    while (i <= str.GetLength() && j <= subStr.GetLength())
    {

        if (j == 0 || str[i - 1] == subStr[j - 1])
        {
            ++i, ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > subStr.GetLength())
    {
        return i - subStr.GetLength();
    }
    return -1;
}

int main()
{
    String s1, s2;
    //e.g. hello ello
    cout << "Input s1 and s2: (e.g. hello ello)" << endl;
    cin >> s1 >> s2;

    // cout << Index(s1, s2) << endl;

    int next[10];
    int nextVal[maxSize];

    GetNext(s2, next);
    GetNextVal(s2, nextVal);

    // cout << KMP(s1, s2, next) << endl;
    cout << KMP(s1, s2, nextVal) << endl;

    return 0;
}