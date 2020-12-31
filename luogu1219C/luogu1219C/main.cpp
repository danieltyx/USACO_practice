#include"bits/stdc++.h"
using namespace std;
int n;
int m[101][101];
int l[101];
int t=0;
bool checkij(int k,int i)
{
    if(l[i]!=0)return false;
    int k2 = k-1;
    int i1= i-1;
    int i2= i+1;
    while(k2>0)
    {
        if(i1>0)
        {
            if(m[k2][i1]==1)return false;
        }
        if(i2<=n)
        {
            if(m[k2][i2]==1)return false;
        }
        k2--;
        i1--;
        i2++;
    }
    return true;
}
void p()
{
    t++;
    if(t>3)return;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(m[i][j]==1)cout<<j<<" ";
        }
    }
    puts("");
}
void dfs(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(checkij(k,i)==true)
        {
            m[k][i]=1;
            l[i]=1;
            if(k==n)
            {
                p();
            }
            else
            {
                dfs(k+1);
            }
            m[k][i]=0;
            l[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<t<<endl;
    return 0;
}
