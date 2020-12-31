#include"bits/stdc++.h"
using namespace std;
int a[100100];
int v[100100];
vector<int> vc;
int main()
{
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n; i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)continue;
        int fp = a[i];
        v[i] = 1;
        vc.clear();
        vc.push_back(fp);
        memset(v,0,sizeof(v));
        for(int j=1;j<n;j++)
        {
            if(fp==0)break;
            if(v[fp]==1)break;
            v[fp]=1;
            fp = a[fp];
            vc.push_back(fp);
        }
        int l = vc.size();
        if(vc.front()==vc.back())
        {
            for(int j=0; j<l; j++)
            {
                a[vc.at(j)] = 0;
            }
        }
       
        //cout<<1<<endl;
    }
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0)cnt++;
    }
    cout<<n-cnt<<endl;
    fclose(stdin);
     fclose(stdout);
    return 0;
}
/*
 5
5 4 3 2 2
 */
