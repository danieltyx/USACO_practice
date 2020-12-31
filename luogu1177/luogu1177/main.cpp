#include"bits/stdc++.h"
using namespace std;
int a[100010];
int t[100010];
void mergesort(int l, int r)
{
    if(l==r) return;
    int mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    int p = l;
    int q = mid+1;
    int i = l;
    while(p<=mid && q<=r)
    {
        if(a[p]<a[q])
        {
            t[i++] = a[p++];
        }
        else
        {
            t[i++] = a[q++];
        }
    }
    while(p<=mid)
    {
        t[i++] = a[p++];
    }
    while(q<=r)
    {
        t[i++] = a[q++];
    }
    for(int i=l;i<=r;i++)
    {
        a[i] = t[i];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(1,n);
    for(int i=1;i<=n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[n]<<endl;
    return 0;
}
