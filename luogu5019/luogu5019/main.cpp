#include"bits/stdc++.h"
using namespace std;
int r[100010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&r[i]);
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(r[i+1]>r[i])
        {
            continue;
        }
        else
        {
            ans+=r[i]-r[i+1];
        }
    }
    ans+=r[n];
    cout<<ans<<endl;
    return 0;
}
