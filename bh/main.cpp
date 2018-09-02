#include <iostream>

using namespace std;

bool containStr(const char *s, int sn, const char *t, int tn)
{
    bool ret = true;
    long h = 0;
    for(int i=0; i<sn; i++)
    {
        h |= (1 << (s[i] - 'A'));
    }
    for(int i=0; i<tn; i++)
    {
        if(!(h & (1 << (t[i] - 'A'))))
        {
            ret = false;
            break;
        }
    }
    return ret;
}

int main()
{
//    cout << "Hello World!" << endl;
    char s[] = "Zbcdef";
    char t[] = "Z d ";
    cout << containStr(s, 7, t, 3);
    return 0;
}
