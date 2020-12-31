//在数组a中找点第一个大于等于 m的值 返回下标 or -1
//默认有序表
#include"bits/stdc++.h"
using namespace std;
int a[1001];
int n = 4;
int erfen(int m)
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
    if(a[r] == m) return r;
    else return l;
}
int main()
{
    int m,m2;
    cin>>m>>m2;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    cout<<erfen(m)<<" "<<erfen(m2)<<endl;
    return 0;
}
