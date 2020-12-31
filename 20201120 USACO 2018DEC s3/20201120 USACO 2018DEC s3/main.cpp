#include"bits/stdc++.h"
using namespace std;
const int MAPN = 1050;
int mp[MAPN][15];
int v[MAPN][15];
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,1,-1};
int n, k;
int tmm[MAPN][15];
bool changed = true;
set<pair<int,int> > c;
set<pair<int,int> >::iterator it;
void clearpoints(set<pair<int,int> > cc)
{
    while(!cc.empty())
    {
        pair<int, int> cpoint;
        it = cc.begin();
        cpoint = *it;
        cc.erase(it);
        mp[cpoint.first][cpoint.second] = 0;
    }

//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=10;j++)
//        cout<<mp[i][j]<<" ";
//        puts("");
//    }
//    puts("");

    
}
void restack()
{
    for(int i=1;i<=n;i++)for(int j=1;j<=10;j++)tmm[i][j]=0;
    for(int j=1;j<=10;j++)
    {
        int tcnt = 1;
        for(int i=n;i>=1;i--)
        {
            if(mp[i][j]!=0)tmm[tcnt++][j] = mp[i][j];
    
        }
    }

    for(int j=1;j<=10;j++)
    {
        for(int i=n;i>=1;i--)
        {
            mp[i][j] = tmm[n-i+1][j];
        }
    }
    
    
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=10;j++)
//        cout<<mp[i][j]<<" ";
//        puts("");
//    }
//    puts("");
    
}
void dfs(int x, int y)
{
    if(x>n;y>10)return;
    for(int i=1;i<=4;i++)
    {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(x1>n ||x1<1 ||y1>10||y1<1||v[x1][y1]==1)
                continue;
        if(mp[x1][y1]==mp[x][y])
        {
            v[x1][y1] = 1;
            c.insert(pair<int,int>{x1,y1});
            dfs(x1,y1);
            v[x1][y1] = 0;
        }
    }
}
int main()
{
//    freopen("mooyomooyo.in","r",stdin);
//    freopen("mooyomooyo.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        for(int j=0;j<a.length();j++)
        {
            mp[i][j+1] = a.at(j) - '0';
        }
    }
    while(changed == true)
    {
        changed = false;
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=10;j++)
            {
                if(mp[i][j]!=0 && v[i][j]==0)
                {
                    v[i][j]=1;
                    c.insert(pair<int,int> {i,j});
                    dfs(i,j);
                    v[i][j]=1;
                    if(c.size()>=k)
                    {
                        changed = true;
                        clearpoints(c);
                    }
                    c.clear();
                }
            }
        }
        restack();
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        cout<<mp[i][j];
        puts("");
    }
//   fclose(stdin);
//    fclose(stdout);
    return 0;
}
/*
10 99
 9999999999
 9999999999
 9999999999
 9999999999
 9999999999
 9999999999
 9999999999
 9999999999
 9999999999
 9999999999
 
 
 3 3
 0110000000
 1443000000
 2224000000
 
 
 
 
 6 6
 3333312098
 3333122098
 3331222089
 3312222089
 3122222098
 1222222098
 
 
 
 5 3
 0000200000
 0002100000
 0211100000
 0221100000
 2211100000
 
 
 
 5 2
 0000000000
 1112246888
 2111357998
 0000000008
 2111110089
 
 
 
 
 
 
 6 4
 0000000000
 0000000300
 0054000300
 1054502230
 2211122220
 1111111223
 */
