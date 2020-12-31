#include"bits/stdc++.h"
using namespace std;
int mp[101][101]= {0};
int u[101][101]={0};
int n,m,t;
int xf,yf,xl,yl;
int xx[5] ={0,0,0,1,-1};
int yy[5] ={0,1,-1,0,0};
int ans =0;
void dfs(int x,int y)
{
    if(x==xl && y==yl)
    {
        ans++;
        return;
    }
    for(int i=1;i<=4;i++)
    {
        int x2 = x+xx[i];
        int y2 = y+yy[i];
    if(x2<1||y2<1||x2>n||y2>m||u[x2][y2]==1||mp[x2][y2]==1)continue;
        u[x2][y2]=1;
        dfs(x2,y2);
        u[x2][y2]=0;
    }
}
int main()
{
    cin>>n>>m>>t;
    cin>>xf>>yf>>xl>>yl;
    for(int i=1;i<=t;i++)
    {
        int k,q;
        cin>>k>>q;
        mp[k][q]=1;
    }
    if(mp[xl][yl]==1||mp[xf][yf]==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    u[xf][yf]=1;
    dfs(xf,yf);
    cout<<ans<<endl;
    return 0;
}
