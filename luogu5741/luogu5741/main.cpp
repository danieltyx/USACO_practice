#include"bits/stdc++.h"
using namespace std;
struct student{
    string name;
    int c;
    int m;
    int e;
};
bool cmp(student x,student y)
{
    return x.name  < y.name;
}
int main()
{
    int n;
    cin>>n;
    student a[10001];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].name>>a[i].c>>a[i].m>>a[i].e;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            
            if(abs(a[i].c-a[j].c)<=5 &&
               abs(a[i].m-a[j].m)<=5 &&
               abs(a[i].e-a[j].e)<=5 &&
               abs(a[i].c + a[i].m + a[i].e
                   - a[j].c - a[j].m - a[j].e )<=10)
            {
                cout<<a[i].name<<" "<<a[j].name<<endl;
            }
        }
    }
    
}
