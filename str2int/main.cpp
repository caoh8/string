#include <iostream>

using namespace std;
// 1判断正负
// 2判断溢出
bool str2int(char* s, int &result)
{
    bool ret = true;

    static const int MAX_INT = (int)((unsigned)~0 >> 1);
    static const int MIN_INT = -(int)((unsigned)~0 >> 1) -1;//边界
    int n = 0;
    int sign = 1;
    if(s!=NULL)
    {
        if(*s)
        {
            if(*s == '-')
            {
                sign = -1;
                s++;
            }
            if(*s == '+')
            {
//                sign = 1;
                s++;
            }
            while(*s)
            {
                if(*s>='0' || *s<='9')
                {
                    int c = *s - '0';
                    if(sign>0 && (n > MAX_INT/10 || (n == MAX_INT/10 && c > MAX_INT%10)))
                    {
                        cout << "out range in str2int" << endl;
                        ret = false;
                        break;
                    }
                    else if(sign<0 && (n < MIN_INT/10 || (n == MIN_INT/10 && -c < MIN_INT%10)))
                    {
                        cout << "out range in str2int" << endl;
                        ret = false;
                        break;
                    }
                    n = n*10+sign*c;
                    s++;
                }
                else
                {
                    ret = false;
                    break;
                }
            }
        }
        else
        {
            ret = false;
        }
    }
    else
    {
        ret = false;
    }
    if(ret)
        result = n;
    return ret;
}

int main()
{
    cout << "Hello World!" << endl;
    char *s = "147483647";
    int n = 0;
    cout << str2int(s, n) << endl;
    cout << n << endl;

    int MAX = -(int)((unsigned)~0>>1)-1;
    cout << MAX << endl;
    return 0;
}
