// each point

#include"bits/stdc++.h"
using namespace std;
int ml[110];
int mr[110];
int seq[10100];
int recseq[2000][10010];
int n,m,k;
void keepmv()
{
    for(int i = 1;i<=m;i++)
    {
        for(int j = ml[i];j<=mr[i];j++)
        {
            if(j>=mr[i]-(j-ml[i]))break;
            int temp = seq[j];
            seq[j] = seq[mr[i]-(j-ml[i])];
            seq[mr[i]-(j-ml[i])] = temp;
        }
    }
}
bool isfinished()
{
    for(int i=1;i<=n;i++)
    {
        if(seq[i]!=i)return false;
    }
    return true;
}
int main()
{
    freopen("swap.in","r",stdin);
    freopen("swap.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>ml[i]>>mr[i];
    }
    for(int i=1;i<=n;i++)
    {
        seq[i] = i;
    }
    bool rep = false;
    int rcnt = 0;
    while(!rep)
    {
        for(int i=1;i<=n;i++)
        {
            recseq[rcnt][i] = seq[i];
        }
        rcnt++;
  
        keepmv();
        rep = isfinished();
    }
    k = k%rcnt;
    for(int i=1;i<=n;i++)
    {
        cout<<recseq[k][i]<<endl;
    }
    return 0;
}
