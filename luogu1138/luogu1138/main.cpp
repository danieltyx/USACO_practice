#include"bits/stdc++.h"
using namespace std;
int a [100010];
int t [100010];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int z=1;
    for(int j=1;j<=n;j++)
    {
        //cout<<a[j]<<" ";
        if(a[j]==a[j+1]) continue;
        t[z++] = a[j];
    }
    //puts("");
    for(int i=1;i<z;i++)
    {
        //cout<<t[i]<<" ";
    }
    if(k>=z)
    {
        cout<<"NO RESULT";
        return 0;
    }

    cout<<t[k]<<endl;
    return 0;
}
