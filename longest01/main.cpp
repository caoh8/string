#include <iostream>
#include <string>
#include <vector>

using namespace std;

int char0[100] = {0};//标记为0的位置

int countS(string &s, int &count1, int &count0, int mark[])
{
    int ret = 0;
    count0 = 0;
    count1 = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '1')
        {
            count1++;
            ret++;
        }
        else
        {
            mark[count0] = i;
            count0++;
        }
    }

    return ret;
}

void marke(string &s, int mark[])
{
    int j=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '0')
        {
            mark[j++] = i;
        }
    }
}

void changeN(int n, int k, int count0, int mark[], vector<int> &ret)
{
    if(count0 - n < k - ret.size())
    {
        ret.clear();
        return;
    }

    if(ret.size()==k)
    {
        for(int i=0; i<k; i++)
            cout << ret[i] << " ";
        cout << endl;
//        ret.clear();
    }

    for(int i=n; i<count0; i++)
    {
        ret.push_back(mark[i]);
        changeN(i+1, k, count0, mark, ret);
        ret.pop_back();
        changeN(i+1, k, count0, mark, ret);
    }
}

void solution(string &s, int k)
{
    if(1);
}


int main()
{
//    cout << "Hello World!" << endl;
    string s = "0111000";
    int k = 2;
    int n = s.size();
    int count0 = 0;
    int count1 = 0;
    int mark[s.size()] = {0};
    int tmpRet = 0;
    countS(s, count1, count0, mark);
    for(int i=0; i<count0; i++)
        cout << mark[i] << " ";

    vector<int> ret;
    changeN(0, k, count0, mark, ret);
//    for(int i=0; i)
    return 0;
}
