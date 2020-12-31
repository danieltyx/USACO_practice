#include"bits/stdc++.h"
using namespace std;
int mmap[10][10][10];
int line[10][10];
int col[10][10];
int sec[10][10];
int xx[101];
int yy[101];
int zz[101];
int all=0;
int dfs(int kk)
{
    int i = xx[kk];
    int j = yy[kk];
    int markk = zz[kk];
    for(int s=1;s<=9;s++)
    {
        if(line[i][s]!=0)continue;
        if(col[j][s]!=0)continue;
        if(sec[markk][s]!=0)continue;
        mmap[i][j][markk] = s;
        line[i][s]++;
        col[j][s]++;
        sec[markk][s]++;
        if(kk==all)
        {
            return 1;
        }
        else
        {
            int rst = dfs(kk+1);
            if(rst == 1) return 1;
        }
        line[i][s]--;
        col[j][s]--;
        sec[markk][s]--;
        mmap[i][j][markk] = 0;
    }
    return 0;
}
int main()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            int k;
            if(i<=3&&j<=3)k=1;
            else if(i>3&&i<=6&&j<=3)k=2;
            else if(i>6&&i<=9&&j<=3)k=3;
            else if (i<=3&&j>3&&j<=6)k=4;
            else if(i>3&&i<=6&&j>3&&j<=6)k=5;
            else if(i>6&&i<=9&&j>3&&j<=6)k=6;
            else if(i<=3&&j>6&&j<=9)k=7;
            else if(i>3&&i<=6&&j>6&&j<=9)k=8;
            else if(i>6&&i<=9&&j>6&&j<=9)k=9;
            int t;
            scanf("%d",&t);
            mmap[i][j][k] = t;
            sec[k][t]++;
            line[i][t]++;
            col[j][t]++;
            if(t==0)
            {
                all++;
                xx[all] = i;
                yy[all] = j;
                zz[all] = k;
            }
        }
    }
    dfs(0);
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=9;k++)
            {
                if(mmap[i][j][k]==0)continue;
                cout<<mmap[i][j][k]<<" ";
            }
        }
        cout<<endl;
    }
}
