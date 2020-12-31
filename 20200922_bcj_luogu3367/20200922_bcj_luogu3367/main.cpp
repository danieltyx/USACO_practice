#include"bits/stdc++.h"
using namespace std;
int ffather[100100];
int find(int x)
{
    if(x!=ffather[x])
        ffather[x] = find(ffather[x]);
    return ffather[x];
}
void makeunion(int a,int b)
{
    int t1,t2;
    t1 = find(a);
    t2 = find(b);
    ffather[t1] = t2;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        ffather[i] = i;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            if(find(b)!=find(c)) makeunion(b,c);
        }
        else
        {
            if(find(b)==find(c)) cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}
