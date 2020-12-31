#include"bits/stdc++.h"
using namespace std;
const int mapsize = 2000;
const int inf = 2147483647;
int t[mapsize][mapsize];
int diff[mapsize];
int diffcnt = 1;
int thetime = 2;
int main()
{
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);
    int n;
    cin>>n;
    int x = mapsize/2;
    int y = mapsize/2;
    t[x][y] = 1;
    for(int i=1;i<=n;i++)
    {
        char a;
        cin>>a;
        int step;
        cin>>step;
        
        if(a == 'N')
        {
            for(int i=1;i<=step;i++)
            {
                if(t[x-i][y]) diff[diffcnt++] = thetime - t[x-i][y];
                t[x-i][y] = thetime++;
            }
            x -= step;
        }
        
        if(a == 'S')
        {
            for(int i=1;i<=step;i++)
            {
                if(t[x+i][y]) diff[diffcnt++] = thetime - t[x+i][y];
                t[x+i][y] = thetime++;
            }
            x += step;
        }
        
        if(a == 'W')
        {
            for(int i=1;i<=step;i++)
            {
                if(t[x][y-i]) diff[diffcnt++] = thetime - t[x][y-i];
                t[x][y-i] = thetime++;
            }
            y -= step;
        }
        
        if(a == 'E')
        {
            for(int i=1;i<=step;i++)
            {
                if(t[x][y+i]) diff[diffcnt++] = thetime - t[x][y+i];
                t[x][y+i] = thetime++;
            }
            y += step;
        }
        
    }
    int ans = inf;
//    for(int i=1;i<=mapsize;i++)
//    {
//        for(int j=1;j<=mapsize;j++)
//        {
//            cout<<t[i][j]<<" ";
//        }
//        puts("");
//    }
//
//    for(int i=1;i<=diffcnt;i++) cout<<diff[i]<<" ";
//
    for(int i=1;i<=diffcnt;i++)
    {
        if(diff[i]==0)continue;
        ans = min(ans,diff[i]);
    }
    
    if(ans==inf)cout<<"-1"<<endl;
    else cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
