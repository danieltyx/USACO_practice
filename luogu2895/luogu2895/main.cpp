#include"bits/stdc++.h"
using namespace std;
struct Boobs{
    int xb;
    int yb;
    int tb;
};
Boobs a[100051];
int n;
int ans;
int stnow=999999999;
int cnt=0;
int xx[5]={0,0,0,1,-1};
int yy[5]={0,1,-1,0,0};
int m[10001][10001];
int maxx=-1;
int maxy=-1;
int maxt=-1;
int ansnum=0;
int ansl[1000001];
int st=0;
bool cmp(Boobs c,Boobs d)
{
    return c.tb<d.tb;
}
bool isok(int x,int y,int t)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i].tb>t)break;
        if((x == a[i].xb)
           &&
           (y == a[i].yb))
        {
            return false;
        }
        for(int j=1;j<=4;j++)
        {
            int xn= a[i].xb+xx[j];
            int yn= a[i].yb+yy[j];
            if(xn<0||yn<0||xn>maxx+1||yn>maxy+1)continue;
            if(x==xn&&y==yn)return false;
        }
    }
    return true;
}
bool isdone(int x,int y,int t)
{
    for(int i=n;i>=1;i--)
    {
        if(a[i].tb<t)break;
        if((x == a[i].xb)
           &&
           (y == a[i].yb))
        {
            return false;
        }
        for(int j=1;j<=4;j++)
        {
            int xn= a[i].xb+xx[j];
            int yn= a[i].yb+yy[j];
            if(xn<0||yn<0||xn>maxx+1||yn>maxy+1)continue;
            if(x==xn&&y==yn)return false;
        }
    }
    return true;
}
void dfs(int x,int y,int t)
{
    for(int i=1;i<=4;i++)
    {
        int x2 = x + xx[i];
        int y2 = y + yy[i];
        if(x2<0||y2<0||x2>maxx+1||y2>maxy+1)continue;
        if(isok(x2,y2,t)==true && st<stnow)
        {
            if(isdone(x2,y2,t)==true)
            {
                st++;
                stnow=st;
                ansl[++ansnum]=st;
                st--;
                return;
            }
            else
            {
                st++;
                m[x2][y2]= st;
                dfs(x2,y2,t+1);
                st--;
                m[x2][y2]= st;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].xb,&a[i].yb,&a[i].tb);
        maxx=max(maxx,a[i].xb);
        maxy=max(maxy,a[i].yb);
        maxt=max(maxt,a[i].tb);
    }
    m[0][0]=0;
    sort(a+1,a+1+n,cmp);
    dfs(0,0,1);
    int printedans=999999999;
    for(int i=1;i<=ansnum;i++)
    {
        printedans= min(printedans,ansl[i]);
    }
    if(printedans==999999999)
    {
        cout<<"-1";
    }
    else
    {
        cout<<printedans<<endl;
    }
    return 0;
}
