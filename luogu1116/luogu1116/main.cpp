#include"bits/stdc++.h"
using namespace std;
int n;
int cnt = 0;
int a[100010];
void Bubblesort()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                cnt++;
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    Bubblesort();
    cout<<cnt<<endl;
    return 0;
}
