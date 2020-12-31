#include"bits/stdc++.h"
using namespace std;
const int INF = 2147483646;
struct Cow{
    char d;
    int x;
    int y;
    int s = INF;
} c[1010];
struct Node{
    int c1;
    int c2;
    int cmin = INF;
    int n1;
    int n2;
} con[10101010];
int concnt = 1;
bool cmp(Node aa, Node bb)
{
    if(aa.cmin != bb.cmin)
    {
        return aa.cmin<bb.cmin;
    }
    return aa.n1 < bb.n1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i].d;
        scanf("%d",&c[i].x);
        scanf("%d",&c[i].y);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(c[i].d=='E' && c[j].d=='N')
            {
                int c1 = c[j].x - c[i].x;
                int c2 = c[i].y - c[j].y;
                if(c1<0 ||c2<0)continue;
                int n1 = i;//c1>c2 i die
                int n2 = j;
                con[concnt].c1 = c1;//horizontal s
                con[concnt].c2 = c2;
                con[concnt].n1 = n1;
                con[concnt].n2 = n2;
                con[concnt].cmin = min(c1,c2);
                concnt++;
            }
            if(c[i].d=='N' && c[j].d=='E')
            {
                int c1 = c[i].x - c[j].x;
                int c2 = c[j].y - c[i].y;
                if(c1<0 ||c2<0)continue;
                int n1 = j;
                int n2 = i;
                con[concnt].c1 = c1;
                con[concnt].c2 = c2;
                con[concnt].n1 = n1;
                con[concnt].n2 = n2;
                con[concnt].cmin = min(c1,c2);
                concnt++;
            }
        }
    }
    sort(con+1,con+concnt+1,cmp);
    for(int i=1;i<=concnt;i++)
    {
        int c1 = con[i].c1;
        int c2 = con[i].c2;
        int n1 = con[i].n1;
        int n2 = con[i].n2;
        if(c[n1].s < c1 || c[n2].s < c2)continue;
        if(c1>c2)
        {
            c[n1].s = c1;
        }
        else if(c1<c2)
        {
            c[n2].s = c2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i].s == INF) cout<<"Infinity"<<endl;
        else cout<<c[i].s<<endl;
    }
    return 0;
}
 
/*
 9
 E 3 5
 N 5 3
 E 4 6
 E 10 4
 N 11 2
 N 8 1
 E 6 2
 E 9 7
 N 12 8
 */
