#include"bits/stdc++.h"
#define int long long
using namespace std;
int a[100100];
int d[400400];
int lazy[400400];
void buildtree(int l, int r, int p)
{
    if(l==r)
    {
        d[p] = a[l];
        return;
    }
    int m = (l + r) / 2;
    buildtree(l , m, p * 2);
    buildtree(m + 1, r, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}
void updatetree(int ul, int ur, int uv, int nl, int nr, int np)
{
    if(ul <= nl && ur >= nr)
    {
        d[np] += (nr - nl + 1) * uv;
        lazy[np] += uv;
        return;
    }
    int m = (nl + nr) / 2;
    if(lazy[np] && nl!=nr)
    {
        d[np * 2] += (m - nl + 1) * lazy[np];
        d[np * 2 + 1] += (nr - m) * lazy[np];
        lazy[np * 2] += lazy[np];
        lazy[np * 2 + 1] += lazy[np];
        lazy[np] = 0;
    }
    if(ul <= m) updatetree(ul, ur, uv, nl, m, np * 2);
    if(ur > m) updatetree(ul, ur, uv, m+1, nr, np * 2 + 1);
    d[np] = d[np * 2] + d[np * 2 + 1];
}
int querytree(int ql, int qr, int nl, int nr, int np)
{
    if(ql <= nl && qr >= nr) return d[np];
    int m = (nl + nr) / 2;
    if(lazy[np])
    {
        d[np * 2] += (m - nl + 1) * lazy[np];
        d[np * 2 + 1] += (nr - m) * lazy[np];
        lazy[np * 2] += lazy[np];
        lazy[np * 2 + 1] += lazy[np];
        lazy[np] = 0;
    }
    int sum = 0;
    if(ql <= m) sum += querytree(ql, qr, nl, m, np * 2);
    if(qr > m) sum += querytree(ql, qr, m+1, nr, np * 2 + 1);
    return sum;
}
signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    buildtree(1,n,1);
    for(int i=1;i<=m;i++)
    {
        int a;
        scanf("%lld",&a);
        if(a == 1)
        {
            int ul,ur,uv;
            scanf("%lld%lld%lld",&ul,&ur,&uv);
            updatetree(ul,ur,uv,1,n,1);
        }
        else if(a == 2)
        {
            int ql, qr;
            scanf("%lld%lld",&ql,&qr);
            printf("%lld\n",querytree(ql,qr,1,n,1));
        }
    }
    return 0;
}
