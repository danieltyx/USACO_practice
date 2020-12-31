//冒泡排序模版
/*
 每一趟确定画最后一个 /最大的一个
 复杂度： O（n^2）
 空间复杂度 O（1）
 */

#include "bits/stdc++.h"
using namespace std;
int n = 5;
int a[10]  = {0,1,5,4,9,3};
void bubbleSort()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)//优化版本 j<n change to j<=n-1 常数更改
        {
            if(a[j] > a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
        puts("");
    }
}
int main()
{
    bubbleSort();
}
