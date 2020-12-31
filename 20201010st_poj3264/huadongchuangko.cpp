
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int f[2000100][30];
int ma[2000100];
int mi[2000100];

inline int read()
{
    int x=0;
    int f=1;
    char ch=getchar();
    while (!isdigit(ch))
    {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (isdigit(ch))
    {
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
int main()
{
    int n = read();
    int m = read();
    for(int i=1;i<=n;i++)
    {
        f[i][0] = read();
    
    }
    for(int j=1; j<=21;j++)
    {
        for(int i=1;i + (1<<j) -1 <=n;i++)
        {
            f[i][j] = max(f[i][j-1],
                          f[i + (1<<(j-1))][j-1]);
            
        }
    }
    for(int i=1;i<=n-m+1;i++)
    {
        int l = i;
        int r = i+m-1;
        int s = log((double)(r - l + 1))/log(2.0);
        ma[i] = max(f[l][s],
                   f[r-(1 << s)+ 1][s]);
    }
    for(int i=1;i<=n-m+1;i++)
    {
        printf("%d ",ma[i]);
    }
    puts("");
        
    for(int j=1; j<=21;j++)
    {
        for(int i=1;i + (1<<j) -1 <=n;i++)
        {
            f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
        }
    }
    
    for(int i=1;i<=n-m+1;i++)
    {
        int l = i;
        int r = i+m-1;
        int s = log((double)(r - l + 1))/log(2.0);
        mi[i] = min(f[l][s],
                f[r-(1 << s)+ 1][s]);
    }
    for(int i=1;i<=n-m+1;i++)
    {
        printf("%d ",mi[i]);
    }

    puts("");
    return 0;
}
