#include"bits/stdc++.h"
using namespace std;
struct student
{
    string name;
    int math;
    int chinese;
    int english;
    int sum;
};
bool cmp(student x, student y)
{
    //if((x.chinese+x.math+x.english)!= (y.chinese+y.math+y.english))
    return x.chinese+x.math+x.english >y.chinese+y.math+y.english;
}
student a[10001];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].name>>a[i].chinese>>a[i].math>>a[i].english;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=1;i++)
    {
        cout<<a[i].name<<" "<<a[i].chinese<<" "<<a[i].math<<" "<<a[i].english<<endl;
    }
    return 0;
}
