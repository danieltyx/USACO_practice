#include"bits/stdc++.h"
using namespace std;
int a[500];
int b[500];
int c[500];
int dp[500][500][500];
int mark[500];
void fs(int i,int j,int k)
{
    if(i>0)
    {
        if(dp[i][j][k]==dp[i-1][j][k])
        {
            mark[i]=0;
            fs(i-1,j,k);
        }
        else if(j-b[i]>=0 && k-a[i]>=0 && dp[i][j][k] == dp[i-1][j-b[i]][k-a[i]]+c[i])
        {
            mark[i]=1;
            fs(i-1,j-b[i],k-a[i]);
        }
    }
}
int main()
{
    int m,v,n;
    cin>>m>>v>>n;
   for(int i=1;i<=n;i++)
   {
       scanf("%d%d%d",&a[i],&b[i],&c[i]);
   }
    for(int i=1;i<=n;i++)
    {
        for(int j=b[i];j<=v;j++)
        {
            for(int k=a[i];k<=m;k++)
            {
                dp[i][j][k] = max(dp[i-1][j][k],dp[i-1][j-b[i]][k-a[i]]+c[i]);
            }
        }
    }
    fs(n,v,m);
    cout<<dp[n][v][m]<<endl;
    for(int i=1;i<=n;i++)
    {
        if(mark[i]==1)cout<<i<<" ";
    }
    return 0;
}
