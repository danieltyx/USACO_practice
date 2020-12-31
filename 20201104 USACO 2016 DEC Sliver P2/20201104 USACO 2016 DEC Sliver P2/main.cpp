#include"bits/stdc++.h"
using namespace std;
map<string,string> mp;
int n;
int main()
{
    cin>>n;
    int ans =0;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        a = a.substr(0,2);
        if(a.compare(b)==0) continue;
        mp[b][a]++;
        ans+= mp[a][b];
    }
    return 0;
}
