
#include"bits/stdc++.h"using namespace std;
int l[10001];
int u[10001];
int cnt=0;
int ans=999999999;
int n,a,b;
void dfs(int k)// currently i am in k floor
{
    if(k==b) ans=min(ans,cnt);
    int a1,a2;
    a1= k + l[k];
    a2= k - l[k];
    if(a1<=n&&u[a1]==0&&cnt<=ans)
    {
        cnt++;
        u[a1]=1;
        dfs(a1);
        cnt--;
        u[a1]=0;
    }
    if(a2>=1&&u[a2]==0&&cnt<=ans)
    {
        cnt++;
        u[a2]=1;
        dfs(a2);
        cnt--;
        u[a2]=0;
    }
}
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&l[i]);
    }
    if(a==b)
    {
        cout<<"0"<<endl;
        return 0;
    }
    dfs(a);
    if(ans!=999999999)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}
