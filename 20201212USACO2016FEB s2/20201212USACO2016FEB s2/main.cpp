#include"bits/stdc++.h"
using namespace std;
const int MAXN = 4010;
struct Point{
    int ox;
    int oy;
    int x;
    int y;
    bool operator< (const Point sp) const
    {
        if(ox != sp.ox) return ox<sp.ox;
        return oy < sp.oy;
    }
};
bool cmp(Point xx,Point yy)
{
    
    if(xx.oy != yy.oy) return xx.oy <yy.oy;
    return xx.ox < yy.ox;
}
Point p[MAXN];
int s[MAXN][MAXN];
int mp[MAXN][MAXN];
int r[MAXN];
int main()
{
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].ox,&p[i].oy);
    }
    sort(p,p+n+1);
    int xp = -1;
    int yp = -1;
    for(int i=1;i<=n;i++)
    {
        if(p[i].ox == p[i-1].ox) p[i].x = p[i-1].x;
        else
        {
            xp+=2;
            p[i].x = xp;
        }
    }
    sort(p,p+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(p[i].oy == p[i-1].oy) p[i].y = p[i-1].y;
        else
        {
            yp+=2;
            p[i].y = yp;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        int xn = p[i].x;
        int yn = p[i].y;
        mp[xn][yn] = 1;
    }

    for(int i=2;i<=xp+2;i+=2)
    {
        for(int j=2;j<=yp+2;j+=2)
        {
            s[i][j] = s[i-2][j] + s[i][j-2] - s[i-2][j-2] + mp[i-1][j-1];
        }
    }
    int rcnt = 1;
    for(int i=2;i<=xp+1;i+=2)
    {
        for(int j=2;j<=yp+1;j+=2)
        {
            int s1 = s[i][yp+1] - s[i][j];
            int s2 = s[i][j];
            int s3 = s[xp+1][j] - s[i][j];
            int s4 = n - s[i][yp+1] - s[xp+1][j]+ s[i][j];
            r[rcnt++] = max(max(s1,s2),max(s3,s4));
            if(n/4 == r[rcnt])
            {
                cout<<n/4<<endl;
                return 0;
            }
        }
    }
    int mins = 9999;
    for(int i=1;i<rcnt;i++)
    {
        mins = min(mins,r[i]);
    }
    cout<<mins<<endl;
    return 0;
    
}
