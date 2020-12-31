#include"bits/stdc++.h"
using namespace std;
const int G = 100100;
double a[G];
double s[G];
double f[G];
int main()
{
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
     cin>>a[i];
    }
    s[1] = a[n];
    for(int i=2;i<=n;i++)
    {
        s[i] = s[i-1] + a[n-i+1];
    }
    
    double mi = a[n];
    double mxs = -1;
    for(int i=2;i<n;i++)
    {
        mi = min(a[n-i+1],mi);
        f[i] = (s[i] - mi)/(i - 1);
        mxs = max(mxs,f[i]);
    }
    for(int i=n-1;i>=2;i--)
    {
        if( abs(mxs - f[i]) <=0.0001)
        {
            cout<<n-i<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
 10
 3 3 3 3 3 3 3 2 2 2
 */
