#include"bits/stdc++.h"
using namespace std;
int n;
int resx[101];
int u[101][101];
int cnt=0;
int ans=0;
bool isok(int x,int y)
{
    if(resx[y]!=0) return false;
    int i = x-1;
    int x1,x2;//第 x 列 第y行
    x1=y+1;
    x2=y-1;
    while(i>0)
    {
        if(x1<=n)
        {
            if(u[i][x1]!=0) return false;
        }
        if(x2>=1)
        {
            if(u[i][x2]!=0) return false;
        }
        i--;
        x1++;
        x2--;
    }
    return true;
}
void printres()
{
    ans++;
    if(ans>3)return;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(u[i][j]==1)
            {
                cout<<j<<" ";
            }
        }
    }
    puts("");
    cnt=0;
}
void dfs(int x)// di x hang
{
    for(int i=1;i<=n;i++)
    {
        if(isok(x,i)==true)
        {
            u[x][i]=1;
            resx[i]=x;
            if(x==n)
            {
                printres();
            }
            else
            {
                dfs(x+1);
            }
            u[x][i]=0;
            resx[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}

