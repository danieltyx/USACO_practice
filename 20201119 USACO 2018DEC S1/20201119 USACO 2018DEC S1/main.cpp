#define ll long long
#include"bits/stdc++.h"
using namespace std;
int a[100100];
int df[100100];
int dfcnt = 1;
int n,m,c;
int lmt = -1;
bool isokay(int t)
{
    int cnt = 1;
    int cnum = 0;
    int nmin = a[1];
    for(int i=1;i<=n;i++)
    {
        cnum++;

        if(a[i] - nmin > t)
        {

                cnt++;
                cnum = 0;
                nmin = a[i];
                continue;

           
        }
        if(cnum > c)
        {
       
                cnt++;
                cnum = 0;
                nmin = a[i];
                continue;
        }
        
    }
    if(cnt>m)return false;
    else return true;
}
int bis()
{
    int l=-1;
    int r=lmt;
    while(l+1<r)
    {
        int mid = (l+r)/2;
        if(isokay(mid))
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
    }
    return r;
}
int main()
{
   // freopen("convention.in","r",stdin);
   // freopen("convention.out","w",stdout);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        lmt = max(lmt,a[i]);
    }
    sort(a+1,a+n+1);
    int ans = bis();
    cout<<ans<<endl;
   // fclose(stdin);
   //fclose(stdout);
    return 0;
}
// 10 4 3 1 1 2 5 9 9 9 10 11 1


