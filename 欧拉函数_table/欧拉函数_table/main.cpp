#include"bits/stdc++.h"
using namespace std;
int n;
int phi[1001]={0};
void ola()
{
    phi[1]=1;
    for(int i=2;i<n;i++)
    {
        if(phi[i]==0)
        {
            for(int j=i;j<n;j+=i)
            {
                if(phi[j]==0) phi[j] = j;
                phi[j] = phi[j]/i * (i - 1);
            }
        }
    }
}

int main()
{
    cin>>n;
    ola();
    for(int i=1;i<n;i++)cout<<phi[i]<<endl;
    return 0;
}
