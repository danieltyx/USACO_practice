#include"bits/stdc++.h"
#define int long long
using namespace std;
int mp[101][101];
int mk[101][101];
int xx[9] = {0,2,2,-2,-2,1,1,-1,-1};
int yy[9] = {0,1,-1,1,-1,2,-2,2,-2};
signed main()
{
    int bx,by,hx,hy;
    cin>>bx>>by>>hx>>hy;
    for(int i=0;i<=8;i++)
    {
        int x1 = hx + xx[i];
        int y1 = hy + yy[i];
        if(x1<0||y1<0||x1>bx||y1>by)continue;
        mk[x1][y1] = -1;
    }
    if(mk[0][0]!=-1)mp[0][0] = 1;
    else
    {
        cout<<"0";
        return 0;
    }
    for(int i=0;i<=bx;i++)
    {
        for(int j=0;j<=by;j++)
        {
            if(i==0&&j==0)continue;
            if(mk[i][j]==-1)continue;
            if(i==0) mp[0][j] = mp[0][j-1];
            else if(j==0) mp[i][0] = mp[i-1][0];
            else mp[i][j] = mp[i-1][j] + mp[i][j-1];
        }
    }
    cout<<mp[bx][by]<<endl;
    return 0;
}
