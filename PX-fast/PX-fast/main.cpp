#include "bits/stdc++.h"
using namespace std;
int a[10] = {0,1,4,2,3,5};
int main()
{
    
    sort(a+1,a+6,greater<int>());// a[0]... a[5] 左闭又开 a+5是五个元素
    //默认从小到大
    for(int i=1;i<=5;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
