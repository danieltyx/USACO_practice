#include"bits/stdc++.h"
using namespace std;
int s[1001000];
int main()
{
    int n,m;
    cin>>n>>m;
    int maxs = -1;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        s[i] = t;
        maxs = max(maxs,t);
    }
    int l = maxs;
    int r = maxs * n;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(mid == r||mid == l)break;
        int ss = 0;
        int cnt= 1;
        for(int i=1;i<=n;i++)
        {
            ss += s[i];
            if(ss>=mid)
            {
                cnt++;
                i--;
                ss=0;
            }
        }
        if(cnt>m)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout<<l;
    return 0;
}
