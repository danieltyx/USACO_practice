#include"bits/stdc++.h"
using namespace std;
int m[1010];
int v[1010];
int dp[1010];
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
        for(int j=t;j>=1;j--)
        {
            if(v[i]>j)
            {
                dp[j]=dp[j];
            }
            else
            {
                dp[j]= max(dp[j-v[i]],m[i]);
            }
        }
    }
    cout<<dp[t];
    return 0;
}
