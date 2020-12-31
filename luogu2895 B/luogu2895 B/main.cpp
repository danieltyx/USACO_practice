#include"bits/stdc++.h"
using namespace std;
int n;
int tn;
int safemap[301][301];
struct Memtor{
    int x;
    int y;
    int t;
};
Memtor m[50001];
int nowmap[301][301];
int xx[5]={0,0,0,1,-1};
int yy[5]={0,1,-1,0,0};
bool cmp(Memtor a,Memtor b)
{
    return a.t<b.t;
}
void checkmap(int t)
{
    for(int i=1;i<=n;i++)
    {
        if(m[i].t==t)
        {
            for(int j=0;j<=4;j++)
            {
                int x1 = m[i].x + xx[i];
                int y1 = m[i].y + yy[i];
                if(x1<0||y1<0||x1>300||y1>300)continue;
                nowmap[x1][y1]=1;
            }
        }
        else
        {
            break;
        }
    }
}
int bfs()
{
    tn = 0;
    checkmap(tn);
    if(safemap[0][0]==0)
    {
        return 0;
    }
    queue<int> qux;
    queue<int> quy;
    qux.push(0);
    quy.push(0);
    while(!qux.empty())
    {
        int x1 = qux.front();
        int y1 = quy.front();
        qux.pop();
        quy.pop();
        for(int i=1;i<=4;i++)
        {
            int x2 = x1 + xx[i];
            int y2 = y1 + yy[i];
            if(x2<0||y2<0||x2>300||y2>300)continue;
            
            if(nowmap[x2][y2]==0)
            {
                qux.push(x2);
                quy.push(y2);
            }
            
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&m[i].x,&m[i].y,&m[i].t);
    }
    sort(m+1,m+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        safemap[m[i].x][m[i].y] = 1;
    }
    cout<<bfs();
}
