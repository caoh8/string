#include <iostream>
#include <algorithm>

using namespace std;

class DINGDAN
{
public:
    int Num;
    int Time_in;
    int Time_out;
};

int main()
{
    int N = 0;
    cin >> N;
    int A = 0;
    cin >> A;
    DINGDAN dingdan[N];

    for(int i=0; i<N; i++)
    {
        cin >> dingdan[i].Num;
        cin >> dingdan[i].Time_in;
        cin >> dingdan[i].Time_out;
    }

    return 0;
}
