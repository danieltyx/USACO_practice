#include"bits/stdc++.h"
using namespace std;
int a[100010];
int t[100010];
int s[100010];
int main()
{
    freopen("socdist1.in","r",stdin);
    freopen("socdist1.out","w",stdout);
    int n;
    cin>>n;
    int tcnt =1;
    string temp;
    cin>>temp;
    for(int i=1;i<=n;i++)
    {
        a[i]= temp.at(i-1)-'0';
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            t[tcnt++]=i;
        }
    }
    t[tcnt] = n+1;
    for(int i=1;i<tcnt;i++)
    {
        s[i]=t[i+1]-t[i]-1;
    }
    
    sort(s+1,s+tcnt,greater<int>());
    if(s[1]%2==0)
    {
        s[1] = (s[1]-1)/2;
    }
    else
    {
        s[1] = ceil(s[1]/2);
    }
    sort(s+1,s+tcnt,greater<int>());
    if(s[1]%2==0)
    {
        s[1] = (s[1]-1)/2;
    }
    else
    {
        s[1] = ceil(s[1]/2);
    }
    //s[1] = s[1]/2;
    sort(s+1,s+tcnt);
    cout<<s[1]+1<<endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
