//在数组a中找点第一个大于等于 m的值 返回下标 or -1
//默认有序表
#include"bits/stdc++.h"
using namespace std;
int a[1001];
int n;
int m;
int erfen()
{
    int l=0;
    int r=n;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(a[mid]>=m)
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return r;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    cout<<erfen()<<endl;
    return 0;
}
