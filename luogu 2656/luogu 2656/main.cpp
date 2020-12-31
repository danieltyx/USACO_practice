#include"bits/stdc++.h"
#define int long long
using namespace std;
const int MAXN = 2000100;
struct edge
{
    int next,to,v,from,v2;
    float co;
};edge e[MAXN];

int T[MAXN];
int ei =0;
int h[MAXN];
int n, low[MAXN], dfn[MAXN];
int sCnt, tCnt =0;
int m;
int s;
int dis[MAXN];
int u[MAXN];
int v[MAXN];
stack<int> st;

void add(int x,int y, int v, int v2)
{
    ei++;
    e[ei].from = x;
    e[ei].to = y;
    e[ei].next = h[x];
    e[ei].v = v;
    e[ei].v2 = v2;
    h[x] = ei;
}
void tarjan(int f)
{
    sCnt ++;
    low[f]= dfn[f] = sCnt;
    st.push(f);
    for(int i = h[f]; i; i=e[i].next)
    {
        int to = e[i].to;
        if(!dfn[to])
        {
            tarjan(to);
            low[f] = min(low[f],low[to]);
        }
        else
        {
            if(!T[to])
            {
                 low[f] = min(low[f],dfn[to]);
            }
        }
    }
    if(low[f]==dfn[f])
    {
        tCnt++;
        while(1)
        {
            int tp = st.top();
            T[tp] = tCnt;
            st.pop();
            if(tp==f)
            {
                break;
            }
        }
    }
}
void do_tarjan()
{
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
}
void delete_point()
{
    int x = ei;
    ei = 0;
    memset(h,0,sizeof(h));
    for(int i=1;i<=x;i++)
    {
        if(T[e[i].from] == T[e[i].to])
        {
            v[T[e[i].from]] += e[i].v2;
            continue;
        }
        add(T[e[i].from], T[e[i].to],e[i].v,0);
    }
}
void spfa(int f)
{
    queue<int> qu;
    memset(dis,0,sizeof(dis));
    dis[f] = v[f];
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
            if(dis[to]==0 || dis[to] < dis[f1] + e[i].v + v[to])
            {
                dis[to] = dis[f1] + e[i].v + v[to] ;
                if(u[to]==0)
                {
                    u[to] = 1;
                    qu.push(to);
                }
            }
        }
    }
}
int vfull(int v, double co)
{
    int v2 = v;
    for(int i=1;v!=0;i++)
    {
        v = co * v;
        v2 += v;
    }
    return v2;
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,v;
        double co;
        scanf("%lld%lld%lld%lf",&x,&y,&v,&co);
        add(x,y,v,vfull(v,co));
    }
    cin>>s;
    do_tarjan();
    delete_point();
    s = T[s];
    spfa(s);
    int spfamax = -1;
    for(int i=1;i<=tCnt;i++)
    {
        spfamax= max(spfamax,dis[i]);
    }
    cout<<spfamax<<endl;
    return 0;
}
