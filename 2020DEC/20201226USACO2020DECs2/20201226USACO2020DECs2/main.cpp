#include"bits/stdc++.h"
#define ll long long
using namespace std;
const int MAXN = 2550;
struct Po{
    int x;
    int y;
}p[MAXN];
ll c[MAXN][MAXN];
bool cmp(Po a,Po b)
{
    return a.x < b.x;
}
ll jc[20];
void jiecheng()
{
    jc[0] = 1;
    ll ji = 1;
    for(int i=1;i<=20;i++)
    {
        ji = ji * i;
        jc[i] = ji;
    }
}
void processc()
{
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i==j) c[i][j]= 1;
            else
            {
                c[i][j] = jc[i] / (jc[j] * jc[i-j]);
            }
            
        }
    }
}
int main()
{
    jiecheng();
    processc();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    sort(p+1,p+n+1,cmp);
    ll reduce = 0;
    for(int i=1;i<=n;i++)
    {
        int yless = 0;
        int ymore = 0;
        for(int j=i+1;j<=n;j++)
        {
            if(p[j].y >p[i].y)
            {
                ymore++;
            }
        }
        for(int j=1;j<i;j++)
        {
            if(p[j].y <p[i].y)
            {
                yless++;
            }
        }
        for(int p=1;p<=yless;p++)
        {
            for(int q=1;q<=ymore;q++)
            {
                reduce+=c[yless][p]*c[ymore][q];
            }
        }
        yless = 0;
        ymore = 0;
        for(int j=i+1;j<=n;j++)
        {
            if(p[j].y <p[i].y)
            {
                ymore++;
            }
        }
        for(int j=1;j<i;j++)
        {
            if(p[j].y >p[i].y)
            {
                yless++;
            }
        }
        for(int p=1;p<=yless;p++)
        {
            for(int q=1;q<=ymore;q++)
            {
                reduce+=c[yless][p]*c[ymore][q];
            }
        }
        
    }
    cout<<pow(2,n) - reduce<<endl;
    return 0;
}


//change to ll
