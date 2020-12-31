#include"bits/stdc++.h"
using namespace std;

const int MAXN =5000100;

struct edge
{
    int next,to,from;
};edge e[MAXN];

int ei=0;
int h[MAXN];
int n, low[MAXN], dfn[MAXN], T[MAXN];
int sCnt = 0, tCnt =0;
stack<int> st;

int ind[MAXN];
int share_com = 0;
void add(int x,int y)
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
void delete_point()
{
    int x = ei;
    ei = 0;
    memset(h,0,sizeof(h));
    memset(ind,0,sizeof(ind));
    for(int i=1;i<=x;i++)
    {
        if(T[e[i].from]!= T[e[i].to])
        {
            add(T[e[i].from],T[e[i].to]);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            int temp;
            scanf("%d",&temp);
            if(temp==0)break;
            add(i,temp);
        }
    }
    
    do_tarjan();
    delete_point();
    
    for(int i=1;i<=tCnt;i++)
    {
        if(ind[i]==0)
        {
            share_com ++;
        }
    }
    cout<<share_com<<endl;
    cout<<share_com<<endl;
}
