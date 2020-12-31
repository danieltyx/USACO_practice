#include"bits/stdc++.h"
using namespace std;
int u[1001];
int prime[1001];
int n[1001];
int main()
{
    char a[1001];
    cin>>a;
    int len = strlen(a);
    int cnt=  1;
    int maxres= 1;
    int minres = 1000;
    sort(a,a+len);
    for(int i=0;i<len;i++)
    {
        if(a[i]==a[i+1])
        {
            n[cnt]++;
        }
        else
        {
            cnt++;
        }
    }
    for(int i=1;i<=cnt-1;i++)
    {
        n[i]++;
    }
    for(int i=1;i<=cnt-1;i++)
    {
        if(n[i]==len)
        {
            cout<<"Lucky Word"<<endl;
            cout<<len<<endl;
            return 0;
        }
        maxres=max(n[i],maxres);
        minres=min(n[i],minres);
    }
    int dif = maxres- minres;
    if(dif==0||dif==1)
    {
        cout<<"No Answer"<<endl;
        cout<<"0"<<endl;
        return 0;
    }
    if(dif==2)
    {
        cout<<"Lucky Word"<<endl;
        cout<<"2"<<endl;
        return 0;
    }
    int t= (int)sqrt(dif);
    for(int i=2;i<=t;i++)
    {
        if(dif%i==0)
        {
            cout<<"No Answer"<<endl;
            cout<<"0"<<endl;
            return 0;
        }
    }
    cout<<"Lucky Word"<<endl;
    cout<<dif<<endl;
    return 0;
    
}
 
