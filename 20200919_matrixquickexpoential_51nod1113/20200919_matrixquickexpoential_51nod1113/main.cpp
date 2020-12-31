#include"bits/stdc++.h"
#define int long long
using namespace std;
struct Matrix{
    long long a[110][110];
};
int n,m;
Matrix m1;
int MODN = 1000000007;
Matrix multi(Matrix m1, Matrix m2)
{
    Matrix ans;
    memset(ans.a,0,sizeof(ans.a));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                ans.a[i][j]= (ans.a[i][j] + (m1.a[i][k] % MODN) * (m2.a[k][j] % MODN))%MODN;
            }
        }
    }
    return ans;
}
Matrix expo()
{
    Matrix ans2;
    memset(ans2.a,0,sizeof(ans2.a));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) ans2.a[i][j] = 1;
        }
    }
    for(;m;m=m>>1)
    {
        if(m & 1) ans2 = multi(ans2,m1);
        m1 = multi(m1,m1);
    }
    return ans2;
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&m1.a[i][j]);
        }
    }
    if(m==0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)printf("1 ");
                else printf("0 ");
            }
            puts("");
        }
        return 0;
    }
    Matrix res = expo();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<res.a[i][j] % MODN<<" ";
        }
        puts("");
    }
    return 0;
}
 

