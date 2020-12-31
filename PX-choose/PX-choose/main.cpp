//选择排序模版
/*
 复杂度分析：o(n^2)
 空间复杂度：o（1）
 */

#include"bits/stdc++.h"
using namespace std;
int a[10]  = {0,1,5,4,2,3};
int n =5;
void selectSort()
{
    for(int c=1;c<=n;c++)
    {
        int x = c;
        for(int i=c+1;i<=n;i++)
        {
           if(a[i]<a[x])
           {
               x = i;
           }
        }
        swap(a[x],a[c]);
       /* for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
        puts("");// == printf("\n") 加回车的字符串输出
        */
    }
}
int main()
{
    selectSort();
    return 0;
}
