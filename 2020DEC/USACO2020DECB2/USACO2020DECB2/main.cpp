#include"bits/stdc++.h"
using namespace std;
int a[110];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans = n;
    for(int i=1;i<=n;i++)
    {
        int sum = a[i];
        for(int j=i+1;j<=n;j++)
        {
            sum+= a[j];
            bool hasit = false;
            if(sum%(j-i+1)!=0)continue;
            int ave = sum/(j-i+1);
            for(int k=i;k<=j;k++)
            {
                if(a[k]==ave)hasit =true;
            }
            if(hasit==true)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
