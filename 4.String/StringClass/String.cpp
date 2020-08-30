#include "String.h"

int main()
{
    char str1[] = "abcd";
    String s1;
    s1.Assign(str1);
    cout << "s1: " << s1 << " " << "length: " << s1.GetLength() << endl;

    String s2 = s1; //拷贝构造
    String s3 = Concat(s1, s2);
    cout << s1 + s2 << endl;
    cout << s3 << endl;
    // s1+s2=s3 返回1
    cout << ((s1 + s2) == s3) << endl;

    char str2[] = "ef";
    s2 += str2;
    cout << "s2: " << s2 << endl;
    //s1：abcd  s2:abcdef   s1<s2为True
    cout << (s1 < s2) << endl;

    //截取s3从下标1开始，长度为5的子串
    String s4 = SubString(s3, 1, 5);
    cout << "s4: " << s4 << endl;

    char str3[] = "12345";
    string s5(str3); //字符数组构造
    cout << "s5: " << s5 << endl;
    cout << s5[2] << endl; //s5中下标为2的值

    String s6;
    //测试输入 e.g. hello
    cout << "input value of s6: (e.g. hello)" << endl;
    cin >> s6;

    cout << "s6: " << s6 << endl;
    cout << "s6[3]: " <<s6[3] << endl;

    s6.Clear();
    cout << s6.GetLength() << endl;

    return 0;
}