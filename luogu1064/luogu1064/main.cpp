#include"bits/stdc++.h"
using namespace std;
int a[50111][5];
int b[50111][5];
int f[50111];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(z==0)
        {
            a[i][0] = x;
            b[i][0] = x*y;
        }
        else
        {
            if(a[z][1]==0)
            {
                a[z][1] = a[z][0] + x;
                b[z][1] = b[z][0] + x*y;
            }
            else
            {
                a[z][2] = a[z][0] +x;
                b[z][2] = b[z][0] +x*y;
                a[z][3] = a[z][1] +x;
                b[z][3] = b[z][1] +x*y;
            }
        }
        
    }
    for(int i=1;i<=m;i++)
    {
        if(a[i][0]==0)continue;
        for(int j=n;j>=0;j--)
        {
            for(int q=0;q<=3;q++)
            {
                if(a[i][q]!=0&&j>=a[i][q])
                f[j]=max(f[j],f[j-a[i][q]]+b[i][q]);
            }
        }
    }
    cout<<f[n]<<endl;
    return 0;
}
//维度开小了 反了
//if 写反了
