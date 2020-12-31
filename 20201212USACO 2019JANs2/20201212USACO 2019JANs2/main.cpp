#include"bits/stdc++.h"
using namespace std;
int n;
int mp[1010][1010];
int v[1010][1010];
int num = 0;
int per = 0;
int xx[5] = {0,1,-1,0,0};
int yy[5] = {0,0,0,1,-1};
void dfs(int x,int y)
{
    for(int i=1;i<=4;i++)
    {
        int x1 = x + xx[i];
        int y1 = y + yy[i];
        if(v[x1][y1])continue;
        if(x1<0||x1>n||y1<0||y1>n||mp[x1][y1]==0)
        {
            per++;
            continue;
        }
        v[x1][y1] = 1;
        num ++;
        dfs(x1,y1);
    }
}
int main()
{
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        for(int j=0;j<n;j++)
        {
            if(a[j]=='#')mp[i][j+1]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j]==0)continue;
            int oldn = num;
            int oldp = per;
            num = 1;
            per = 0;
            v[i][j] =1;
            dfs(i,j);
            if(oldn>num)
            {
                num = oldn;
                per = oldp;
            }
            else if(oldn == num)
            {
                if(oldp <per)
                {
                    num = oldn;
                    per = oldp;
                }
            }
        }
    }
    cout<<num<< " "<<per<<endl;
    return 0;

}

/*
 
 for(int i=1;i<=n;i++)
 {
     for(int j=1;j<=n;j++)
     {
         cout<<mp[i][j];
     }
     puts("");
 }
 */

/*
 5
.....
.....
.....
.....
.....
 */
