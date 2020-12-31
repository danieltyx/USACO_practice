#include"bits/stdc++.h"
using namespace std;
int main()
{
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    int x1,y1,x2,y2;
    int a1,b1,a2,b2;
    cin>>x1>>y1>>x2>>y2;
    cin>>a1>>b1>>a2>>b2;
    int i1,j1,i2,j2;
    i1 = min(x1,a1);
    j1 = min(y1,b1);
    i2 = max(x2,a2);
    j2 = max(y2,b2);
    int l = max(i2 - i1, j2 - j1);
    cout<<l*l<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
