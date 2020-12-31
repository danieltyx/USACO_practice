#include"bits/stdc++.h"
using namespace std;
int m[1010];
int v[1010];
int dp[1010][1010];
int main()
{
    int t;
    int mm;
    cin>>t>>mm;
    for(int i=1;i<=mm;i++)
    {
        scanf("%d%d",&v[i],&m[i]);
    }
    int vt=t;
    for(int i=1;i<=mm;i++)
    {
        for(int j=1;j<=vt;j++)
        {
            if(j<v[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j-v[i]]+m[i],dp[i-1][j]);
            }
        }
    }
    cout<<dp[mm][t];
    return 0;
}
