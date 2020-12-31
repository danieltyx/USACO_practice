#include"bits/stdc++.h"
using namespace std;
int ffriend[10010];

int find(int x)
{
    if(ffriend[x]!=x)
    {
        ffriend[x] = find(ffriend[x]);
    }
    return ffriend[x];
}
void makeunion(int a,int b)
{
    int t1 = find(a);
    int t2 = find(b);
    ffriend[t1] = t2;
}
int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n,m;
        cin>>n>>m;
        int cntboard[1010];
        memset(cntboard,0,sizeof(cntboard));
        memset(ffriend,0,sizeof(ffriend));
        int cnt = 0;
        for(int i=1;i<=1010;i++)
        {
            ffriend[i] = i;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            if(find(a)!=find(b)) makeunion(a,b);
        }
        for(int i=1;i<=n;i++)
        {
            cntboard[find(i)]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(cntboard[i]!=0)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
