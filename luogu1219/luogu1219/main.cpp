#include"bits/stdc++.h"
using namespace std;
int n;
int mp[101][101];
int u[101][101];
int ans=0;
int xx[9]={0,1,1,1,0,0,-1,-1,-1};
int yy[9]={0,0,-1,1,-1,1,0,1,-1};

int xxx[4]= {0,0,1,1};
int yyy[4]= {0,1,0,1};
int xb,yb;
//int hnum[14]={0,0,0,0,0,0,6};
void printres()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<u[i][j]<<" ";
        }
        puts("");
    }
    puts("");
}
void dfs(int x,int y)
{
    mp[x][y]=1;
    u[x][y]=1;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x2 = x + xx[i]*j;
            int y2 = y + yy[i]*j;
            if(x2>=1&&y2>=1&&x2<=n&&y2<=n)
            {
                u[x2][y2]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(u[i][j]==0)
            {
                dfs(i,j);
            }
        }
    }
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x2 = x + xx[i]*j;
            int y2 = y + yy[i]*j;
            if(x2>=1&&y2>=1&&x2<=n&&y2<=n)
            {
                u[x2][y2]=1;
            }
        }
    }
    
    
    
    
    
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j]==1) cout<<j<<" ";
        }
    }
    puts("");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mp[i][j]=0;
            u[i][j]=0;
        }
    }
    for(int i=1;i<=4;i++)
    {
        dfs(xb+xxx[i],yb+yyy[i]);
    }
}
int main()
{
    cin>>n;
    xb=1;
    yb=1;
    dfs(xb,yb);
}
