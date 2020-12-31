#include"bits/stdc++.h"
using namespace std;
char a[1001];
int mp[1001][1001]={0};
int ans=0;
int n,m;
int xx[9]={0,1,1,1,-1,-1,-1,0,0};
int yy[9]={0,0,1,-1,0,1,-1,1,-1};
int u[1001][1001]={0};
void dfs(int x,int y)
{
    for(int i=1;i<=8;i++)
    {
        int x2=x+xx[i];
        int y2=y+yy[i];
        if(x2<1||y2<1||x2>n||y2>m||u[x2][y2]==1||mp[x2][y2]==0)
        {
            continue;
        }
        u[x2][y2]=1;
        dfs(x2,y2);
    }
    return;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a);
        for(int j=1;j<=m;j++)
        {
            if(a[j-1]=='W')
            {
                mp[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==1&&u[i][j]!=1)
            {
                u[i][j]=1;
                dfs(i,j);
                /*for(int k=1;k<=n;k++)
                {
                    for(int q=1;q<=m;q++)
                    {
                        cout<<u[k][q];
                    }
                    puts("");
                }
                puts("");*/
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
