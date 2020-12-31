#include"bits/stdc++.h"
using namespace std;
int a[500];
int b[500];
int c[500];
int dp[500][500];
int mark[500];
vector <int> vc[210][210];
int main()
{
    int m,v,n;
    cin>>m>>v>>n;
   for(int i=1;i<=n;i++)
   {
       scanf("%d%d%d",&a[i],&b[i],&c[i]);
   }
    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=b[i];j--)
        {
            for(int k=m;k>=a[i];k--)
            {
                dp[j][k] = max(dp[j][k],dp[j-b[i]][k-a[i]]+c[i]);
                if(dp[j][k]==dp[j-b[i]][k-a[i]]+c[i])
                {
                    vc[j][k].clear();
                    vc[j][k].assign(vc[j-b[i]][k-a[i]].begin(),vc[j-b[i]][k-a[i]].end());
                    vc[j][k].push_back(i);
                }
            }
        }
    }
    cout<<dp[v][m]<<endl;
    int l = vc[v][m].size();
    for(int i=0;i<l;i++)
    {
        cout<<vc[v][m].at(i)<<" ";
    }
    return 0;
}
