#include <iostream>
//最长回文子串
#define SIZE 14//字符串长度
#define N_SIZE 2*SIZE+2
#define MIN(x, y) (x < y ? x : y)
using namespace std;

//char S[N_SIZE];
//得到辅助字符串t
void createStr(char *s, char *t)
{
    if(s!=NULL)
    {
        *t++ = '$';
        *t++ = '#';
    }
    while(*s)
    {
        *t++ = *s++;
        *t++ = '#';
    }
    *t = '\0';
}
//得到回文子串的分布
void Manacher(char *S, int P[])
{
//    int P[N_SIZE] = {0};
    int mx = 0;
    int id;
    int mlength = 0;
    int mid;
    for(int i=1; i<N_SIZE; i++)
    {
        if(mx>i)
        {
            P[i] = MIN(P[2*id-i], mx-i);
        }
        else
        {
            P[i] = 1;
        }
        while(S[i-P[i]] == S[i+P[i]])
        {
            P[i]++;
        }
        if(P[i] + i > mx)
        {
            mx = P[i] + i;
            id = i;
            if(P[i] > mlength)
            {
                mlength = P[i];
                mid = i;
            }
        }
    }
    cout << "Center: " << mid << endl;//输出最大的中心位置
    cout << "Center value: " << S[mid] << endl;//输出最大的中心位置值
    cout << "longest value: " << mlength - 1 << endl;//输出最大的长度
    for(int i=0; i<N_SIZE; i++)
    {
        cout << P[i] << " ";
    }
    cout << endl;
}
//好难，放弃这部分
//根据p的分布，得到回文子串的输出分布s,t为距离中心位置长度
//void split(int p[], int s[], int t[])
//{
//    for(int i=1; i<N_SIZE; i++)
//    {
//        if(p[i] > s[i])
//        {
//            for(int j=0; j<p[i]; j++)
//            {
//                if(s[i-j] < p[i])
//                {
//                    s[i-j] = p[i];
//                }
//                else
//                    break;
//                s[i+j] = p[i];
//                t[i+j] = j;
//                t[i-j] = j;
//            }
//        }
//    }
//}

//void displayStr(char *s, int from, int to)
//{
//    for(int i=from; i<to; i++)
//    {
//        cout << s[i];
//    }
//    cout << endl;
//}

int main()
{
    cout << "Hello World!" << endl;
    char S[] = "SaSaabacababca";
    cout << S << endl;
    char T[N_SIZE+1];

    createStr(S, T);
    cout << T << endl;
    cout << S << endl;
    int P[N_SIZE] = {0};
    Manacher(T, P);

//    split(P,s, t);
//    for(int i=0; i<N_SIZE; i++)
//    {
//        cout << s[i] << " ";
//    }
//    cout << endl;
//    for(int i=0; i<N_SIZE; i++)
//    {
//        cout << t[i] << " ";
//    }
//    cout << endl;
//    for(int i=0; i<SIZE; )
//    {
//        int length = s[2*(i+1)] - 1;
// //        cout << length << endl;
//        displayStr(S, i, i+length);
// //        cout << (i += length) << endl;
//        i += length;
//    }
    return 0;
}
