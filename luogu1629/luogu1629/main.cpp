#include"bits/stdc++.h"
using namespace std;
struct edge{
    int next,to,v;
};
edge e[100100];
edge e2[100100];
int dis[100100];
int dis2[100100];
int h[100100];
int h2[100100];
int u[100100];
int ei = 0;
int ei2 = 0;
void add(int x,int y, int v)
{
    ei++;
    e[ei].to = y;
    e[ei].v = v;
    e[ei].next = h[x];
    h[x] = ei;
}
void add2(int y,int x,int v)
{
    ei2++;
    e2[ei2].to = y;
    e2[ei2].v = v;
    e2[ei2].next = h2[x];
    h2[x] = ei;
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
            if(dis[to] > dis[f1] + e[i].v)
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
void spfa2(int f)
{
    queue<int> qu;
    memset(dis2,0x3f,sizeof(dis2));
    memset(u,0,sizeof(u));
    dis2[f] = 0;
    qu.push(f);
    u[f] = 1;
    while(!qu.empty())
    {
        int f1 = qu.front();
        qu.pop();
        u[f1] = 0;
        for(int i = h2[f1];i;i=e2[i].next)
        {
            int to = e2[i].to;
            if(dis2[to] > dis2[f1] + e2[i].v)
            {
                dis2[to] = dis2[f1] + e2[i].v;
                if(u[to]==0)
                {
                    u[to] = 1;
                    qu.push(to);
                }
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        add(x,y,v);
        add2(x,y,v);
    }
    spfa(1);
    spfa2(1);
    int sum=0;
    for(int i=2;i<=n;i++)
    {
        sum += dis[i];
        sum += dis2[i];
    }
    cout<<sum;
    return 0;
}
