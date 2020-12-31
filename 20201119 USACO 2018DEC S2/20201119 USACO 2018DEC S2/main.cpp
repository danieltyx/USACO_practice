#include"bits/stdc++.h"
using namespace std;
struct Cows{
    int p;
    int a;
    int ba;
    int t;
    bool m=false;
    bool operator< (const Cows y) const
    {
        return p > y.p;
    }
};


bool cmp(Cows x,Cows y)
{
    return x.a<y.a;
}
int n;
int wt = -1;
int wtcnt =1;
int tt =0;
int cn = 0;
Cows c[100100];

priority_queue<Cows> f;
void qs()
{
    while(!f.empty())
    {
        Cows temp = f.top();
        f.pop();
        wt= max(wt,tt - temp.ba);
        tt += temp.t;
        for(int i = cn;i<=n;i++)
        {
            if(c[i].a >=tt)break;
            if(c[i].a <= tt && c[i].m == false)
            {
                c[i].a = 0;
                c[i].m = true;
                f.push(c[i]);
                cn++;
            }
        }
        if(f.empty())
        {
            if(cn<=n)
            {
                f.push(c[cn+1]);
                tt = c[cn+1].a;
                c[cn+1].m=true;
                cn++;
            }
            else return;
        }
    }
    return;
}
int main()
{
    freopen("convention2.in","r",stdin);
   freopen("convention2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&c[i].a,&c[i].t);
        c[i].ba = c[i].a;
        c[i].p = i;
    }
    sort(c+1,c+1+n,cmp);
    //for(int i=1;i<=n;i++) cout<<c[i].p<<" "<<c[i].a<<" "<<c[i].t<<endl;
    tt = c[1].a;
    f.push(c[1]);
    c[1].m=true;
    cn++;
    qs();
    cout<<wt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
    
}


/*
 8
 20 3
 20 40
 50 5
 55 15
 45 5
 105 5
 19342433 235
 19342433 23
 */
