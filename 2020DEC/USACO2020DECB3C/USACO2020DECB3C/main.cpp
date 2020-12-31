#include"bits/stdc++.h"
using namespace std;
struct Cow{
    int x;
    int y;
    int d;//direction 1n 2e
    int s=0;//steps
    bool live = true;
};Cow c[70];
int n;
map<int,int> mpv;
bool cmpx(Cow cowa,Cow cowb)
{
    if(cowa.x!=cowb.x)
    {
        return cowa.x<cowb.x;
    }
    return cowa.y<cowb.y;
}

set<pair<int,int>> ey;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string aa;
        int bb;
        int cc;
        cin>>aa>>bb>>cc;
        c[i].x = bb;
        c[i].y = cc;
        if(aa[0]=='E') c[i].d = 2;
        else c[i].d = 1;
    }
    sort(c+1,c+n+1,cmpx);
    for(int i=1;i<=n;i++)
    {
        if(c[i].d==2)continue;
        int x1 = c[i].x;
        for(int j=1;j<=i;j++)
        {
            if(c[j].d==1)continue;
            if(c[j].x<=x1)ey.insert({c[i].x,c[j].y});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
//            cout<<i<<"# "<<j<<endl;
//            cout<<c[i].x<<" "<<c[j].x<<endl;
//            cout<<c[i].d<<" "<<c[j].d<<endl;
            if((c[i].x==c[j].x) && (c[i].d==c[j].d))
            {
                ey.insert({c[i].x, max(c[i].y,c[j].y)});
            }
            if((c[i].y==c[j].y) && (c[i].d==c[j].d))
            {
                ey.insert({max(c[i].x,c[j].x),c[i].y});
            }
        }
    }//all meet points
    for(set<pair<int,int>>::iterator it=ey.begin();it!=ey.end();it++)
    {
        
        int x1 = it->first;
        int y1 = it->second;
        int mintime = 9999999999;
        for(int i=1;i<=n;i++)
        {
            if(c[i].live = false)continue;
            if(c[i].x!=x1 && c[i].y!=y1)continue;
            if(c[i].x==x1 && c[i].d==1)
            {
                int tm = y1 - c[i].y;
                mintime = min(mintime,tm);
            }
            else if(c[i].y==y1 &&c[i].d==2)
            {
                int tm = x1 - c[i].x;
                mintime = min(mintime,tm);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i].live = false)continue;
            if(c[i].x!=x1 && c[i].y!=y1)continue;
            if(c[i].x==x1 && c[i].d==1)
            {
                int tm = y1 - c[i].y;
                if(tm!= mintime)
                {
                    c[i].s = tm;
                    c[i].live = false;
                }
            }
            else if(c[i].y==y1 &&c[i].d==2)
            {
                int tm = x1 - c[i].x;
                if(tm!= mintime)
                {
                    c[i].s = tm;
                    c[i].live = false;
                }
            }
        }
    
        for(int i=1;i<=n;i++)
        {
            cout<<c[i].s<<endl;
        }
    }
    return 0;
}


/*
 7
 E 3 5
 N 5 3
 E 4 6
 E 10 4
 N 11 2
 N 8 1
 N 5 4
 */
