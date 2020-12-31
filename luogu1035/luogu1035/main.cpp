#include"bits/stdc++.h"
using namespace std;
int main()
{
    double s =1.00;
    double k;
    cin>>k;
    for(double i=2;;i++)
    {
        s += 1/i;
        if(s > k)
        {
            cout<<i;
            return 0;
        }
    }
}
