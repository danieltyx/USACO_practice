#include"bits/stdc++.h"
using namespace std;
struct nd
{
    int id,dis;
    bool operator<(const nd&x) const
    {
        return dis>x.dis;
    }
};

struct edge
{
    int next,to,v;
};

edge e[1001000];
int ei = 0;
int h[1001000];
priority_queue<nd> qu;
int n,m,s;
int u[1001000],dis[1001000];

void add(int x,int y,int v)
{
    ei++;
    e[ei].to = y;
    e[ei].v = v;
    e[ei].next = h[x];
    h[x] = ei;
}

void dij(int s)
{
    nd a;
    a.id = s;
    a.dis = 0;
    dis[s] = 0;
    qu.push(a);
    while(!qu.empty())
    {
        int id = qu.top().id;
        int ppp = qu.top().dis;
        qu.pop();
        if(u[id]==1) continue;
        u[id] = 1;
        dis[id] = ppp;
        for(int i=h[id];i;i=e[i].next)
        {
            int to = e[i].to;
            if(u[to]==1)continue;
            nd b;
            b.id = to;
            b.dis = dis[id] + e[i].v;
            qu.push(b);
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    for(int i =1;i<=m;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        add(x,y,v);
    }
    dij(s);
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}

