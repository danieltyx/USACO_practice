#include"bits/stdc++.h"
using namespace std;
int u[101];
int len[101];
string a[101];
string s;
int n;
int maxlen =-1;
int res=-1;
string maxs;
void dfs(string cword,int lennow)
{
    maxlen = max(maxlen,lennow);
    if(lennow>=maxlen)
    {
        maxs = cword;
    }
    for(int i=1;i<=n;i++)
    {
        int lena = a[i].length();
        int lenn = min(lennow,lena);
        for(int j=lenn-1;j>=1;j--)
        {
            string tempc =cword.substr(cword.length()-j,j);
            string tempa =a[i].substr(0,j);
             if(tempc == tempa)
             {
                 if(u[i]>=2) continue;
                 u[i]++;
                 string cword2 = cword + a[i].substr(j,a[i].length());
                 int lennow2 = cword2.length();
                 dfs(cword2,lennow2);
                 u[i]--;
             }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        len[i] = a[i].length();
    }
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        if(a[i].at(0)==s.at(0))
        {
            u[i]++;
            dfs(a[i],len[i]);
            res = max(res,maxlen);
        }
    }
    cout<<res<<endl;
    return 0;
}
