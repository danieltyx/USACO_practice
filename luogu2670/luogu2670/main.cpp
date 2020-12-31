#include"bits/stdc++.h"
using namespace std;
int a[1001][1001];
int main()
{
    int n,m;
    char k;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>k;
            if(k== '*') a[i][j]=1;
            else a[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)
            {
                cout<<"*";
                continue;
            }
            else
            {
                int sum = a[i+1][j] +
                          a[i+1][j+1] +
                          a[i+1][j-1] +
                        a[i-1][j] +
                        a[i-1][j+1] +
                        a[i-1][j-1] +
                a[i][j+1]+a[i][j-1];
                cout<<sum;
            }
        }
        puts("");
    }
    return 0;
}
