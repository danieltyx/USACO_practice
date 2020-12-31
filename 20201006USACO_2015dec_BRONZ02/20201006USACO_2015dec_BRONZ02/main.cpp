#include"bits/stdc++.h"
using namespace std;
int rl[110];
int main()
{
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    int lcnt=0,scnt=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            rl[lcnt + j] = b;
        }
        lcnt += a;
    }
    int cs = 0;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            cs = max(b - rl[scnt + j],cs);
        }
        scnt += a;
    }
    cout<<cs<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
