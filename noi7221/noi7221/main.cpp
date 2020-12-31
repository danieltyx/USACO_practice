#include"bits/stdc++.h"
using namespace std;
int csn=0;
int kn=0;
int csx[20][20];
int csy[20][20];
int r[20];
int c[20];
int k[20];
int sx[20];
int sy[20];
int uk[5][20];
char mapp[210][210][20];
int stp[210][210];
int xx[5]={0,0,0,1,-1};
int yy[5]={0,1,-1,0,0};
void bfs(int ii,int r,int c)
{
    memset(stp,0x3f,sizeof(stp));
    queue<int> qux;
    queue<int> quy;
    qux.push(sx[ii]);
    quy.push(sy[ii]);
    stp[sx[ii]][sy[ii]]=0;
    while(!qux.empty())
    {
        int x1 = qux.front();
        int y1 = quy.front();
        qux.pop();
        quy.pop();
        for(int i=1;i<=4;i++)
        {
            int x2 = x1 + xx[i];
            int y2 = y1 + yy[i];
            int t2 = stp[x1][y1] +1;
            if(x2<0||y2<0||x2>r||y2>c)continue;
            if(mapp[x2][y2][ii]== '#')continue;
            if(mapp[x2][y2][ii]== '$')
            {
                for(int j=1;j<=csn;j++)
                {
                    int xx1 = csx[j][ii];
                    int yy1 = csy[j][ii];
                    if(xx1==x2&&yy1==y2)continue;
                    qux.push(xx1);
                    qux.push(yy1);
                }
            }
            if(mapp[x2][y2][ii]== 'E')
            {
                if(kn>=k[ii])
                {
                    cout<<t2<<endl;
                    return;
                }
            }
            if(stp[x2][y2]>t2)
            {
                if(mapp[x2][y2][ii]== '0'&& uk[0][ii]==0)
                {
                    kn++;
                    uk[0][ii] =1;
                }
                if(mapp[x2][y2][ii]== '1'&& uk[1][ii]==0)
                {
                    kn++;
                    uk[1][ii] =1;
                }
                if(mapp[x2][y2][ii]== '2'&& uk[2][ii]==0)
                {
                    kn++;
                    uk[2][ii] =1;
                }
                if(mapp[x2][y2][ii]== '3'&& uk[3][ii]==0)
                {
                    kn++;
                    uk[3][ii] =1;
                }
                if(mapp[x2][y2][ii]== '4'&& uk[4][ii]==0)
                {
                    kn++;
                    uk[4][ii] =1;
                }
                stp[x2][y2] = t2;
                qux.push(x2);
                quy.push(y2);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        kn=0;
        csn=0;
        scanf("%d%d%d",&r[i],&c[i],&k[i]);
        int n = r[i];
        int m = c[i];
        
        for(int j=1;j<=n;j++)
        {
            for(int q=1;q<=m;q++)
            {
                char t;
                scanf("%c",&t);
                if(t =='\n')
                {
                    q--;
                    continue;
                }
                mapp[j][q][i] = t;
                if(t=='S')
                {
                    sx[i] = j;
                    sy[i] = q;
                }
                if(t=='$')
                {
                    csx[++csn][i] = j;
                    csy[++csn][i] = q;
                }
            }
        }
        bfs(i,n,m);
    }

    return 0;
}
