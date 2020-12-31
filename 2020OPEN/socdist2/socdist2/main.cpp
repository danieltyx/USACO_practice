
#include"bits/stdc++.h"
using namespace std;
int tagg[100010];
int pos[100010];
int infected[100010];
int main()
{
    //freopen("socdist2.in","r",stdin);
    //freopen("socdist2.out","w",stdout);
    int n;
    int maxhere;
    int allinfected = 0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&pos[i],&tagg[i]);
        if(tagg[i]==1)allinfected ++;
    }
    int maxtrans = 999999999;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(pos[j]>pos[j+1])
            {
                swap(pos[j],pos[j+1]);
                swap(tagg[j],tagg[j+1]);
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(tagg[i]!=tagg[i+1])
        {
            maxhere = pos[i+1] - pos[i];
        }
        maxtrans = min(maxtrans,maxhere);
    }
    maxtrans --;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            infected[j] = 0;
        }
        int cowsnum = i;
        for(int j=1;j<=n;j++)// now it is which number infacted
        {
            if(tagg[j]==0)continue;
            if(infected[j]==1)continue;
            infected[j] = 1;
            for(int k=1;k<=maxtrans;k++)
            {
                if((pos[j+k] <= pos[j]+maxtrans) && tagg[j+k]==1 && j+k<=pos[n])
                {
                    infected[j+k] = 1;
                }
                if((pos[j-k] >= pos[j]-maxtrans) && tagg[j-k]==1 && j-k>=1)
                {
                    infected[j-k] = 1;
                }
            }
            cowsnum--;
            if(cowsnum==0) break;
        }
        int suss = 0;
        for(int i=1;i<=n;i++)
        {
            if(tagg[i]==1 && infected[i]==1) suss++;
        }
        if(suss==allinfected)
        {
            cout<<i<<endl;
            //fclose(stdin);
            //fclose(stdout);
            return 0;
        }
    }
    cout<<allinfected<<endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
