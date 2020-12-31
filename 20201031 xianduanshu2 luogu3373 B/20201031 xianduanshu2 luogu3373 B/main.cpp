#include"bits/stdc++.h"
#define ll long long
using namespace std;
ll a[1000100];
ll read(){
    ll x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
struct Joint{
    ll l,r,sum,add,mul;
};Joint t[4000400];
int n,m;
int mod;

void buildtree(ll l, ll r, ll p)
{
    t[p].l = l;
    t[p].r = r;
    t[p].mul = 1;
    if(l == r)
    {
        t[p].sum = a[l];
        t[p].sum %= mod;
        return;
    }
    ll m = (l + r) >> 1;
    buildtree(l,m,2*p);
    buildtree(m+1,r,2*p+1);
    t[p].sum = (t[p*2].sum + t[p*2+1].sum) % mod;
}

void spread(ll p)
{
    if(t[p].add==0 && t[p].mul==1) return;
    t[2*p].sum *= t[p].mul;
    t[2*p].sum %= mod;
    t[2*p].sum += t[p].add * (t[p*2].r - t[p*2].l + 1);
    t[2*p].sum %= mod;
    
    t[2*p+1].sum *= t[p].mul;
    t[2*p+1].sum %= mod;
    t[2*p+1].sum += t[p].add * (t[p*2+1].r - t[p*2+1].l + 1);
    t[2*p+1].sum %= mod;
    
    t[2*p].mul *= t[p].mul;
    t[2*p+1].mul *= t[p].mul;
    t[2*p].mul %= mod;
    t[2*p+1].mul %= mod;
    
    t[2*p].add *= t[p].mul;
    t[2*p].add %= mod;
    t[2*p].add += t[p].add;
    t[2*p].add %= mod;
    
    t[2*p+1].add *= t[p].mul;
    t[2*p+1].add %= mod;
    t[2*p+1].add += t[p].add;
    t[2*p+1].add %= mod;
    
    t[p].add = 0;
    t[p].mul = 1;
}
void updatetree_add(ll l, ll r, ll k, ll p)
{
    if(l <= t[p].l && r >= t[p].r)
    {
        t[p].sum = (t[p].sum + (t[p].r - t[p].l + 1) * k) % mod;
        t[p].add = (t[p].add + k) % mod;
        return;
    }
    spread(p);
    t[p].sum= (t[p*2].sum + t[p*2+1].sum) % mod;
    ll m = (t[p].l + t[p].r) >> 1;
    if(l <= m) updatetree_add(l,r,k,2*p);
    if(r > m) updatetree_add(l,r,k,2*p+1);
    t[p].sum = (t[p*2].sum + t[p*2+1].sum) % mod;
}

void updatetree_mul(ll l, ll r, ll k, ll p)
{
    if(l <= t[p].l && r >= t[p].r)
    {
        t[p].mul *= k;
        t[p].mul %= mod;
        t[p].add *= k;
        t[p].add %= mod;
        t[p].sum *= k;
        t[p].sum %= mod;
        return;
    }
    spread(p);
    ll m = (t[p].l + t[p].r) >> 1;
    if(l <= m) updatetree_mul(l,r,k,2*p);
    if(r > m) updatetree_mul(l,r,k,2*p+1);
    t[p].sum = (t[p*2].sum + t[p*2+1].sum) % mod;
}

ll querytree(ll l, ll r,ll p)
{
    if(l <= t[p].l && r >= t[p].r)
    {
        return t[p].sum;
    }
    spread(p);
    ll m = (t[p].r + t[p].l) >> 1;
    ll ans = 0;
    if(l <= m) ans += querytree(l,r,2*p);
    ans %= mod;
    if(r > m) ans += querytree(l,r,2*p+1);
    ans %= mod;
    return ans;
}
int main()
{
    cin>>n>>m>>mod;
    for(int i = 1; i<=n; i++)
    {
        a[i] = read();
    }
    buildtree(1,n,1);
    for(int i=1;i<=m;i++)
    {
        ll a=read();
        if(a == 1)
        {
            ll ul = read(),ur = read(),uv = read();
            updatetree_mul(ul,ur,uv,1);
        }
        else if(a == 2)
        {
            ll ul = read(),ur = read(),uv = read();
            updatetree_add(ul,ur,uv,1);
        }
        else if(a == 3)
        {
            ll ql = read(),qr = read();
            printf("%lld\n",querytree(ql,qr,1));
        }
    }
    return 0;
}
