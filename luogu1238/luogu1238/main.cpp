#include"bits/stdc++.h"
using namespace std;
int m,n;
int xf,yf;
int xl,yl;
int mp[101][101];
int u[101][101];
int xx[5]={0,0,-1,0,1};
int yy[5]={0,-1,0,1,0};
int ans=0;
vector<int> vcx;
vector<int> vcy;
void dfs(int x,int y)
{
    if(x==xl&&y==yl)
    {
        ans++;
        int len= vcx.size();
        printf("(%d,%d)",vcx.at(0),vcy.at(0));
        for(int i=1;i<len;i++)
        {
            printf("->(%d,%d)",vcx.at(i),vcy.at(i));
        }
        puts("");
        return;
    }
    for(int i=1;i<=4;i++)
    {
        int x2 = x +xx[i];
        int y2 = y +yy[i];
        if(x2<1||y2<1||x2>m||y2>n||u[x2][y2]==1||mp[x2][y2]==0)continue;
        u[x2][y2]=1;
        vcx.push_back(x2);
        vcy.push_back(y2);
        dfs(x2,y2);
        vcx.pop_back();
        vcy.pop_back();
        u[x2][y2]=0;
    }
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&mp[i][j]);
        }
    }
    cin>>xf>>yf;
    cin>>xl>>yl;
    if(mp[xf][yf]==0||mp[xl][yl]==0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    u[xf][yf]=1;
    vcx.push_back(xf);
    vcy.push_back(yf);
    dfs(xf,yf);
    if(ans==0)cout<<"-1"<<endl;
    return 0;
}

