#include"bits/stdc++.h"
using namespace std;
float w[500000];
int ww[500000];
int v[500];
int dp[500];
int main()
{
    int alln;
    cin>>alln;
    for(int all=1;all<=alln;all++)
    {
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        float maxw;
        int n;
        cin>>maxw>>n;
        int maxww = maxw*10000;
        for(int i=1;i<=n;i++)
        {
            int ww;
            scanf("%d%f",&v[i],&w[i]);
            ww[i]= w[i]*10000;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=maxww;j>=0;j++)
            {
                if(j-ww[i]<0)continue;
                
                dp[j] = max(dp[j],dp[j-ww[i]]+v[i]);
            }
        }
        cout<<dp[maxw]<<endl;
    }
    return 0;
}
