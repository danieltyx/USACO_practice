#include"bits/stdc++.h"
using namespace std;
int o[100100];
int qpa[100100];
int qpb[100100];
int a[100100];
int b[100100];
int c[100100];
int main()
{
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&o[i]);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&qpa[i],&qpb[i]);
    }
    if(o[1]==1)
    {
        a[1] = 1;
    }
    else if(o[1]==2)
    {
        b[1] = 1;
    }
    else
    {
        c[1] = 1;
    }
    for(int i=2;i<=n;i++)
    {
        if(o[i]==1)
        {
            a[i] = a[i-1] + 1;
            b[i] = b[i-1];
            c[i] = c[i-1];
        }
        else if (o[i]==2)
        {
            b[i] = b[i-1] + 1;
            a[i] = a[i-1];
            c[i] = c[i-1];
        }
        else
        {
            c[i] = c[i-1] + 1;
            b[i] = b[i-1];
            a[i] = a[i-1];
        }
    }
    
    for(int i=1;i<=q;i++)
    {
        int l = qpa[i] -1;
        int r = qpb[i];
        cout<<a[r] - a[l]<<" "<<b[r] - b[l]<<" "<<c[r] - c[l]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
