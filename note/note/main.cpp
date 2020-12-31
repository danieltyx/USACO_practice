#include"bits/stdc++.h"
using namespace std;
int a[10001];
int f[10001];
int main()
{
    int n;
    cin>>n;
    int ans =0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int mx=0;
        for(int j=1;j<i;j++)
        {
            if(a[j]>a[i])
            {
                mx = max(mx,f[i]);
            }
        }
        f[i]=mx+1;
        ans = max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}
