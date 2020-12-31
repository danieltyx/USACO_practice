#include"bits/stdc++.h"
using namespace std;
map<int,vector<int> > mp;
int res =0;
int n;
int v[100010];
void dfs(int x)
{
    v[x] = 1;
    int len = mp[x].size();
    if(len!=1)
    {
        int log2len = log2(len);
        if(pow(2,log2len) != len) log2len++;
        if(log2len==0) log2len++;
        res += log2len;
    }
    for(int i=0;i<len;i++)
    {
        if(v[mp[x].at(i)]==1)continue;
        res++;
        dfs(mp[x].at(i));
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    dfs(1);
    cout<<res<<endl;
}
