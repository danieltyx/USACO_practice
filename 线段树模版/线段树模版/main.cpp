#include"bits/stdc++.h"
using namespace std;
int a[10]={0,11,12,13,14,15,16,17,18,19};
int d[40];
int lazy[40];
void buildtree(int l,int r,int p)
{
    if(l==r)
    {
        d[p] = a[l];
        return;
    }
    int m = (l+r)/2;
    buildtree(l,m,p * 2);
    buildtree(m+1,r,p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}
/*
int querytree(int ql, int qr, int nl, int nr, int np)
{
    if(ql <= nl && qr >= nr) return d[np];
    int m = (nl + nr) / 2;
    int sum = 0;
    if(ql <= m) sum += querytree(ql, qr, nl, m, np * 2);
    if(qr > m) sum += querytree(ql, qr, m+1, nr, np * 2 + 1);
    return sum;
}
*/
void updatetree(int ul, int ur, int uv, int nl, int nr, int np)
{
    if(ul <= nl && ur >= nr)
    {
        d[np] += (nr - nl + 1) * uv;
        lazy[np] += uv;
        return;
    }
    int m = (nl + nr) / 2;
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
int main()
{
    buildtree(1,9,1);
    cout<<querytree(1,9,1,9,1)<<endl;
    updatetree(1,4,2,1,9,1);
    cout<<querytree(1,9,1,9,1)<<endl;
}
