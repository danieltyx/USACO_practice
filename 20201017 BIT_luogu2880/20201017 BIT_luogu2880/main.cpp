#include"bits/stdc++.h"
using namespace std;

int treen[9] = {0,1,1,3,1,4,2,11,1};
int a[9] = {0,1,5,3,9,4,2,11,14};

int lowbit(int x)
{
    return x&-x;
}

int _findmin(int x, int y)
{
    cout<<"X: "<<x<<"  Y:"<<y<<"  y-lowbit(y):"<<y - lowbit(y)<<endl;
    if(y > x)
    {
        
        if(y - lowbit(y) > x)
        {
            cout<<"1step"<<endl;
            return min(treen[y], _findmin(x, y - lowbit(y)));
        }
        else
        {
            cout<<"2step"<<endl;
            return min(a[y], _findmin(x, y - 1));
        }
    }
    return a[x];
}

int main()
{
   
    
    cout<<_findmin(2,8)<<endl;
    
    
    return 0;
}

