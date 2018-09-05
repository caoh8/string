#include <iostream>
#include <string>

using namespace std;
// 1
void permutationDsf(char *s, int from, int to)
{
    if(from == to)
    {
        for(int i=0; i<=to; i++)
            cout << s[i];
        cout << endl;
    }
    else
    {
        for(int j=from; j<=to; j++)
        {
            swap(s[j], s[from]);
            permutationDsf(s, from+1, to);
            swap(s[j], s[from]);
        }
    }
}

// 2 有序排列，s为要排序字符串，n为要多少位
void bsf(string &s, string &d,int c, int n)
{
    int m = d.size();
    if((s.size() - c) < (n-d.size()))
    {
        d.clear();
        return;
    }
    if(m == n)
    {
        cout << d << endl;
        return;
    }

    for(int i=c; i<(int)s.size(); i++)
    {

        d.push_back(s[i]);
        bsf(s, d, i+1, n);
        d.pop_back();
        bsf(s, d, i+1, n);
    }
}
void orderedStrPemutation(string s, int n)
{
    string d;
    if(n==0)
        return;
    if(n==1)
    {
        for(int i=0; i<(int)s.size(); i++)
        {
            cout << s[i] << endl;
        }
        return;
    }
    bsf(s, d, 0, n);
}

int main()
{
    cout << "Hello World!" << endl;
    char s[] = "abc";
    permutationDsf(s, 0, 2);
    string ss = "abcdefgh";
    orderedStrPemutation(ss, 5);
    return 0;
}
