#include"bits/stdc++.h"
using namespace std;
long long fastpow(long long a, long long b,int mod)
{
    long long ans = 1;
    for(;b;b=b>>1)
    {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}
int main()
{
    int b,p,k;
    cin>>b>>p>>k;
    long long fans = fastpow(b,p,k);
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<fans%k<<endl;
    return 0;

}
