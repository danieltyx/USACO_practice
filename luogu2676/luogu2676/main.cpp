#include"bits/stdc++.h"
using namespace std;
int a[1000010];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    
    int n,m;
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(sum>=m)
        {
            cout<<i-1<<endl;
            return 0;
        }
        sum += a[i];
    }
    return 0;
}
