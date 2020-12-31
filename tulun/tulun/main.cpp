//luogu P4779 【模板】单源最短路径（标准版）
//TLE 
#include"bits/stdc++.h"
#define int long long
using namespace std;
int h[1001000];
int ei = 0;
int dis[1001000];
int u[1001000];
struct edge{
    int next, to,v;
};edge e[1001000];
void add(int x,int y,int v)
{
    ei++;
    e[ei].to = y;
    e[ei].v = v;
    e[ei].next = h[x];
    h[x] = ei;
}
void spfa(int f)
{
    queue<int> qu;
    memset(dis,0x3f,sizeof(dis));
    dis[f] = 0;
    qu.push(f);
    u[f] = 1;
    while(!qu.empty())
    {
        int f1 = qu.front();
        qu.pop();
        u[f1] = 0;
        for(int i = h[f1];i;i=e[i].next)
        {
            int to = e[i].to;
            if(dis[to]> dis[f1] + e[i].v)
            {
                dis[to] = dis[f1] + e[i].v;
                if(u[to]==0)
                {
                    u[to] = 1;
                    qu.push(to);
                }
            }
        }
    }
}
signed main()
{
    int n,m,s;
    cin>>n;
    cin>>m;
    cin>>s;
    for(int i=1;i<=m;i++)
    {
        int x,y,v;
        scanf("%lld%lld%lld",&x,&y,&v);
        add(x,y,v);
    }
    spfa(s);
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}
