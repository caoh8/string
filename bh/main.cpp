#include <iostream>
#include <string>

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

bool containStr(string s, int sn, string t, int tn)
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
    string s;
    cin >> s;
    string t;
    cin >> t;
    if(containStr(s, s.size(), t, t.size()))
        cout << "true";
    else
        cout << "false";
    return 0;
}
