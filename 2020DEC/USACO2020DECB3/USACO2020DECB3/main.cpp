#include"bits/stdc++.h"
using namespace std;
const int THEEND = 100000;
struct Cow{
    int x;
    int y;
    int d;//direction 1n 2e
    int s=0;//steps
    bool live = true;
};Cow c[70];
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
    for(int i=1;i<=THEEND;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(c[j].live == false)continue;
            int x1 = c[j].x;
            int y1 = c[j].y;
            int d1 = c[j].d;
            if(mp.count({x1,y1})==0)
            {
                mp[{x1,y1}] = i;
                if(d1==1) c[j].y++;
                else c[j].x++;
                c[j].s++;
            }
            else
            {
                //map<pair<int,int>,int>::iterator it;
                //it = mp.find({c[j].x,c[j].y});
                int t = mp[{c[j].x,c[j].y}];
                if(t==i)
                {
                    if(d1==1) c[j].y++;
                    else c[j].x++;
                    c[j].s++;
                }
                else
                {
                    c[j].live = false;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i].s==THEEND)cout<<"Infinity"<<endl;
        else cout<<c[i].s<<endl;
    }
    
    return 0;
    
    
}
/*
 6
 E 3 5
 N 5 3
 E 4 6
 E 10 4
 N 11 2
 N 8 1
 
 */
