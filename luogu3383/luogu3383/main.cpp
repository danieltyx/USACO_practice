#include "bits/stdc++.h"
using namespace std;
int n;
int m;
int u[100000010];
int prime[100000010];
int a[100000010];
int cnt =0;
int maxx =-1;


void ola()
{
    u[0] = u[1] = 1;
    for(int i=1;i<=n;i++)
    {
        if(cnt>maxx)break;
        if(u[i]!=1)
        {
            prime[++cnt] = i;
        }
        for(int j=1;j<=cnt;j++)
        {
            if(i*prime[j] > n) break;
            u[i*prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}



int main()
{
    cin>>n>>m;
    maxx = -1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>maxx)maxx=a[i];
    }
    ola();
    for(int i=1;i<=m;i++)
    {
        printf("%d\n",prime[a[i]]);
    }
}
