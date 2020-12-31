//NSWE 1234
#include"bits/stdc++.h"
#define pp pair<int,int>
using namespace std;
map<pp,set<pp> > con;

int mp[2010][2010];
int v[2010][2010];
int cnt = 1;
void dfs(int x, int y)
{
    v[x][y]++;
    if(v[x][y]==2)
    {
        cnt++;
    }
    else
    {
        int x1,y1;
        for(set<pp>::iterator it=con[{x,y}].begin();it!=con[{x,y}].end();++it)
        {
            pair<int,int> xy1;
            xy1 =*it;
            x1 = xy1.first;
            y1 = xy1.second;
            if(x1==x-1 && y1==y && mp[x-1][y]==1)
            {
                dfs(x-1,y);
            }
            if(x1==x && y1==y+1 && (mp[x][y+1]==1))
            {
                dfs(x,y+1);
            }
        }
    }
}
int main()
{
//    freopen("gates.in","r",stdin);
//    freopen("gates.out","w",stdout);
    int n;
    cin>>n;
    string a;
    cin>>a;
    int x = 1000;
    int y = 1000;
    int xmax = -1;
    int ymin = 9999;
    mp[x][y]=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='N')
        {
            con[{x,y}].insert({x-1,y});
            con[{x-1,y}].insert({x,y});
            x--;
            mp[x][y] = 1;
        }
        else if(a[i]=='S')
        {
            con[{x,y}].insert({x+1,y});
            con[{x+1,y}].insert({x,y});
            x++;
            mp[x][y] = 1;
        }
        else if(a[i] =='W')
        {
            con[{x,y}].insert({x,y-1});
            con[{x,y-1}].insert({x,y});
            y--;
            mp[x][y] = 1;
        }
        else if(a[i] == 'E')
        {
            con[{x,y}].insert({x,y+1});
            con[{x,y+1}].insert({x,y});
            y++;
            mp[x][y] = 1;
        }
        //xmax = max(xmax,x);
        //ymin = min(ymin,y);
    }
    //dfs(xmax,ymin);
    for(int i=1000+n;i>=1000-n;i--)
    {
        for(int j=1000-n;j<=1000+n;j++)
        {
            if(mp[i][j]==1 && v[i][j]==0)
            {
                dfs(i,j);
                cnt--;
            }
        }
    }
//

    for(int i=1000-10;i<=1000+10;i++)
    {
        for(int j=1000-10;j<=1000+10;j++)
        {
            cout<<v[i][j]<<" ";
        }
        puts("");
    }

    cout<<cnt;
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}



/***
 
 15
 NEENWWWSSSEEENN
 
 
 
 26
NNNEEENNWSSSSSWWWWSSSEENNN
 
 
 
 11
 NNNEEESWNNN
 
 
 30
 NNNNNEEEEESSSSWWWWNNNEEESSWWNN
***/
