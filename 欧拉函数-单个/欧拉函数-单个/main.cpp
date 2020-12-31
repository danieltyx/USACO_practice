#include"bits/stdc++.h"
using namespace std;
int n;
int ans;
void hola()
{
    ans=n;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            //cout<<"ans before"<<ans<<"  ";
            ans = ans/i *(i-1);// ans = ans*(1-ans/i)
            //cout<<"i:  "<<i<<"   ans_After:"<<ans<<endl;
            while(n%i==0) n/=i;
        }
    }
    if(n>1)
    {
        ans = ans/n * (n -1);
    }
}
int main()
{
    cin>>n;
    hola();
    cout<<ans;
    return 0;
}
