//1433 吃奶酪 dfs+优化

#include"bits/stdc++.h"
using namespace std;
int n;
double xr[101];
double yr[101];
int u[101];
double now=0.00;
double cnt=0.00;
double dis[101][101];
double ress=99999999.99;
double adddis(int i1,int i2)
{
    double x1= xr[i1];
    double y1= yr[i1];
    double x2= xr[i2];
    double y2= yr[i2];
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(int k,int s)
{
    for(int i=0;i<=n;i++)
    {
        if(u[i]==1)continue;
        if(now > ress)continue;
        double newadd  = dis[k][i];
        now += newadd;
        u[i] = 1;
        if(s==n)
        {
            ress=min(ress,now);
        }
        else if(s<=n)
        {
            dfs(i,s+1);
        }
        now -= newadd;
        u[i]=0;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&xr[i],&yr[i]);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dis[i][j]!=0)continue;
            if(i==j)continue;
            dis[i][j] = adddis(i,j);
            dis[j][i] = dis[i][j];
        }
    }
    xr[0]=0;
    yr[0]=0;
    dfs(0,0);
    printf("%0.2lf",ress);
    return 0;
}
