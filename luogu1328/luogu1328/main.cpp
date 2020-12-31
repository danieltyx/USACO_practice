#include"bits/stdc++.h"
using namespace std;
int x[500010];
int y[500010];
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int cnta = 0;
    int cntb = 0;
    for(int i=1;i<=a;i++)
    {
        scanf("%d",&x[i]);
        for(int j=1;j<=210;j++)
        {
            x[i+a*j] = x[i];
        }
    }
    for(int i=1;i<=b;i++)
    {
        scanf("%d",&y[i]);
        for(int j=1;j<=210;j++)
        {
            y[i+b*j] = y[i];
        }
    }
    
    
    for(int i=1;i<=n;i++)
    {
        if(x[i]==y[i])continue;
        if(x[i]==0&&y[i]==1)cntb++;
        if(x[i]==0&&y[i]==2)cnta++;
        if(x[i]==0&&y[i]==3)cnta++;
        if(x[i]==0&&y[i]==4)cntb++;
        
        if(x[i]==1&&y[i]==0)cnta++;
        if(x[i]==1&&y[i]==2)cntb++;
        if(x[i]==1&&y[i]==3)cnta++;
        if(x[i]==1&&y[i]==4)cntb++;
        
        if(x[i]==2&&y[i]==0)cntb++;
        if(x[i]==2&&y[i]==1)cnta++;
        if(x[i]==2&&y[i]==3)cntb++;
        if(x[i]==2&&y[i]==4)cnta++;
        
        if(x[i]==3&&y[i]==0)cntb++;
        if(x[i]==3&&y[i]==1)cntb++;
        if(x[i]==3&&y[i]==2)cnta++;
        if(x[i]==3&&y[i]==4)cnta++;
        
        if(x[i]==4&&y[i]==0)cnta++;
        if(x[i]==4&&y[i]==1)cnta++;
        if(x[i]==4&&y[i]==2)cntb++;
        if(x[i]==4&&y[i]==3)cntb++;
    }
    cout<<cnta<<" "<<cntb<<endl;
    return 0;
}
