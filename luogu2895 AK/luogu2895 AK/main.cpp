#include <bits/stdc++.h>
using namespace std;
int m,mp[400][400],dis[400][400],n=302;
int xx[5] = {0,1,-1,0,0};
int yy[5] = {0,0,0,1,-1};
void setxy(int x,int y,int t)
{
    if(x>=0&&y>=0&&x<=n&&y<=n&&mp[x][y]>t)
    {
        mp[x][y] = t;
    }
}

void bfs()
{
    memset(dis,0x3f,sizeof(dis));
    queue<int>qux,quy;
    qux.push(0);
    quy.push(0);
    dis[0][0]=0;
    if(mp[0][0]==0x3f3f3f3f)
    {
        cout<<0;
        return;
    }
    while(!qux.empty())
    {
        int fx = qux.front(),fy=quy.front();
        qux.pop(),quy.pop();
        for(int i=1;i<=4;i++)
        {
            int tx = fx+xx[i];
            int ty = fy+yy[i];
            int ft = dis[fx][fy]+1;
            if(tx>=0&&tx<=n&&ty>=0&&ty<=n&&dis[tx][ty]>ft
               &&mp[tx][ty]>ft)
            {
                dis[tx][ty]=ft;
                qux.push(tx), quy.push(ty);
                if(mp[tx][ty]==0x3f3f3f3f)
                {
                    cout<<ft;
                    return;
                }
            }
        }
    }
    cout<<-1;
}
int main()
{
    cin>>m;
    int t,x,y;
    memset(mp,0x3f,sizeof(mp));
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&t);
        for(int j=0;j<=4;j++)
        {
            setxy(x+xx[j],y+yy[j],t);
        }
    }
    bfs();
    return 0;
}
