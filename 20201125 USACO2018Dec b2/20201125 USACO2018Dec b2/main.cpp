#include"bits/stdc++.h"
using namespace std;
const int TIME = 2000;
int mp[TIME];
int main()
{
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int s,t,b;
        cin>>s>>t>>b;
        for(int j=s;j<=t;j++)
        {
            mp[j] += b;
        }
    }
    int maxn = 0;
    for(int i=1;i<TIME;i++)
    {
        maxn = max(maxn,mp[i]);
    }
    cout<<maxn<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
