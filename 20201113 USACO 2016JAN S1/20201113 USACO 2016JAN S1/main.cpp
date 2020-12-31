#include"bits/stdc++.h"
using namespace std;
int b[100100];
int n,k;
int maxn = -1;
int minn = 1000000000;
bool isokay(int x)
{
    int pointer = minn;
    for(int i=1;i<=k;i++)
    {

        pointer += 2 * x;
        if(pointer >= maxn)
        {
            return true;
        }
        pointer = b[upper_bound(b,b+n,pointer) - b];

    }
    return false;
}
int bisearch()
{
    int l = 0;
    int r = maxn;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(isokay(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}
int main()
{
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        maxn = max(maxn,b[i]);
        minn = min(minn,b[i]);
    }
    sort(b+1,b+n+1);
    cout<<bisearch()<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
