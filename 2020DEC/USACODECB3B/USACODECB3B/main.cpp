#include"bits/stdc++.h"
using namespace std;
struct Cow{
    int x;
    int y;
    int d;//direction 1n 2e
    int s=0;//steps
    bool live = true;
};Cow c[70];
bool cmpx(Cow cowa,Cow cowb)
{
    if(cowa.x!=cowb.x)
    {
        return cowa.x<cowb.x;
    }
    return cowa.y<cowb.y;
}

bool cmpy(Cow cowa,Cow cowb)
{
    if(cowa.y!=cowb.y)
    {
        return cowa.y<cowb.y;
    }
    return cowa.x<cowb.x;
}
map<pair<int,int>,int> mp;
int n;
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
        for(int j=1;j<i;i++)
        {
            if(c[j])
            int x1 = c[j].x;
            int y1 = c[j].y;
            
        }
    }
    
    
    
    
    
    return 0;
}
