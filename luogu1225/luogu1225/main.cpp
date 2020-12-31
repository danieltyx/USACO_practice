#include"bits/stdc++.h"
using namespace std;
char a[100];
int f[5050][5000];
int len = 1;
void apa(int k)
{
    for(int i=1;i<=len;i++)
    {
        f[k][i] += f[k-1][i] + f[k-2][i];
        if(f[k][i]>=10)
        {
            f[k][i+1] += f[k][i]/10;
            f[k][i] = f[k][i]%10;
            if(f[k][len+1]!=0)len++;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    f[1][1] =1;
    f[2][1] =2;
    for(int i=3;i<=n;i++)
    {
        apa(i);
    }
    for(int i=len;i>=1;i--)
    {
        cout<<f[n][i];
    }
    return 0;
}
