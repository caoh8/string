#include <iostream>
#include <map>
#include <iterator>

using namespace std;

class LRU_Cahche
{
    int N;
    map<int, int> m;
    map<int, int> use;

    int min()
    {
        int tmp = usd[0];
        int ret = 0;
        for(int i=0; i<N; i++)
        {
            if(usd[i] < tmp)
            {
                tmp = usd[i];
                ret = i;
            }
        }
    }

public:
    LRU_Cahche(int n) : N(n)
    {
        for(int i=0; i<N; i++)
            usd[i] = 0;
    }
    int get(int key)
    {
        int ret = -1;

        map<int, int>::iterator it = m.find(key);

        if(it != m.end())
        {
            ret = it->second;
        }

        return ret;
    }

    void put(int key, int value)
    {
        map<int, int>::iterator it = m.find(key);

        if(it != m.end())
        {
            m[key] = value;
        }
        else
        {
            if(N==0)
            {
                m.erase(min());
            }
            m.insert(pair<int, int>(key, value));
        }
    }
};

int main()
{
    int N = 0;
    cin >> N;

    char pg;
    LRU_Cahche cahche(N);
    while (true)
    {
        cin >> pg;
        if(pg == 'g')
        {
            int g = 0;
            cin >> g;
            cout << cahche.get(g);
        }
        if(pg == 'p')
        {
            int p = 0;
            int key = 0;
            cin >> key;
            cin >> p;
            cahche.put(key, p);
        }
    }

    return 0;
}
