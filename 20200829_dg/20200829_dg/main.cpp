#include"bits/stdc++.h"
#include<vector>
using namespace std;
int n;
vector<int> vc;

void makeorder(int x)
{
    if( x == n + 1)
    {
        int l = vc.size();
        for(int i=0;i<l;i++)
        {
            printf("%d ",vc[i]);
        }
        puts("");
        return;
    }
    makeorder(x+1);
    vc.push_back(x);
    makeorder(x+1);
    vc.pop_back();
}

int main()
{
    
    cin>>n;
    makeorder(1);
    return 0;
    

}
