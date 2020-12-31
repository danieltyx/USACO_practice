#include"bits/stdc++.h"
using namespace std;
int n=302;
int m;
int tmp[350][350];
int mp[350][350];
int xx[5] = {0,0,0,1,-1};
int yy[5] = {0,1,-1,0,0};
void bfs()
{
    memset(mp,0x3f,sizeof(mp));
    if(tmp[0][0]==0x3f3f3f3f)
    {
        cout<<"0";
        return;
    }
    mp[0][0] = 0;
    queue<int> qux;
    queue<int> quy;
    qux.push(0);
    quy.push(0);
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
            int t2 = mp[x1][y1] + 1;
            if(x2>=0&&y2>=0&&x2<=n&&y2<=n&&mp[x2][y2]>t2&&tmp[x2][y2]>t2)
            {
                mp[x2][y2] = t2;
                qux.push(x2);
                quy.push(y2);
                if(tmp[x2][y2]==0x3f3f3f3f)
                {
                    cout<<t2;
                    return;
                }
            }
            
        }
    }
    cout<<"-1";
}
int main()
{
    memset(tmp,0x3f,sizeof(tmp));
    cin>>m;
    int x,y,t;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&t);
        for(int j=0;j<=4;j++)
        {
            int x1 = x + xx[j];
            int y1 = y + yy[j];
            if(x1<0||y1<0||x1>n||y1>n)continue;
            if(tmp[x1][y1]<t)continue;
            tmp[x1][y1] = t;
        }
    }
    bfs();
    return 0;
}
