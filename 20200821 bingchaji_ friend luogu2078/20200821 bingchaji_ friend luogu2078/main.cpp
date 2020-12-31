#include"bits/stdc++.h"
using namespace std;
int mf[10100];
int hf[10100];
int find(int x) {
  if (x != mf[x])
    mf[x] = find(mf[x]);
  return mf[x];
}
int find2(int x) {
  if (x != hf[x])
    hf[x] = find2(hf[x]);
  return hf[x];
}
void makeunion(int a,int b)
{
    int t1,t2;
    t1 = find(a);
    t2 = find(b);
    mf[t1] = t2;
}

void makeunion2(int a,int b)
{
    int t1,t2;
    t1 = find2(a);
    t2 = find2(b);
    hf[t1] = t2;
}

int main()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    
    for(int i=1;i<=n;i++) mf[i] = i;
    for(int i=1;i<=m;i++) hf[i] = i;
    
    for(int i=1;i<=p;i++)
    {
        int a,b;
        cin>>a>>b;
        if(find(a)!=find(b)) makeunion(a,b);
    }
    
    
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin>>a>>b;
        a = -a;
        b = -b;
        if(find2(a)!=find2(b)) makeunion2(a,b);
    }
    
    int cntm=0, cnth=0;
    for(int i=1;i<=n;i++)
    {
        if(find(i)==find(1))cntm++;
    }
    for(int i=1;i<=m;i++)
    {
        if(find2(i)==find2(1))cnth++;
    }
    cout<<min(cntm,cnth);
    return 0;
}
