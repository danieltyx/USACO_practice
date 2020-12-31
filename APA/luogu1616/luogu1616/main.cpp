#include"bits/stdc++.h"
using namespace std;
int m[100010];
int v[100010];
int dp[100010];

int main()
{
    int t,mm;
    cin>>t>>mm;
    for(int i=1;i<=mm;i++)
    {
        scanf("%d%d",&v[i],&m[i]);
    }
    for(int i=1;i<=mm;i++)
    {
        for(int j=1;j<=t;j++)
        {
            if(j<v[i])continue;
            dp[j]=max(dp[j],dp[j-v[i]]+m[i]);
        }
    }
    cout<<dp[t];
    return 0;
}
