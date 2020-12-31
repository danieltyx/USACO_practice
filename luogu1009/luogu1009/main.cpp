#define LENS 1050
#define MAXL 150
#include"bits/stdc++.h"
int a[LENS];
int b[LENS];
int c[LENS];
int d[LENS];
int e[LENS];

using namespace std;
void muti(int x)
{
    for(int i=0;i<=MAXL;i++)
    {
        a[i] = c[i];
    }
    memset(c,0,sizeof(c));
    for(int i=0;i<LENS-1;i++)
    {
        c[i] += a[i] * x;
        if(c[i]>=10)
        {
            c[i+1]  += c[i]/10;
            c[i] %=10;
        }
    }
}

void addder(int x)
{
    for(int i=0;i<MAXL;i++)
    {
        d[i] = e[i];
    }
    memset(e,0,sizeof(e));
    for(int i=0;i<LENS-1;i++)
    {
        e[i] += d[i]+c[i];
        if(e[i]>=10)
        {
            e[i+1]++;
            e[i]%=10;
        }
    }
}
void printresult()
{
    int i;
    for(i=LENS;i>=1;i--)
    {
        if(e[i]!=0)break;
    }
    for(;i>=0;i--)
    {
        cout<<e[i];
    }
}

int main()
{
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(e,0,sizeof(e));
    
    
    e[0] = 1;
    c[0] = 1;

    for(int i=2;i<=n;i++)
    {
        muti(i);
        addder(i);
    }
    printresult();
    return 0;
}
