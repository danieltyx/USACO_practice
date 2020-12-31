#include"bits/stdc++.h"
using namespace std;
int a[100100];
int b[100100];
int pos[100100];
int c[100100];
int f[100100];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&b[i]);
        pos[b[i]] = i;
    }
    for(int i=1;i<=n;i++)
    {
        c[i] = pos[a[i]];
    }
    int len =0;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        int pos = lower_bound(f+1, f+1+len,c[i]) - f;
        if(pos==len+1)
        {
            len++;
        }
        f[pos]=min(f[pos],c[i]);
    }
    cout<<len<<endl;
    return 0;
}
