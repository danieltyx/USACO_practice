#include"bits/stdc++.h"
using namespace std;
int a[100100];
int s[100100];
int res[8];
int main()
{
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    s[0] = 0;
    for(int i=1;i<=n;i++)
    {
        s[i] = s[i-1] + a[i];
        s[i] %= 7;
    }
    for(int i=1;i<=7;i++)
    {
        int l=0;
        int r=0;
        for(int j=1;j<=n;j++)
        {
            if(s[j]==i)
            {
                l = j;
                break;
            }
        }
        for(int j=n;j>=1;j--)
        {
            if(s[j]==i)
            {
                r = j;
                break;
            }
        }
        res[i] = r - l;
    }
    int maxn = 0;
    for(int i=1;i<=7;i++)
    {
        maxn = max(maxn,res[i]);
    }
    cout<<maxn<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
