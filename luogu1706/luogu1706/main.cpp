#include"bits/stdc++.h"
using namespace std;
int n;
int m[101];
int u[101];
int q=1;
void printres()
{
    for(int i=1;i<=n;i++)
    {
        printf("%5d",m[i]);
    }
    puts("");
}
void dfs(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(u[i]==1)continue;
        u[i]=1;
        m[k]=i;
        if(k==n)
        {
            printres();
        }
        else
        {
            dfs(k+1);
        }
        u[i]=0;
    }
}
int main()
{
    cin>>n;
    dfs(1);
    return 0;
}
