#include"bits/stdc++.h"
#define pp pair<int,int>
using namespace std;
map<int,vector<pp> > mp;
map<int,pp> ss;
int bml[1100];
int rbml[1100];
int pois[1100];
int ans[1100];
int main()
{
    freopen("badmilk.in","r",stdin);
    freopen("badmilk.out","w",stdout);
    int n,m,d,s;
    cin>>n>>m>>d>>s;
    for(int i=1;i<=d;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back({b,c});
    }
    for(int i=1;i<=d;i++)
    {
        int l = mp[i].size();
        for(int j=0;j<mp[i].size();j++)
        {
            for(int k=0;k< mp[i].size();k++)
            {
                if(j==k) continue;
                if(mp[i].at(j).first == mp[i].at(k).first)
                {
                    if(mp[i].at(j).second < mp[i].at(k).second)
                    {
                        mp[i].erase(mp[i].begin()+k);
                    }
                    else
                    {
                        mp[i].erase(mp[i].begin()+j);
                    }
                }
            }
        }
    }
    for(int i=1;i<=s;i++)
    {
        int a,b;
        cin>>a>>b;
        ss[i] = {a,b};
    }
    
    for(int i=1;i<=s;i++)
    {
        int l = mp[ss[i].first].size();
        for(int j=0;j<l;j++)
        {
            if(mp[ss[i].first].at(j).second < ss[i].second)
            {
                bml[mp[ss[i].first].at(j).first]++;
            }
        }
    }
    
    int rcnt = 0;
    for(int i=1;i<=m;i++)
    {
        if(bml[i]==s)
        {
            rbml[i] = 1;
            rcnt++;
        }
    }


    
    for(int k=1;k<=rcnt;k++)
    {
        for(int i=1;i<=n;i++)
        {
            int l = mp[i].size();
            for(int j=0;j<l;j++)
            {
                if(rbml[mp[i].at(j).first]==1)
                {
                    pois[i] = 1;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(pois[i]==1)ans[k]++;
        }
    }
    int maxans = -1;
    for(int i=1;i<=rcnt;i++)
    {
        maxans = max(maxans,ans[i]);
    }
    cout<<maxans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
    
}
/*
 3 4 6 1
 1 1 1
 1 4 1
 1 3 4
 1 2 2
 2 1 5
 2 2 7
 1 3
 

 */
