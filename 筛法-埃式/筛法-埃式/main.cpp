#include"bits/stdc++.h"
using namespace std;
int u[100011];
int ans[100011];
int cnt = 0;
 int n;
void aishai(int x)
{
    u[0] = 1;// 这个数0是没被标记 1 是被标记了
    u[1] = 1;
    for(int i=2;i<=x;i++)
    {
        if(u[i]==0)
        {
            ans[++cnt]=i;
            for(int j=i*i;j<=n;j+=i)//从i*i开始因为 (i-n)*i 已经在i-1的轮次里算过了
            {
                u[j] = 1;
            }
        }
    }
}
int main()
{
    cin>>n;
    aishai(n);
    for(int i=1;i<=cnt;i++)cout<<ans[i]<<endl;
    return 0;
}
