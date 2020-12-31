#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<n;
    puts("");
    int a[110];
    for(int i=1;i<=n;i++)
    {
        a[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j!=i)
            {
                a[j] = 1-a[j];
            }
        }
        for(int i =1;i<=n;i++)
        {
            cout<<a[i];
        }
        puts("");
    }
    return 0;
}
