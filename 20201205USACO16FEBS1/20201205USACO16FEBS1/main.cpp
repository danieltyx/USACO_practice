#include"bits/stdc++.h"
using namespace std;
int a[10010];
int o[10010];
priority_queue <int >  qu;
vector<int> vc;
int main()
{
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    int n;
    cin>>n;
    int fans = 9999999999;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        o[i] = a[i];
    }
    for(int k=0;k<n;k++)
    {
        vc.clear();
        while(!qu.empty())qu.pop();
        memset(a,0,sizeof(a));
        for(int i = 1;i<=n-k;i++)
        {
            a[i] = o[i+k];
        }
        int ncnt = 1;
        for(int i=n-k+1;i<=n;i++)
        {
            a[i] = o[ncnt++];
        }
//        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//        puts("");
        for(int i=n;i>=1;i--)
        {
            if(a[i]==0)
            {
                qu.push(i);
            }
            else
            {
                while(!qu.empty())
                {
                    a[i]--;
                    int np = qu.top();
                    qu.pop();
                    vc.push_back(np-i);
                    a[np] = 1;
                    if(a[i]==0)
                    {
                        qu.push(i);
                        break;
                    }
                }
            }
        }
        while(!qu.empty())qu.pop();
        int zerocnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)zerocnt++;
            else break;
        }
        if(zerocnt!=0)continue;
        int summ = 0;
        int l = vc.size();
        for(int i=0;i<l;i++)
        {
            summ += vc.at(i)*vc.at(i);
        }
//        cout<<summ<<endl;
        fans = min(summ,fans);
    }
    cout<<fans<<endl;
    return 0;
}
/*
 10
 1
 0
 0
 2
 0
 0
 1
 2
 2
 2
 
 10
 0
 1
 2
 2
 2
 1
 0
 0
 2
 0
 
 14
 0
 0
 0
 1
 2
 0
 0
 1
 3
 4
 0
 0
 1
 2
 
 

 */
