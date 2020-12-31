#include"bits/stdc++.h"
using namespace std;
int c[50][50][30];
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int m,n;
        cin>>m>>n;
        for(int j=0;j<=m;j++)
        {
            for(int q=1;q<=n;q++)
            {
                if(j==1||q==1||j==0) c[j][q][i]=1;
                else if(j<q) c[j][q][i] = c[j][j][i];
                else c[j][q][i] = c[j][q-1][i] + c[j-q][q][i];
            }
        }
        cout<<c[m][n][i]<<endl;
    }
    return 0;
}
