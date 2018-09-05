#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct strStruct
{
    int num;
    string str;
};

ostream& operator << (ostream& out, strStruct str)
{
    for(int i=0; i<str.num; i++)
        out << str.str;
    return out;
}

void split(string &s, vector<strStruct> &strs)
{
    string tmp;
    int n = 0;
    bool preCharIsNum = false;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            n = n*10 + s[i] - '0';
            preCharIsNum = true;
        }
        else
        {
            if(preCharIsNum)
            {
                strStruct strTmp;
                strTmp.num = n;
                strTmp.str = tmp;
                strs.push_back(strTmp);
                tmp.clear();
                n = 0;
            }
            tmp.push_back(s[i]);
            preCharIsNum = false;
        }
    }

    strStruct strTmp;
    strTmp.num = n;
    strTmp.str = tmp;
    strs.push_back(strTmp);
}

bool compareStrStrcut(strStruct str1, strStruct str2)
{
    return str1.num == str2.num ? str1.str < str2.str : str1.num < str2.num;
}

int main()
{
    vector<strStruct> strs;
    string s;
    cin >> s;
    split(s, strs);

    vector<strStruct>::iterator it;
    sort(strs.begin(), strs.end(), compareStrStrcut);
    for(it = strs.begin(); it != strs.end(); it++)
    {
        cout << *it;
    }
    return 0;
}
