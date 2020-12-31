#include"bits/stdc++.h"
#define ll long long
using namespace std;
const int MAXN = 1000;
ll jc[MAXN];
int c[100][100];
void jiecheng()
{
    jc[0] = 1;
    ll ji = 1;
    for(int i=1;i<=20;i++)
    {
        ji = ji * i;
        jc[i] = ji;
    }
}
void processc()
{
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i==j) c[i][j]= 1;
            else
            {
                c[i][j] = jc[i] / (jc[j] * jc[i-j]);
            }
            
        }
    }
}
int main()
{
    jiecheng();
    processc();
    cout<<c[36][3]<<endl;
}
