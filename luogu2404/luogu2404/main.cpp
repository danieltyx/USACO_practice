#include"bits/stdc++.h"
using namespace std;
int n;
int line[10001];
int sum=0;
void p(int k)
{
    cout<<line[1];
    for(int i=2;i<=k;i++)
    {
        cout<<"+"<<line[i];
    }
      puts("");
}
void dfs(int k,int startt)
{
    if(k>n)return;
    for(int i=startt;i<n;i++)
    {
        line[k]=i;
        sum+=i;
        if(sum==n)
        {
            p(k);
        }
        else
        {
            dfs(k+1,i);
        }
        sum-=i;
    }
}
int main()
{
    cin>>n;
    dfs(1,1);//从数字s开始填写第k位
}
