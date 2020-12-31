#include"bits/stdc++.h"
#define NooN int
using namespace std;
int a[10001];
int f[10001];
int main()
{
    int n;
    int len =0;
    memset(f,0x3f,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int pos = lower_bound(f+1, f+1+len,a[i]) - f;
        if(pos==len+1) 
        {
            len++;
        }
        f[len]=min(f[len],a[i]);
    }
    cout<<len;
    return 0;
}






/*

洛谷 p1567 统计天数
p1020 题解 求最长上升子序列
P1439 【模板】最长公共子序列
洛谷P1091_合唱队形
P3902 递增
P1637 三元上升子序列
hdu 1003 Max Sum
hdu 1087 Super Jumping!
uva 10635 Prince and Princess LCS转化成LIS
P2516 [HAOI2010]最长公共子序列
poj 1239 Increasing Sequence 两次dp
p2757

*/


