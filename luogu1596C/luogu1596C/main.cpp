#include"bits/stdc++.h"
using namespace std;
int n,m;
char a[1001];
int mp[1001][1001];
int ans=0;
int xx[9]={0,1,1,1,0,0,-1,-1,-1};
int yy[9]={0,0,1,-1,1,-1,0,1,-1};
void bfs(int x,int y)
{
    queue<int> qux;
    queue<int> quy;
    qux.push(x);
    quy.push(y);
    while(!qux.empty())
    {
        int x1=qux.front();
        int y1=quy.front();
        qux.pop();
        quy.pop();
        for(int i=1;i<=8;i++)
        {
            int x2 = x1 + xx[i];
            int y2 = y1 + yy[i];
            if(x2<1||y2<1||x2>n||y2>m||mp[x2][y2]==0)continue;
            mp[x2][y2]=0;
            qux.push(x2);
            quy.push(y2);
        }
    }
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
            if(mp[i][j]==1)
            {
                mp[i][j]==0;
                bfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
