#include"bits/stdc++.h"
using namespace std;
int mp[1010][1010];
char a[1010];
int xx[9]={0,1,1,1,-1,-1,-1,0,0};
int yy[9]={0,0,1,-1,0,1,-1,1,-1};
int ans=0;
int n,m;
void bfs(int x,int y)
{
    queue<int> qux;
    queue<int> quy;
    qux.push(x);
    quy.push(y);
    mp[x][y] =0;
    while(!qux.empty())
    {
        int fx = qux.front();
        int fy = quy.front();
        qux.pop();
        quy.pop();
        for(int i=1;i<=8;i++)
        {
            int fx2 = fx + xx[i];
            int fy2 = fy + yy[i];
            if(mp[fx2][fy2]==1)
            {
                if(fx2<1||fy2<1||fx2>n||fy2>m)continue;
                mp[fx2][fy2]=0;
                qux.push(fx2);
                quy.push(fy2);
            }
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
            if(a[j-1]=='.')
            {
                mp[i][j]=0;
            }
            else if(a[j-1]=='W')
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
                bfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
