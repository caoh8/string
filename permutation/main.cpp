#include <iostream>

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

// 2

int main()
{
    cout << "Hello World!" << endl;
    char s[] = "abc";
    permutationDsf(s, 0, 2);
    return 0;
}
