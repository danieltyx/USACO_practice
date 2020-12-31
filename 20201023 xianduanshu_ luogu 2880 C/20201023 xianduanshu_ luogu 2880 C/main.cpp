#include"bits/stdc++.h"
using namespace std;
int a[10001000];
int da[40004000];
int di[40004000];
void buildmaxtree(int l, int r, int p)
{
    if(l == r)
    {
        da[p] = a[l];
        return;
    }
    int m = (l + r) / 2;
    buildmaxtree(l, m, 2 * p);
    buildmaxtree(m + 1, r, 2 * p + 1);
    da[p] = max(da[p * 2], da[p * 2 + 1]);
}
void buildmintree(int l, int r, int p)
{
    if(l == r)
    {
        di[p] = a[l];
        return;
    }
    int m = (l + r) / 2;
    buildmintree(l, m, 2 * p);
    buildmintree(m + 1, r, 2 * p + 1);
    di[p] = min(di[p * 2], di[p * 2 + 1]);
}
int querymaxtree(int ql, int qr, int nl, int nr, int np)
{
    if(ql <= nl && qr >= nr)
    {
        return da[np];
    }
    int m = (nl + nr) / 2;
    int maxx = -1 ;
    if(ql <= m)  maxx = max(maxx,querymaxtree(ql, qr, nl, m, np * 2));
    if(qr > m) maxx = max(maxx, querymaxtree(ql, qr, m + 1, nr, np * 2 + 1));
    return maxx;
}
int querymintree(int ql, int qr, int nl, int nr, int np)
{
    if(ql <= nl && qr >= nr)
    {
        return di[np];
    }
    int m = (nl + nr) / 2;
    int minn = 2147483646;
    if(ql <= m)  minn = min(minn,querymintree(ql, qr, nl, m, np * 2));
    if(qr > m) minn = min(minn, querymintree(ql, qr, m + 1, nr, np * 2 + 1));
    return minn;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    buildmintree(1, n, 1);
    buildmaxtree(1, n, 1);
//    for(int i = 1; i <= 13; i++)
//    {
//        cout<<da[i]<<" "<<di[i]<<endl;
//    }
    for(int i = 1;i <= m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int maxx = querymaxtree(a,b,1,n,1);
        int minn = querymintree(a,b,1,n,1);
        cout<<maxx - minn<<endl;
        
    }
    
    return 0;
}

/*6 3
 1
 7
 3
 4
 2
 5
 1 5
 4 6
 2 2 */
