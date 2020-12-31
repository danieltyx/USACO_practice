#include"bits/stdc++.h"
using namespace std;
int a[1001];
bool cmp(int x,int y)
{
    return x<y;//< 从小到大
    //return x>y；//c> 从大到小
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
