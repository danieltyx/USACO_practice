#include"bits/stdc++.h"
using namespace std;
int s[1000010];
int o[1000010];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&o[i]);
    }
    s[1] = o[1];
    for(int i=2;i<=n;i++)
    {
        s[i] = o[i] + s[i-1];
    }
    int maxx = -1;
    for(int i=1;i<=n-k;i++)
    {
        maxx = max(maxx, s[i+k] - s[i]);
    }
    cout<<maxx<<endl;
    return 0;
}
