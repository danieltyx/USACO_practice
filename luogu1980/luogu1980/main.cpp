#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    int f;
    cin>>n>>f;
    int cnt =0;
    int dig =1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(i>=(int)pow(10,j))dig=j+1;
            else break;
        }
        if(i%10==f)cnt++;
        for(int j=1;j<=dig-1;j++)
        {
            if(i/(int)pow(10,j)%10==f)cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
