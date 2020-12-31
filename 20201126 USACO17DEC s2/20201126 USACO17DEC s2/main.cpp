#include"bits/stdc++.h"
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
        if(tm == y.tm)
        {
            if(gg == y.gg)
            {
                return nid < y.nid;
            }
            return gg > y.gg;
        }
        return tm < y.tm;
    }
};
map<int,Cows> mp;
vector<Cows> vc;
set<Cows> st;
bool cmp(Cows a, Cows b)
{
    return a.id < b.id;
}
int main()
{
   // freopen("measurement.in","r",stdin);
   // freopen("measurement.out","w",stdout);
    cin>>n>>g;
    int ans = 0;
    Cows cow[100100];
    for(int i=1;i<=n;i++)
    {
        int a,b,d;
        string c;
        cin>>a>>b>>c;
        if(c[0] == '-')
        {
            d = - (c[1] - '0');
        }
        else
        {
            d = c[1] - '0';
        }
        cow[i].tm = a;
        cow[i].id = b;
        cow[i].m = d;
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
    for(vector<Cows>::iterator it = vc.begin();it!=vc.end();++it)
    {
        it->tm = 0;
    }
    Cows ncow[100100];
    vector<Cows> vwall;
    set<Cows> sw;
    for(vector<Cows>::iterator it = vc.begin();it!=vc.end();++it)
    {
        if(ncow[it->nid].m!=0)
        {
            st.erase(ncow[it->nid]);
            int pregg = ncow[it->nid].gg;
            ncow[it->nid] = *it;
            ncow[it->nid].gg = pregg + it->m;
            st.insert(ncow[it->nid]);
        }
        else
        {
            ncow[it->nid] = *it;
            ncow[it->nid].gg += it->m;
            st.insert(ncow[it->nid]);
        }
        int bestGg = st.begin()->gg;
        if(sw.empty())
        {
            ans++;
            for(set<Cows>::iterator it = st.begin(); it!=st.end();++it)
            {
                if(it->gg == bestGg) sw.insert(*it);
                else break;
            }
        }
        else
        {
            set<Cows> tempsw;
            for(set<Cows>::iterator it = st.begin(); it!=st.end();++it)
            {
                if(it->gg == bestGg) tempsw.insert(*it);
                else break;
            }
            if(sw.size()!=tempsw.size())
            {
                ans++;
                sw.swap(tempsw);
            }
            else
            {
                bool flag = true;
                set<Cows>::iterator it1;
                set<Cows>::iterator it2;
                for (it1 = sw.begin(), it2 = tempsw.begin(); it1 != sw.end(); it1++, it2++){
                    if (it1->nid != it2->nid){
                        flag = false;
                        break;
                    }
                }
                if(flag == false)
                {
                    ans++;
                    sw.swap(tempsw);
                }
            }
        }
    }
    cout<<ans<<endl;
  // fclose(stdin);
   // fclose(stdout);
    return 0;
}

/*
 
5 10
7 233 +3
4 232 -1
9 233 -1
1 231 +2
11 232 +4

 
 4 100
 1 101 +5
 2 102 +5
 3 103 +6
 4 103 -1

*/
