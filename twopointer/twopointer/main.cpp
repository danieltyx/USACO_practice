// 给出一个递增队列a和整数x，求数组中是否有和x
// nlogn 二分做饭
#include"bits/stdc++.h"
using namespace std;
int a[1001];
int n,m;
int erfen(int x)
{
    int l=x+1;
    int r=n;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(a[x]+a[mid]>m)
        {
            r=mid;
        }
        else if(a[x]+a[mid]<m)
        {
            l=mid;
        }
        else
        {
            cout<<a[x]<<" and "<<a[mid]<<endl;
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        if(erfen(i)==0)return 0;
    }
    cout<<"-1"<<endl;
    return 0;
}


/* 线性2 pointer 算法（更优）
#include"bits/stdc++.h"
using namespace std;
int a[10001];
int n,x;

void tp()
{
    int l=1;
    int r=n;
    while(1)
    {
        if(l==r)
        {
            cout<<"-1"<<endl;
            return;
        }
        if(a[l]+a[r]==x)
        {
            cout<<a[l]<<" and "<<a[r]<<endl;
            return;
        }
        if(a[l]+a[r]<x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
}
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    tp();
    return 0;
}
*/
