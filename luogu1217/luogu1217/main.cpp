#include"bits/stdc++.h"
using namespace std;
bool checkprim(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int getlenth(int n)//  find how many digits
{
    int cnt = 1;
    for(int i=1;i<=9;i++)
    {
        if(n/(int)pow(10,i)!=0)cnt++;
    }
    return cnt;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=n;i<=m;i=i+2)
    {
        
        if(checkprim(i)==true)//
        {
            int check = 0;
            int lens = getlenth(i);
            int k = 0;
            int j = lens-1;
            while(j>k)
            {
                int s =(int)pow(10,j);
                int b =(int)pow(10,k);
                if(i/s%10 != i/b%10)
                {
                    check++;
                }
                j--;
                k++;
            }
            if(check==0)cout<<i<<endl;
        }
    }
    return 0;
}
