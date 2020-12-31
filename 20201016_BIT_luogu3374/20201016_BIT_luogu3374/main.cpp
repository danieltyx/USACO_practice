#include"bits/stdc++.h"
using namespace std;
int n,m;
int a[1001000];
int c[1001000];
int lowbit(int x)
{
    return x & -x;
}
void add(int x,int k)
{
    while(x<=n)
    {
        c[x]+= k;
        x+= lowbit(x);
    }
}
int get(int x)
{
    int res = 0;
    while(x>=1)
    {
        res+= c[x];
        x-= lowbit(x);
    }
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        add(i,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1)
        {
            add(b,c);
        }
        else if(a==2)
        {
            printf("%d\n",get(c) - get(b-1));
        }
    }
    return 0;
}
