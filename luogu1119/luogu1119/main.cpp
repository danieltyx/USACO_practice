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
int t[1001000];
int ra[1001000];
int rb[1000100];
int rt[1001000];
int n,m;
int mt;
int u[1001000],dis[1001000];

void add(int x,int y,int v)
{
    ei++;
    e[ei].to = y;
    e[ei].v = v;
    e[ei].next = h[x];
    h[x] = ei;
}
void dij(int s,int tt)
{
    priority_queue<nd> qu;
    memset(dis,0x3f,sizeof(dis));
    memset(u,0,sizeof(u));
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
        if(t[id]>tt) continue;
        u[id] = 1;
        dis[id] = ppp;
        for(int i=h[id];i;i=e[i].next)
        {
            if(t[i]>tt) continue;
            int to = e[i].to;
            if(u[to]==1)continue;
            if(t[to]>tt) continue;
            nd b;
            b.id = to;
            b.dis = dis[id] + e[i].v;
            qu.push(b);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
    }
    for(int i =1;i<=m;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        add(x,y,v);
        add(y,x,v);
    }
    cin>>mt;
    for(int i=1;i<=mt;i++)
    {
        scanf("%d%d%d",&ra[i],&rb[i],&rt[i]);
    }
    for(int i=1;i<=mt;i++)
    {
        if(t[ra[i]]>rt[i])
        {
            cout<<"-1"<<endl;
            continue;
        }
        int fdis= -1;
        dij(ra[i],rt[i]);
        if(dis[rb[i]]==0x3f3f3f3f) fdis = -1;
            else fdis = dis[rb[i]];
        dij(rb[i],rt[i]);
        if(dis[ra[i]]==0x3f3f3f3f) fdis = -1;
        else fdis = max(fdis,dis[ra[i]]);
        cout<<fdis<<endl;
        
    }
    return 0;
}
