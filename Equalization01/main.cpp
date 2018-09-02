#include <iostream>
#include <string>
using namespace std;

int howmany(string s)
{
    int numL = 0;
    int numR = 0;
    int end = s.size()/2;
    int rev = s.size() - 1;
    for(int i=0; i<end; i++)
    {
        if(s[i] == '1')
        {
            numL++;
        }
        if(s[rev-i] == '1')
        {
            numR++;
        }
    }
    if(numL == numR)
        return 1;
    return 2;
}


int main()
{
    cout << howmany("0101001111") << endl;
    return 0;
}
