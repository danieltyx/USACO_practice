#include"bits/stdc++.h"
using namespace std;
const int dfsize = 1000;
int a[11];
int b[11];
int df[dfsize];
int dfcnt = 1;
int df2[dfsize];
int dfcnt2 =1;
vector<int> vc;
vector<int> vc2;
set<int> dfset;
void mix1(int x)
{
    for(int i=1;i<=11;i++)
    {
        int x1 = vc2.at(i);
        int mc = x1 - a[x];
        //cout<<mc<<" ";
        df[dfcnt++]=mc;
    }
    
    
    //puts("");
}

void mix2(int x)
{
    for(int i=1;i<=11;i++)
    {
        int x1 = vc2.at(i);
        int mc = x1 - a[x];
        //cout<<mc<<endl;
        //cout<<mc<<" ";
        df2[dfcnt2++] = mc;
    }
    
    //puts("");
}
int main()
{
    freopen("backforth.in","r",stdin);
    freopen("backforth.out","w",stdout);
    vc.push_back(0);
    vc2.push_back(0);
    for(int i=1;i<=10;i++)
    {
        cin>>a[i];
        vc.push_back(a[i]);
    }
    for(int i=1;i<=10;i++)
    {
        cin>>b[i];
        vc.push_back(b[i]);
        vc2.push_back(b[i]);
    }
    
    for(int i=1;i<=9;i++)
    {
        vc2.push_back(a[i]);
        mix1(i);
        vc2.pop_back();
        for(int j=i+1;j<=10;j++)
        {
            vc2.push_back(a[j]);
            mix2(j);
            vc2.pop_back();
            for(int q=1;q<=dfcnt-1;q++)
            {
                for(int k=1;k<=dfcnt-1;k++)
                {
                    if(q!=11 & q==k)continue;
                    dfset.insert(df[q]+df2[k]);
                }
            }
            dfcnt2 = 1;
        }
        dfcnt =1;
    }
    
    cout<<dfset.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
 1 1 1 1 1 1 1 1 1 2
 2 2 2 2 2 2 2 2 3 4
 */
