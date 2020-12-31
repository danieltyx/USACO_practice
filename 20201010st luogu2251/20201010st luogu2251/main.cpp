#include"bits/stdc++.h"
using namespace std;
int f[200000][30];
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
    for(int j=1;j<=21;j++)
    {
        for(int i=1;i + (1<<j) -1 <=n;i++)
        {
            f[i][j] = min(f[i][j-1],
                          f[i + (1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=n-m+1;i++)
    {
        int l = i;
        int r = i + m - 1;
        int s = log2(r - l + 1);
        printf("%d\n",min(f[l][s],
                  f[r-(1 << s)+ 1][s]));
    }
    return 0;
}


