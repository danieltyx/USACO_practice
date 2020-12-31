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
int stnow=0;
int xx[5]={0,0,0,1,-1};
int yy[5]={0,1,-1,0,0};
int m[10001][10001];
int t[10001][10001];
int maxx=-1;
int maxy=-1;
int maxt=-1;
int ansnum=0;
int ansl[1000001];
int st=0;
bool isok(int x,int y,int t)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i].tb<=t)
        {
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
                if(xn<0||yn<0||xn>300||yn>300)continue;
                if(x==xn&&y==yn)return false;
            }
        }
    }
    return true;
}
bool isdone(int x,int y,int t)
{
    for(int i=n;i>=1;i--)
    {
        if(a[i].tb>=t)
        {
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
                if(xn<0||yn<0||xn>300||yn>300)continue;
                if(x==xn&&y==yn)return false;
            }
        }
    }
    return true;
}

void bfs(int x,int y,int t)
{
    queue<int> qux;
    queue<int> quy;
    qux.push(x);
    quy.push(y);
    while(!qux.empty())
    {
        int x1 = qux.front();
        int y1 = quy.front();
        qux.pop();
        quy.pop();
        for(int i=1;i<=4;i++)
        {
           int x2 = x1 + xx[i];
           int y2 = y1 + yy[i];
           if(x2<0||y2<0||x2>300||y2>300)continue;
           if(isok(x2,y2,t)==true)
           {
               if(isdone(x2,y2,t)==true)
               {
                   st++;
                   t[x2][y2]=
                   m[x2][y2]=st;
                   for(int z=0;z<=6;z++)
                   {
                       for(int q=0;q<=6;q++)
                       {
                           cout<<m[z][q]<<" ";
                       }
                       puts("");
                   }
                   stnow=st;
                   return;
               }
               else
               {
                   st++;
                   t++;
                   m[x2][y2]=st;
                   for(int z=0;z<=6;z++)
                   {
                       for(int q=0;q<=6;q++)
                       {
                           cout<<m[z][q]<<" ";
                       }
                       puts("");
                   }
                   
                   qux.push(x2);
                   quy.push(y2);
               }
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
    bfs(0,0,1);
    if(stnow==0)
    {
        cout<<"-1";
    }
    else
    {
        cout<<stnow;
    }
    return 0;
}
