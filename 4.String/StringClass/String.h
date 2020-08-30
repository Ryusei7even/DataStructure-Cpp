#include <iostream>
#include <cstring>
using namespace std;
#ifndef STRING_H
#define STRING_H

class String
{
public:
    String();
    String(char *chars);
    String(const String &s);
    ~String();
    friend String SubString(const String& s, int pos, int len);       //返回第pos个字符起长度为len的子串
    friend int Compare(const String& s1, const String& s2);                  //类似C中的strcmp()，s1>s2返回正值，相等返回0，s1<s2返回负值
    String Assign(char *chars);                                //赋值法1
    String &operator=(const String &s);                        //赋值法2：重载"="运算符
    friend String Concat(String &s1, String &s2);              //拼接串法1
    String operator+(const String &s);                         //拼接串法2：重载"+"运算符
    char &operator[](int index);                               //重载"[]"运算符
    bool operator==(const String &);                           //重载"=="运算符
    String operator+=(const String &s);                        //重载"+="运算符
    int operator>(const String &s);                            //重载">"运算符
    int operator<(const String &s);                            //重载"<"运算符
    friend ostream &operator<<(ostream &out, const String &s); //重载"<<"运算符
    friend istream &operator>>(istream &in, String &s);        //重载">>"运算符
    int GetLength() const;                                           //返回长度
    void Clear();                                              //清空串

private:
    char *ch;
    int len;
};


String::String()
{
    ch = NULL;
    len = 0;
}

//字符数组构造
String::String(char *chars)
{
    len = strlen(chars);
    ch = new char[len + 1]; //+1为了存储'\0'
    strcpy(ch, chars);
    ch[len] = '\0';
}

//拷贝构造
String::String(const String &s)
{
    len = s.len;
    ch = new char[len + 1];
    strcpy(ch, s.ch);
    ch[len] = '\0';
}

String::~String()
{
    delete[] ch;
    ch = NULL;
}

String SubString(const String& s, int pos, int len)
{
    String subStr;
    if (pos < 0 || pos >= s.len || len <= 0 || len > s.len - pos) //截取长度超出范围或子串长度不合法
    {
        cout << "No substring" << endl;
        return subStr;
    }
    else
    {
        subStr.ch = new char[len + 1];
        for (int i = pos, j = 0; i < pos + len; i++, j++)
        {
            subStr.ch[j] = s.ch[i];
        }
        subStr.len = len;
        subStr.ch[len] = '\0';
        return subStr;
    }
}

int Compare(const String& s1, const String& s2)
{
    for (int i = 0; i < s1.len && i < s2.len; i++)
    {
        if (s1.ch[i] != s2.ch[i])
        {
            return s1.ch[i] - s2.ch[i];
        }
    }
    return s1.len - s2.len;
}

String String::Assign(char *chars)
{
    if (ch)
    {
        delete[] ch;
    }
    char *c = chars;
    int length = 0;
    while (*c)
    {
        ++length, ++c;
    }
    if (!length)
    {
        ch = NULL;
        len = 0;
        return *this;
    }
    else
    {
        ch = new char(length + 1);
        c = chars;
        for (int i = 0; i <= length; i++, c++)
        {
            ch[i] = *c;
        }
        len = length;
        return *this;
    }
}

String &String::operator=(const String &s)
{
    len = s.len;
    if (this == &s)
    {
        return *this;
    }
    if (ch)
    {
        delete[] ch;
    }
    if (s.ch)
    {
        ch = new char[len + 1];
        strcpy(ch, s.ch);
        cout << s.ch << endl;
        ch[len] = '\0';
        cout << ch << endl;
    }
    else
    {
        ch = NULL;
    }
    return *this;
}

String Concat(String &s1, String &s2)
{
    String newStr;

    newStr.ch = new char[newStr.len + 1];
    int i = 0, j = 0;
    while (i < s1.len)
    {
        newStr.ch[i] = s1.ch[i];
        i++;
    }
    while (j < s2.len)
    {
        newStr.ch[i + j] = s2.ch[j];
        j++;
    }
    newStr.len = s1.len + s2.len;
    newStr.ch[newStr.len] = '\0';
    return newStr;
}

String String::operator+(const String &s)
{
    String newStr;
    len += strlen(s.ch);
    if (len > 0)
    {
        newStr.ch = new char[len + 1];
        strcpy(newStr.ch, ch);
        strcat(newStr.ch, s.ch);
        newStr.ch[len] = '\0';
    }
    else
    {
        newStr.ch = 0;
    }
    return newStr;
}

char &String::operator[](int index)
{
    if (index < 0 || index > len)    //ch[len]存放'\0'
    {
        cout << "Out of range!" << endl;
    }
    return ch[index];
}

bool String::operator==(const String &s)
{
    return (strcmp(ch, s.ch) == 0);
}

String String::operator+=(const String &s)
{
    len += s.len;
    char *newCh = new char[len + 1];
    strcpy(newCh, ch);
    strcat(newCh, s.ch);
    delete[] ch;
    ch = newCh;
    return *this;
}

int String::operator>(const String &s)
{
    return Compare(*this, s) > 0;
}

int String::operator<(const String &s)
{
    return Compare(*this, s) < 0;
}

ostream &operator<<(ostream &out, const String &s)
{
    out << s.ch;
    return out;
}

istream &operator>>(istream &in, String &s)
{
    char temp[100];
    in >> temp;
    s.len = strlen(temp);
    s.ch = new char[s.len + 1];
    strcpy(s.ch, temp);
    s.ch[s.len] = '\0';
    return in;
}

int String::GetLength() const
{
    return len;
}

void String::Clear()
{
    if (ch)
    {
        delete[] ch;
        ch = NULL;
        len = 0;
    }
}

#endif