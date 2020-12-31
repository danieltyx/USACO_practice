#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 210
#define INF dp[0][0]
int dp[maxn][maxn],n,m,q,t[maxn];
signed main()
{
    cin>>n>>m;
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&t[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        dp[x+1][y+1] = dp[y+1][x+1] = z;
    }
    cin>>q;
    int s=1;
    for(int ii=1;ii<=q;ii++)
    {
        int x,y,z,k;
        scanf("%lld%lld%lld",&x,&y,&z);
        x++,y++;
        for(k=s;t[k]<=z && k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        s=k;
        if(dp[x][y]==INF||t[x]>z||t[y]>z)
        {
            printf("-1\n");
        }else
        {
            printf("%lld\n",dp[x][y]);
        }
    }
}
