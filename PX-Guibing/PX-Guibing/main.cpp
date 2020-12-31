//归并排序
//基于分治的思想
/*一分为二
 eg[1,8,2,7,3,6,4,5]
 [1,8,2,7]  [3,6,4,5]
 [1,2,3,4,5,6,7,8]
 */
//复杂度 ：o(nlogn)
#include"bits/stdc++.h"
using namespace std;
int a[10] = {0,1,2,5,7,8,2,2,1};
int tempr[10];
int n = 8;
void mergesort(int l,int r)
{
    if(l==r) return;
    int mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    int i = l;
    int p = l;
    int q = mid+1;
    while(p<=mid && q<=r)
    {
        if(a[q]>a[p])
        {
            tempr[i] = a[p];
            p++;
            i++;
        }
        else
        {
            tempr[i] = a[q];
            q++;
            i++;
        }
    }
    while(p<=mid)
    {
        tempr[i] = a[p];
        i++;
        p++;
    }
    while(q<=r)
    {
        tempr[i] = a[q];
        i++;
        q++;
    }
    for(int i=l;i<=r;i++)
    {
        a[i] = tempr[i];
    }
}
int main()
{
    mergesort(1,8);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
