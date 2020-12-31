#include"bits/stdc++.h"
using namespace std;
int f[1000001];
struct city{
    int a;
    int b;
};city ct[1000001];
bool cmp(city aa,city bb)
{

        return aa.a<bb.a;
    
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&ct[i].a,&ct[i].b);
    }
    sort(ct+1,ct+n+1,cmp);
    memset(f,0x3f,sizeof(f));
    int len =0;
    for(int i=1;i<=n;i++)
    {
        int pos = upper_bound(f+1,f+1+len,ct[i].b) - f;
        if(pos==len+1)
        {
            len++;
        }
        f[pos]=min(f[pos],ct[i].b);
    }
    cout<<len;
    return 0;
}
