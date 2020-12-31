#include"bits/stdc++.h"
#define int long long
using namespace std;
const int MAXN = 500000;
struct edge
{
    int next,to,from;
};edge e[MAXN];
int ei=0;
int h[MAXN];
int ind[MAXN];
int dep[MAXN];
int sCnt =0;
int tCnt =0;
int low[MAXN];
int dfn[MAXN];
int T[MAXN];
stack<int> st;
int n,m;
void add(int x, int y)
{
    ei++;
    e[ei].from = x;
    e[ei].to = y;
    e[ei].next = h[x];
    h[x] = ei;
    ind[y]++;
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
    memset(ind,0,sizeof(ind));
    
    for(int i=1;i<=x;i++)
    {
        int tfrom = T[e[i].from];
        int tto = T[e[i].to];
        if(tfrom != tto)
        {
            add(tfrom, tto);
        }
    }
}
void top_sort()
{
    queue<int> qu;
    for(int i=1;i<=n;i++)
    {
        if(ind[i] == 0)
        {
            qu.push(i);
            dep[i] = 1;
        }
    }
    while(!qu.empty())
    {
        int f1 = qu.front();
        qu.pop();
        for(int i = h[f1]; i!=0; i=e[i].next)
        {
            int to = e[i].to;
            dep[to] = max(dep[to],dep[f1]+1);
            ind[to]--;
            if(ind[to]==0)
            {
                qu.push(to);
            }
        }
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%lld%lld",&a,&b);
        add(a,b);
        
    }
    do_tarjan();
    delete_point();
    int ans =0;
    int num_ind0 = 0;
    for(int i=1;i<=tCnt;i++)
    {
        if(num_ind0>1)
        {
            cout<<0<<endl;
            return 0;
        }
        if(ind[i]==0)
        {
            num_ind0++;
            top_sort();
        }
        
        int maxdep=-1;
        for(int i=1;i<=n;i++)
        {
            maxdep=max(maxdep,dep[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(dep[i]==maxdep)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
