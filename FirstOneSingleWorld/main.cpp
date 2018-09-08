#include <iostream>
#include <string>
#include <vector>
/*
 * 输出第一个只出现一次的字符
 * abacddbe --- c
 */

#define BEGAIN_CHAR 'A'
#define END_CHAR 'z'
#define NUM_CHAR (END_CHAR - BEGAIN_CHAR)
using namespace std;

struct CountChar
{
//    CountChar(int t) : n(0), i(-1), c('a' + t) { }
    CountChar() : n(0), i(-1) {}
    int n;//出现个数
    int i;//第一次出现的索引
//    const char c;//字符
};

CountChar t[NUM_CHAR];//ASCII码??
//CountChar t[NUM_CHAR] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
//                   10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
//                   20, 21, 22, 23, 24, 25/*, 26, 27, 28, 29,
//                   30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
//                   40, 41, 42, 43, 44, 45*/};//表示26个abcdef...

ostream& operator << (ostream& out, CountChar c)
{
    return out << c.n << ": " << c.i/* << " " << c.c */<< endl;
}

void split(const string &s)
{
    for(unsigned int i=0; i<s.size() && i<NUM_CHAR; i++)
    {
        if(t[s[i] - BEGAIN_CHAR].n++ == 0)
        {
            t[s[i] - BEGAIN_CHAR].i = i;
        }
    }
}

char result(const string &s)//失败放回'\0'
{
    char ret = '\0';
    split(s);
    int index = s.size();
    for(int i=0; i<NUM_CHAR; i++)
    {
        if(t[i].n == 1 && t[i].i < index)
        {
            ret = i + BEGAIN_CHAR;
            index = t[i].i;
        }
    }
    return ret;
}

int main()
{
    string s;
    cin >> s;
    cout << result(s) << endl;
//    split(s);
    for(int i=0; i<NUM_CHAR; i++)
        if(t[i].n)
            cout << (char)(i + BEGAIN_CHAR) << t[i];
    return 0;
}
