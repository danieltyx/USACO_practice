#include"bits/stdc++.h"
using namespace std;
const int marginn = 5;
const int mapsize = 1000;

int mp[mapsize*4][mapsize*4];
int cnt = 1;
int n;
int maxx = -1;
int maxy = -1;
int minx = mapsize*4;
int miny = mapsize+4;


void dfs(int x,int y)
{

    if(!(x>maxy+marginn||x<minx-marginn||y>maxy+marginn||y<miny-marginn))
    {
        if(mp[x+1][y]==0)
        {
            mp[x+1][y]=cnt;
            dfs(x+1,y);
        }
        if(mp[x-1][y]==0)
        {
            mp[x-1][y]=cnt;
            dfs(x-1,y);
        }
   
        if(mp[x][y+1]==0)
        {
            mp[x][y+1]=cnt;
            dfs(x,y+1);
        }
   
        if(mp[x][y-1]==0)
        {
            mp[x][y-1]=cnt;
            dfs(x,y-1);
        }
    }
}

void makecolor()
{
    for(int i=minx-marginn;i<=maxx+marginn;i++)
    {
        for(int j=miny-marginn;j<=maxy+marginn;j++)
        {
            if(mp[i][j]==0)
            {
                cnt++;
                mp[i][j] = cnt;
                dfs(i,j);
//                puts("");
//                puts("");
//                cout<<i<<" "<<j<<endl;
//                for(int q=minx-marginn;q<=maxx+marginn;q++)
//                {
//                    for(int s=miny-marginn;s<=maxy+marginn;s++)
//                    {
//                        cout<<mp[q][s]<<" ";
//                    }
//                    puts("");
//                }
//                puts("");
            }
        }
    }
}

int main()
{
//        freopen("gates.in","r",stdin);
//        freopen("gates.out","w",stdout);
    cin>>n;
    string a;
    cin>>a;
    int x = mapsize*2;
    int y = mapsize*2;
    mp[x][y]=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='N')
        {
            mp[x-1][y] = 1;
            mp[x-2][y] = 1;
            x-=2;
            minx = min(minx,x);
            maxx = max(maxx,x);
            miny = min(miny,y);
            maxy = max(maxy,y);
        }
        else if(a[i]=='S')
        {
            mp[x+1][y] = 1;
            mp[x+2][y] = 1;
            x+=2;
            minx = min(minx,x);
            maxx = max(maxx,x);
            miny = min(miny,y);
            maxy = max(maxy,y);
        }
        else if(a[i] =='W')
        {
            mp[x][y-1] = 1;
            mp[x][y-2] = 1;
            y-=2;
            minx = min(minx,x);
            maxx = max(maxx,x);
            miny = min(miny,y);
            maxy = max(maxy,y);
        }
        else if(a[i] == 'E')
        {
            mp[x][y+1] = 1;
            mp[x][y+2] = 1;
            y+=2;
            minx = min(minx,x);
            maxx = max(maxx,x);
            miny = min(miny,y);
            maxy = max(maxy,y);
        }
    }

    

    for(int i=minx-marginn;i<=maxx+marginn;i++)
    {
        for(int j=miny-marginn;j<=maxy+marginn;j++)
        {
            cout<<mp[i][j]<<" ";
        }
        puts("");
    }

    
    makecolor();

    for(int i=minx-marginn;i<=maxx+marginn;i++)
    {
        for(int j=miny-marginn;j<=maxy+marginn;j++)
        {
            cout<<mp[i][j]<<" ";
        }
        puts("");
    }
    
    
    cout<<cnt-2<<endl;
//        fclose(stdin);
//       fclose(stdout);
    return 0;
}

/***
300
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
***/
