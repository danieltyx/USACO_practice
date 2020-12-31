#include"bits/stdc++.h"
using namespace std;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    if(a<=c && c<=b && b<=d)
    {
        cout<<d-a<<endl;
    }
    else if(c<=a && b>=d && a<=d)
    {
        cout<<b-c<<endl;
    }
    else if(a<=c && d<=b)
    {
        cout<<b-a<<endl;
    }
    else if(c<=a && b<=d)
    {
        cout<<d-c<<endl;
    }
    else
    {
        cout<<(b-a)+(d-c)<<endl;
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
