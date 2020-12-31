#include"bits/stdc++.h"
using namespace std;
int main()
{
    int a;
    int save = 0;//自己这个月用的钱
    int sum =0;// 给mm的钱
    for(int i=1;i<=12;i++)
    {
        scanf("%d",&a);
        int left = 300-a;//这个月剩的钱
        if(left+save < 0)
        {
            cout<<"-"<<i<<endl;
            return 0;
        }
        int all = left+save;
        int multi = all/100;
        save = all%100;
        sum += multi*100;
    }
    cout<<sum*6/5+save<<endl;
    return 0;
}
