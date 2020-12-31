// http://poj.org/problem?id=1958
// 2020-09-04
//#include"bits/stdc++.h"
#include<stdio.h>
#include<iostream>
using namespace std;
int f3[100];
int f4[100];
void three_tower()
{
    for(int i=3;i<=15;i++)
    {
        f3[i] = 2 * f3[i-1] + 1;
    }
}

void four_tower()
{
    for(int i=4;i<=15;i++)
    {
        int tempmin = 99999;
        for(int k=1;k<i;k++)
        {
            tempmin = min(tempmin,2 * f4[i-k] + f3[k]);
        }
        f4[i] = tempmin;
    }
}
int main()
{
    
    f3[1]=1;
    f3[2]=3;
    f4[1]=1;
    f4[2]=3;
    f4[3]=5;
    three_tower();
    four_tower();
    for(int i=1;i<=12;i++)
    {
        cout<<f4[i]<<endl;
    }
   
    return 0;
    
}
