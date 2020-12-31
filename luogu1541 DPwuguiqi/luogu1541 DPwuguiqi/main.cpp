#include"bits/stdc++.h"
using namespace std;
int x[1010];
int y[1010];
int p[5];
int bin[50][50][50][50];
int vis[50][50][50][50];
int n,m;

int dp(int a,int b,int c,int d)
{
    if(a==p[1]&&b==p[2]&&c==p[3]&&d==p[4]) return x[n];
    if(vis[a][b][c][d]==1) return bin[a][b][c][d];
    
    int now =1+a+2*b+3*c+4*d;
    
    //cout<<bin[a][b][c][d]<<endl;
    
    if(a<p[1]) bin[a][b][c][d] = max(bin[a][b][c][d],dp(a+1,b,c,d));
    if(b<p[2]) bin[a][b][c][d] = max(bin[a][b][c][d],dp(a,b+1,c,d));
    if(c<p[3]) bin[a][b][c][d] = max(bin[a][b][c][d],dp(a,b,c+1,d));
    if(d<p[4]) bin[a][b][c][d] = max(bin[a][b][c][d],dp(a,b,c,d+1));
    
    
    vis[a][b][c][d] = 1;
    bin[a][b][c][d] += x[now];
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl;
    //cout<<"###"<<bin[a][b][c][d]<<endl;
    return bin[a][b][c][d];
}
int main()
{
   
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        y[i]=t;
        if(t==1)p[1]++;
        else if(t==2)p[2]++;
        else if(t==3)p[3]++;
        else if(t==4)p[4]++;
    }
    cout<<dp(0,0,0,0)<<endl;
    return 0;
}
