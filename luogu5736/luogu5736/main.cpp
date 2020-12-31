#include"bits/stdc++.h"
using namespace std;
vector<int> vc;
int primecheck(int x)
{
     if(x==1) return 0;//0 is not
     if(x==2)return 1;// 1 is prime
    for(int i=2;i<x;i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}
int main()
{
    int n;
    int k;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        vc.push_back(k);
    }
    for(int i=0;i<vc.size();)
    {
        if(primecheck(vc[i])==0)
           {
                vc.erase(vc.begin()+i);
                continue;
           }
        i++;
    }
    int lengthvc  = vc.size();
    for(int i=0;i<lengthvc;i++)
    {
        cout<<vc[i]<<" ";
    }
    return 0;
}
