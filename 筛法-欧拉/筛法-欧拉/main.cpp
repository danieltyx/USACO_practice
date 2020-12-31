#include"bits/stdc++.h"
using namespace std;
int n;
int u[100010];
int prime[100010];
int cnt = 0;
void ola()
{
    u[0] = u[1] = 1;
    for(int i=1;i<=n;i++)
    {
        if(u[i]!=1)
        {
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++)
       {
           if(i*prime[j]>n) break;
           u[i*prime[j]] = 1;
           if(i%prime[j]==0) break;
       }
    }
}


int main()
{
    cin>>n;
    ola();
    for(int i=1;i<=cnt;i++)cout<<prime[i]<<endl;
    return 0;
}
