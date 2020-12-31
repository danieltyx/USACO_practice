//插入排序
//保证总是有序的
//假设赌徒打牌
/*时间复杂度o（n^2）
 空间复杂度o（n）
 */
#include"bits/stdc++.h"
using namespace std;
int a[10] ={0,1,5,4,2,3};
int w[10];//当前手牌
int cnt;//w 中有的个数
int n =5;
void Insert(int x)
{
    int p;
    for(p=1;p<=cnt;p++)
    {
        if(w[p] > x)
        {
            break;
        }
    }
    for(int i=cnt;i>=p;i--)
    {
        w[i+1]=w[i];
    }
    w[p] = x;
    cnt++;
}
 
int main()
{
    for(int i=1;i<=n;i++)
    {
        Insert(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<w[i];
    }
    return 0;
}
