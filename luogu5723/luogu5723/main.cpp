#include"bits/stdc++.h"
using namespace std;
bool primecheck(int x)
{
    if(x==1)return false;
    if(x==2)return true;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int sum = 0;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(primecheck(i)==true)
        {
            sum+=i;
            if(sum>n)break;
            cout<<i<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
