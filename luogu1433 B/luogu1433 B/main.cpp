#include"bits/stdc++.h"
using namespace std;
int n;
double x[101];
double y[101];
int u[101];
double dis[101][101];
double ans;
double minans = 999999999.99;
double finddis(double a1,double b1,double a2, double b2)
{
    return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}
void dfs(int k,int s)
{
    for(int i=0;i<=n;i++)
    {
        if(u[i]!=0)continue;
        if(ans+dis[k][i]>=minans)continue;
        ans += dis[k][i];
        u[i] = 1;
        if(s==n)
        {
            minans= min(minans,ans);
        }
        else
        {
            dfs(i,s+1);
        }
        u[i] = 0;
        ans-=dis[k][i];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            dis[i][j] = finddis(x[i],y[i],x[j],y[j]);
            //cout<<"i & j"<<i<<j<<" dis"<<dis[i][j]<<endl;
            dis[j][i] = dis[i][j];
        }
    }
    u[0]=1;
    dfs(0,1);
    printf("%.2f \n",minans);
    return 0;
}
