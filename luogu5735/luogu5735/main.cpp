#include"bits/stdc++.h"
using namespace std;
float dist(float x1,float y1,float x2,float y2)
{
    return sqrt((x2-x1)*(x2-x1) +(y2-y1)*(y2-y1));
}
int main()
{
    float sum = 0.00;
    float ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    sum += dist(ax,ay,bx,by);
    sum += dist(ax,ay,cx,cy);
    sum += dist(bx,by,cx,cy);
    printf("%0.2f",sum);
    return 0;
}
