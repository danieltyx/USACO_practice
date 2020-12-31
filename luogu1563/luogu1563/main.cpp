#include "bits/stdc++.h"
using namespace std;
int namenum[1000100];
int side[1000100];
int dirct[1000100];
int step[1000100];
string name[1000100];
int copyy[1000100];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&side[i]);
        cin>>name[i];
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&dirct[i],&step[i]);
    }
    int nowpos = 1;
    for(int i=1;i<=m;i++)
    {
        int realstep = step[i]%n;
        if(realstep ==0) continue;
        if(side[nowpos] == dirct[i])
        {
            if(nowpos-realstep>0)
            {
                nowpos-=realstep;
            }
            else
            {
                nowpos= (nowpos +n-realstep)%n;
                if(nowpos==0)
                {
                    nowpos = n;
                }
            }
        }
        else
        {
            nowpos= (realstep+nowpos)%n;
            if(nowpos==0)
            {
                nowpos = n;
            }
        }
    }
     cout<<name[nowpos]<<endl;
    return 0;
}
