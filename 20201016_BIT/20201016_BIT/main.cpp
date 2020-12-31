#include"bits/stdc++.h"
using namespace std;
int a[9] = {0,1,2,3,4,5,6,7,8};
int c[9];
int n = 8;
int lowbit(int x)
{
    return x & -x;
}
void add(int x,int k)
{
    while(x<=n)
    {
        c[x]+= k;
        x+= lowbit(x);
    }
}
int get(int x)
{
    int res = 0;
    while(x>=1)
    {
        res+= c[x];
        x-= lowbit(x);
    }
    return res;
}
int main()
{
    for(int i=1;i<=8;i++)
    {
        add(a[i],a[i]);
    }
    cout<<"sum from 1 to i"<<endl;
    for(int i=1;i<=8;i++)
    {
        cout<<get(i)<<endl;
    }
    cout<<"c[1]->c[8]"<<endl;
    for(int i=1;i<=8;i++)
    {
        cout<<c[i]<<endl;
    }
    cout<<lowbit(4)<<endl;
    return 0;
}
