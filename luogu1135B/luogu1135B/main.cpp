#include"bits/stdc++.h"
using namespace std;
int l[1011];
int st[1011];
int n,a,b;
void bfs(int x)
{
    queue<int> qu;
    qu.push(x);
    while(!qu.empty())
    {
        int x1 = qu.front();
        if(x1==b)return;
        qu.pop();
        int x2 = x1 + l[x1];
        int x3 = x1 - l[x1];
        if(x2<=n)
        {
            st[x2] = st[x1]+1;
            qu.push(x2);
        }
        if(x3>=1)
        {
            st[x3] = st[x1]+1;
            qu.push(x3);
        }
    }
}
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&l[i]);
    }
    if(a==b)
    {
        cout<<"0"<<endl;
        return 0;
    }
    st[a]=0;
    bfs(a);
    if(st[b]!=0)
    {
         cout<<st[b]<<endl;
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}
/*5 1 2
  3 3 1 2 5*/
