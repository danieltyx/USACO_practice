#include"bits/stdc++.h"
#define int long long
using namespace std;
int n,g;
struct Cows{
    int tm;// time
    int id;// old id
    int nid;//new id
    int m;// delta
    int gg = g; //amount
    bool operator< (const Cows y) const
    {
        return tm < y.tm;
    }
};
vector<Cows> vc;
vector<int> vw;
vector<int> vl;
bool cmp(Cows a, Cows b)
{
    return a.id < b.id;
}

int d[400400];
int cd[100100];
Cows cow[100100];
string a ="";
string b ="";

void buildtree(int l, int r, int p)
{
    if(l==r)
    {
        d[p] = g;
        return;
    }
    int m = (l + r) / 2;
    buildtree(l , m, p * 2);
    buildtree(m + 1, r, p * 2 + 1);
    d[p] = max( d[p * 2] , d[p * 2 + 1]);
}
void updatetree(int ul, int ur, int uv, int nl, int nr, int np)
{
    if(ul <= nl && ur >= nr)
    {
        d[np] += (nr - nl + 1) * uv;
        return;
    }
    int m = (nl + nr) / 2;
    if(ul <= m) updatetree(ul, ur, uv, nl, m, np * 2);
    if(ur > m) updatetree(ul, ur, uv, m+1, nr, np * 2 + 1);
    d[np] = max( d[np * 2], d[np * 2 + 1]);
}

string bestcows = "";
void searchintree(int l,int r, int mm,int p)
{
    if(d[p]==mm)
    {
        if(l==r)
        {
            bestcows += p;
            return;
        }
        int m = (l+r)/2;
        if(l<=m) searchintree(l,m,mm,p*2);
        if(r>m) searchintree(m+1,r,mm,p*2+1);
    }
}


signed main()
{
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
     cin>>n>>g;
     int ans = 0;
     Cows cow[100100];
     for(int i=1;i<=n;i++)
     {
         int a,b,c;
         scanf("%lld%lld%lld",&a,&b,&c);
         cow[i].tm = a;
         cow[i].id = b;
         cow[i].m = c;
         vc.push_back(cow[i]);
     }
     sort(vc.begin(),vc.end(),cmp);
     int newid = 1;
     int lastid = vc.begin()->id;
     vc.begin()->nid = 1;
     for(vector<Cows>::iterator it = vc.begin();it!=vc.end();++it)
     {
         if(it->id == lastid) it->nid = newid;
         else it->nid = ++newid;
         lastid = it->id;
     }
    sort(vc.begin(),vc.end());
    buildtree(1,newid,1);
    vl.push_back(0);
    
    bestcows = "";
    string lastcows ="";
    
    for(vector<Cows>::iterator it = vc.begin();it!=vc.end();++it)
    {
        int cow_nid = it->nid;
        int delta = it->m;
        updatetree(cow_nid,cow_nid,delta,1,newid,1);
        
        int afterd = d[1];
        bool lessg = false;
        if(afterd<g)
        {
            afterd = g;
            lessg = true;
        }
        
        bestcows = "";
        searchintree(1,newid,afterd,1);
        string nowcows = bestcows;
        if(afterd==g)
        {
            nowcows ="=";
            if(lessg==true)
            {
                nowcows ="null";
            }
        }
        if(nowcows.compare(lastcows)==0);
        else
        {
            ans++;
        }
        lastcows = nowcows;
    }
    
    cout<<ans<<endl;
    fclose(stdin);
     fclose(stdout);
    return 0;
}

/*
 4 10
 7 3 +3
 4 2 -1
 9 3 -1
 1 1 -2
 
 4 100
 1 101 +5
 2 102 +5
 3 101 +80
 4 101 -100
 */
