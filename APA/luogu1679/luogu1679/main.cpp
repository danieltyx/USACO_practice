#include"bits/stdc++.h"
#define int long long
using namespace std;
int jh[20];
int dp[100100];
void cal()
{
    for(int i=1;i<=20;i++)
    {
        jh[i] = i*i*i*i;
    }
}
signed main()
{
    int m;
    cin>>m;
    dp[0]=1;
    for(int i=1;i<=100100;i++)
    {
        dp[i]=99999;
    }
    for(int i=1;i<=20;i++)
    {
        for(int j=jh[i];j<=m;j++)
        {
            dp[j]=min(dp[j],dp[j-jh[i]]+1);
        }
    }
    cout<<dp[m];
    return 0;
}
