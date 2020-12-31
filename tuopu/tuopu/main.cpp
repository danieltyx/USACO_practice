#include"bits/stdc++.h"
using namespace std;
int stops[1010][1010];
int dep[1010],ind[1010];
int n,m;
int mp[1010][1010];
int u[1010];
void add(int x,int y)
{
    if(mp[x][y]==1)return;
    mp[x][y] = 1;
    ind[y]++;
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
        for(int i =1;i<=n;i++)
        {
            int to = i;
            if(mp[f1][to]==0)
            {
                continue;
            }
            dep[to] = max(dep[to],dep[f1]+1);
            ind[to] --;
            if(ind[to]==0)
            {
                qu.push(to);
            }
        }
    }
}
int in[1010];
int inindex = 0;
int out[1010];
int outindex =0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        inindex = 0;
        outindex = 0;
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        int last = -1;
        for(int j=1;j<=t;j++)
        {
            int k;
            scanf("%d",&k);
            in[++inindex] = k;
            if(j>1)
            {
                for(int q=last+1;q<k;q++)
                {
                    out[++outindex] = q;
                }
            }
            last = k;
        }
        for(int z=1;z<=inindex;z++)
        {
            for(int zz=1;zz<=outindex;zz++)
            {
                add(in[z],out[zz]);
            }
        }
    }
    
    top_sort();
    
    int max_dep = -1;
    for(int i=1;i<=n;i++)
    {
        max_dep = max(max_dep,dep[i]);
    }
    cout<<max_dep<<endl;
    return 0;
}
