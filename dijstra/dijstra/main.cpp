#include"bits/stdc++.h"
using namespace std;
//STL
struct nd
{
    int id,dis;
    bool operator<(const nd&x) const// 只用更改 nd类型 e 和x
    {
        return dis>x.dis;
    }
};
priority_queue<nd> qu;//大根堆
int maxn = 999;
int u[maxn],dis[maxn];
void dij(int s)//起点
{
    nd a;
    a.id = s;
    a.dis = 0;
    dis[s] = 0;
    u[s] = 1;
    qu.push(a);
    while(!qu.empty())
    {
        int id = qu.top().id;
        int ppp = qu.top().dis;
        qu.pop();
        if(u[id]==1) continue;
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

