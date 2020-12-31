#define LENS 1004
#include"bits/stdc++.h"
using namespace std;
int a[1004];
int b[1004];
int c[1004];
void clear()
{
    for(int i=1;i<=LENS;i++)
    {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }
}
void read()
{
    char s[LENS],ss[LENS];
    cin>>s>>ss;
    int len_s = strlen(s);
    int len_ss = strlen(ss);
    for(int i = 0; i<len_s;i++)
    {
        a[len_s-i-1] = s[i] - '0';
    }
    for(int i = 0; i<len_ss;i++)
    {
        b[len_ss-i-1] = ss[i] - '0';
    }
}
void add()
{
    for(int i=0;i<=LENS-1;i++)
    {
        c[i] += a[i]+b[i];
        if(c[i]>=10)
        {
            c[i+1]++;
            c[i]-= 10;
        }
    }
}
void print()
{
    int i;
    for(i=LENS; i>=1;i--)
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
    clear();
    read();
    add();
    print();
    return 0;
}

