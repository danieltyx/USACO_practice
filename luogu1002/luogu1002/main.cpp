#include"bits/stdc++.h"
#define int long long
using namespace std;
int mapp[101][101];
int xx[9] = {0,1,1,-1,-1,2,2,-2,-2};
int yy[9] = {0,2,-2,2,-2,1,-1,1,-1};

signed main()
{
    int bx,by,cx,cy;
    cin>>bx>>by>>cx>>cy;
    mapp[0][0] = 1;
    mapp[0][1] = 1;
    mapp[1][0] = 1;
    for(int i=0;i<=8;i++)
    {
        int ncx = cx+xx[i];
        int ncy = cy+yy[i];
        if(ncx<0||ncy<0||ncx>bx||ncy>by)continue;
        if(ncx==0&&ncy==0)
        {
            cout<<"0";
            return 0;
        }
        mapp[ncx][ncy] = -1;
    }
    for(int i=0;i<=bx+1;i++)
    {
        for(int j=0;j<=by+1;j++)
        {
            if(mapp[i][j]==-1)continue;
    
            if(i==0&&j==0)continue;
            if(i==0)
            {
               if(mapp[i][j-1]==1)
               {
                   mapp[i][j]=1;
               }
                else
                {
                    mapp[i][j]=-1;
                }
                continue;
            }
            
            if(j==0)
            {
                if(mapp[i-1][j]==1)
                {
                    mapp[i][j]=1;
                }
                else
                {
                    mapp[i][j]=-1;
                }
                continue;
            }
            if(mapp[i-1][j] == -1 && mapp[i][j-1]==-1) continue;
            if(mapp[i-1][j]==-1)
            {
                mapp[i][j]=mapp[i][j-1];
                continue;
            }
            if(mapp[i][j-1]==-1)
            {
                mapp[i][j]=mapp[i-1][j];
                continue;
            }
            mapp[i][j] = mapp[i-1][j] + mapp[i][j-1];
        }
    }
    cout<<mapp[bx][by]<<endl;
    return 0;
}
