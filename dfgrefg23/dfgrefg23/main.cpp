#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define maxn 50
using namespace std;
int n,m,p,q,ansm=0,ansf=0,father[maxn];
int find(int x)
{
    if(father[x]!=x) father[x]=find(father[x]);
    return father[x];
}
void unionn(int x,int y)
{
    int r1=find(x);
    int r2=find(y);
    father[r2]=r1;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(int i=1;i<=n+m;++i)
     father[i]=i;
    for(int i=1;i<=p;++i)
     {
         int a,b;
         scanf("%d%d",&a,&b);
         if(find(a)!=find(b))
          unionn(a,b);
     }
    for(int i=1;i<=q;++i)
     {
         int a,b;
         scanf("%d%d",&a,&b);
         a*=-1;b*=-1;
         if(find(a+n)!=find(b+n))
          unionn(a+n,b+n);
     }
    for(int i=1;i<=n;++i)
     if(find(i)==find(1))
      ansm++;
    for(int i=n+1;i<=n+m;++i)
     if(find(i)==find(n+1))
      ansf++;
    printf("%d",min(ansf,ansm));
    return 0;
}
