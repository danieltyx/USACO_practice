#include"bits/stdc++.h"
#define int long long
using namespace std;
int a[1000100];
int d[4000400];
int d2[4000400];
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
    d[p] = max(d[p * 2], d[p * 2 + 1]);
}

int querytree(int ql, int qr, int nl, int nr, int np)
{
    if(ql <= nl && qr >= nr) return d[np];
    int m = (nl + nr) / 2;
    int maxx = -9999999999999999;
    if(ql <= m) maxx = max(maxx,querytree(ql, qr, nl, m, np * 2));
    if(qr > m) maxx = max(maxx, querytree(ql, qr, m+1, nr, np * 2 + 1));
    return maxx;
}
void buildtree2(int l, int r, int p)
{
    if(l==r)
    {
        d2[p] = a[l];
        return;
    }
    int m = (l + r) / 2;
    buildtree2(l , m, p * 2);
    buildtree2(m + 1, r, p * 2 + 1);
    d2[p] = min(d2[p * 2], d2[p * 2 + 1]);
}
int querytree2(int ql, int qr, int nl, int nr, int np)
{
    if(ql <= nl && qr >= nr) return d2[np];
    int m = (nl + nr) / 2;
    int minn = 9999999999999999;
    if(ql <= m) minn = min(minn,querytree2(ql, qr, nl, m, np * 2));
    if(qr > m) minn = min(minn, querytree2(ql, qr, m+1, nr, np * 2 + 1));
    return minn;
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
    buildtree2(1,n,1);
    for(int i=1;i<=n-m+1;i++)
    {
        cout<<querytree2(i,i+m-1,1,n,1)<<" ";
    }
    puts("");
    for(int i=1;i<=n-m+1;i++)
    {
        cout<<querytree(i,i+m-1,1,n,1)<<" ";
    }
    return 0;
}
