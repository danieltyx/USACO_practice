#define LENS 10004
#include"bits/stdc++.h"
using namespace std;
int a[LENS];
int b[LENS];
int c[LENS];
void read()
{
    char x[LENS],y[LENS];
    cin>>x>>y;
    int lenx = strlen(x);
    int leny = strlen(y);
    for(int i=0;i<lenx;i++)
    {
        a[lenx - i - 1] = x[i]- '0';
    }
    for(int i=0;i<leny;i++)
    {
        b[leny - i - 1] = y[i] -'0';
    }
}

void muti()
{
    for(int i=0;i< LENS-1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            c[i] += a[j] * b[j+1];
            cout<<i<<" "<<j<<endl;
        }
        if(c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
}
void print()
{
    int i;
    for(i=LENS; i>=1 ;i--)
    {
        if(c[i]!=0)break;
    }
    for(;i>=0;i--)
    {
        cout<<c[i];
    }
}
int main()
{
    read();
    muti();
    print();
}
