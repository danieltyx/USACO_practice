#define LENS 1004
#include"bits/stdc++.h"
using namespace std;
int a[LENS];
int b[LENS];
int c[LENS];
int i =0;
void read()
{
    char x[LENS] = (char)i,y[LENS];
    int lenx = strlen(x);
    int leny = strlen(y);
    for(int i = 0;i < lenx;i++)
    {
        a[lenx - i - 1] = x[i] - '0';
    }
    for(int i = 0; i < leny; i++)
    {
        b[leny - i - 1] = y[i] - '0';
    }
}
void muti()
{
    for(int i=0;i<LENS-1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            c[i] += a[j] * b[i-j];
        }
        if(c[i]>=10)
        {
            c[i+1] += c[i]/10;
            c[i] = c[i]%10;
        }
    }
}
void print()
{
    int i;
    for(i=LENS-1;i>=1;i--)
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
    int n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        
    }
    read();
    muti();
    print();
    return 0;
}
