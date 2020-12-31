#include"bits/stdc++.h"
using namespace std;
string a;
string b[1000501];



int  main()
{
    cin>>a;
    transform(a.begin(),a.end(),a.begin(),::tolower);
    int k=1;
    getline(cin,b);
        transform(b[k].begin(),b[k].end(),b[k].begin(),::tolower);
        k++;
    }
    int cnt=0;
    int c=0;
    int u[1000501];
    for(int i=1;i<=k;i++)
    {
        if(b[i]==a)
        {
            cnt++;
            u[++c]=i;
        }
    }
    if(cnt==0)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<cnt<<" ";
    cout<<u[1]-1<<endl;
    return 0;
}
