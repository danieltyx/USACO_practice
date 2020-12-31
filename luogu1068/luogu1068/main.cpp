#include"bits/stdc++.h"
using namespace std;
struct People{
    int idnum;
    int score;
};
bool cmp(People x, People y)
{
    if(x.score==y.score)
    {
        return x.idnum<y.idnum;
    }
    else
    {
        return x.score>y.score;
    }
}
int main()
{
    People a[10010];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].idnum,&a[i].score);
    }
    
    int scorepeople = m*3/2;
    sort(a+1,a+n+1,cmp);
    int finalscore = a[scorepeople].score;
    int tcnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].score>=finalscore)tcnt++;
    }
    cout<<finalscore<<" "<<tcnt<<endl;
    
    for(int i=1;i<=tcnt;i++)
    {
        cout<<a[i].idnum<<" ";
        cout<<a[i].score<<endl;
    }
    return 0;
}

