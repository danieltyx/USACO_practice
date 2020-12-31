#include"bits/stdc++.h"
#define int long long
using namespace std;
int a[1000100];
int d[4000400];
int lazy_add[4000400];
int lazy_mul[4000400];
int pmod;
int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
void buildtree(int l, int r, int p)
{
    if(l==r)
    {
        d[p] = a[l]  % pmod;
        return;
    }
    int m = (l + r) >> 1;
    buildtree(l , m, p << 1);
    buildtree(m + 1, r, p << 1 | 1);
    d[p] = d[p << 1] % pmod + d[p << 1 | 1] % pmod;
}

void spread(int nl, int nr, int np)
{
    if(lazy_add[np]==0 && lazy_mul[np]==1) return;
    
    int m = (nl + nr) >> 1;
    
    d[np << 1] = (long long)(d[np << 1] * lazy_mul[np] + (m - nl + 1) * lazy_add[np]) % pmod;
    d[np << 1 | 1] = (long long)(d[np << 1 | 1] * lazy_mul[np] + (nr - m) * lazy_add[np]) % pmod;
    
    lazy_mul[np << 1] =(long long) (lazy_mul[np << 1]  * lazy_mul[np]) % pmod;
    lazy_mul[np << 1 | 1] =(long long) (lazy_mul[np << 1] * lazy_mul[np]) % pmod;
    
    lazy_add[np << 1] = (long long)(lazy_add[np << 1] * lazy_mul[np] + lazy_add[np]) % pmod;
    lazy_add[np << 1 | 1] = (long long)(lazy_add[np << 1 | 1] * lazy_mul[np] + lazy_add[np]) % pmod;
    
    lazy_add[np] = 0;
    lazy_mul[np] = 1;
}

void updatetree_add(int ul, int ur, int uv, int nl, int nr, int np)
{
    
    if(ul <= nl && ur >= nr)
    {
        d[np] =(int)(d[np] + (nr - nl + 1) * uv) % pmod;
        lazy_add[np] = (lazy_add[np] + uv) % pmod;
        return;
    }
    spread(nl, nr, np);
    int m = (nl + nr) >> 1;
    if(ul <= m) updatetree_add(ul, ur, uv, nl, m,np << 1);
    if(ur > m) updatetree_add(ul, ur, uv, m + 1, nr, np << 1 | 1);
    d[np] = d[np << 1] % pmod + d[np << 1 | 1] % pmod;
}

void updatetree_mul(int ul, int ur, int uv, int nl, int nr, int np)
{
    if(ul <= nl && ur >= nr)
    {
        d[np] = (d[np] * uv) % pmod;
        lazy_mul[np] = (lazy_mul[np] * uv) % pmod;
        lazy_add[np] = (lazy_add[np] * uv) % pmod;
        return;
    }
    int m = (nl + nr) >> 1;
    spread(nl, nr, np);
    if(ul <= m) updatetree_mul(ul, ur, uv, nl, m, np << 1);
    if(ur > m) updatetree_mul(ul, ur, uv, m+1, nr, np << 1 | 1);
    d[np] = d[np << 1] % pmod + d[np << 1 | 1] % pmod;
}

int querytree(int ql, int qr, int nl, int nr, int np)
{
    if(ql <= nl && qr >= nr) return d[np];
    int m = (nl + nr) >> 1;
    spread(nl, nr, np);
    int sum = 0;
    if(ql <= m) sum = (sum + querytree(ql, qr, nl, m, np << 1)) % pmod;
    if(qr > m) sum = (sum + querytree(ql, qr, m+1, nr, np << 1 | 1)) % pmod;
    return sum % pmod;
}
signed main()
{
    int n,m;
    cin>>n>>m>>pmod;
    for(int i = 1; i<=n; i++)
    {
        a[i] = read();
    }
    for(int i=1;i <= 4 * n;i++)
    {
        lazy_mul[i] = 1;
    }
    buildtree(1,n,1);
    for(int i=1;i<=m;i++)
    {
        int a=read();
        if(a == 1)
        {
            int ul = read(),ur = read(),uv = read();
            updatetree_mul(ul,ur,uv,1,n,1);
        }
        else if(a == 2)
        {
            int ul = read(),ur = read(),uv = read();
            updatetree_add(ul,ur,uv,1,n,1);
        }
        else if(a == 3)
        {
            int ql = read(),qr = read();
            printf("%lld\n",querytree(ql,qr,1,n,1) % pmod);
        }
    }
    return 0;
}
