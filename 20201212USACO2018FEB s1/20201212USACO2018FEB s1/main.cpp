#include"bits/stdc++.h"
#define ll long long
using namespace std;
struct Stopp{
    ll dis;
    ll val;
};
Stopp sp[400010];
ll s[400100];
ll l,n,rf,rb;
ll ct = 0;
int main()
{
    freopen("reststops.in","r",stdin);
    freopen("reststops.out","w",stdout);
    cin>>l>>n>>rf>>rb;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld",&sp[i].dis,&sp[i].val);
    }
    s[n] = sp[n].val;
    for(ll i=n-1;i>=1;i--)
    {
        s[i] = max(sp[i].val,s[i+1]);
    }
    ll ans = 0;
    for(ll i=1;i<=n;i++)
    {
        if(s[i]!=s[i+1])
        {
            ans += (sp[i].dis-ct)*(rf-rb)*sp[i].val;
            ct = sp[i].dis;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
20 10 5 3
2 5
3 1
6 2
8 5
9 1
10 1
11 3
13 1
14 2
15 1
 
*/
