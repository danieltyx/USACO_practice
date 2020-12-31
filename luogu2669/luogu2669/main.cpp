#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum =0;
    int day =0;
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
             day++;
            if(day==n)
            {
                sum+= i;
                cout<<sum<<endl;
                return 0;
            }
            sum+= i;
        }
    }
}
