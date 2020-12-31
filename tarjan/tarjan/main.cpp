//全联通
#include"bits/stdc++.h"
using namespace std;

struct edge{
    int next, to,v;
};edge e[1001000];
int h[1001000];
int ei = 0;

const int MAXN =1000;
int n, low[MAXN], dfn[MAXN], T[MAXN];
int sCnt = 0, tCnt =0;
stack<int> st;


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
            if(!T[f])
            {
                 low[f] = min(low[f], dfn[to]);
            }
        }
    }
    if(low[f]==dfn[f])
    {
        tCnt++;
        while(1)
        {
            int tp = st.top();
            T[tp]= tCnt;
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

