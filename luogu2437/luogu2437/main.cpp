#include"bits/stdc++.h"
using namespace std;
int f[10001];
int main()
{
    int m,n;
    cin>>m>>n;
    int d = n-m;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=2000;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    cout<<f[d]<<endl;
    return 0;
}
