/*
ID: danielt15
TASK: friday
LANG: C++
*/
#include"bits/stdc++.h"
using namespace std;
int r[8];
int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int saveday[100001];
int p[100001];
int sum=0;
int leap=0;
int yearnow=1900;
int yearc=0;
int n;
void printtheresult()
{
    cout<<r[6]<<" ";
    cout<<r[7]<<" ";
    cout<<r[1]<<" ";
    cout<<r[2]<<" ";
    cout<<r[3]<<" ";
    cout<<r[4]<<" ";
    cout<<r[5]<<endl;
}
void makesureweek()
{
    for(int i=2;i<=sum;i++)
    {
        int z,caculated_day;
        z = saveday[i]/7;
        caculated_day = saveday[i]-7*z;
        if(saveday[i]%7==0)caculated_day=7;
        for(int k=7;k>=1;k--)
        {
            if((caculated_day)%k==0)
            {
                //cout<<"i: "<<i<<"   saveday[i]:  "<<saveday[i]<<"    caculated_day:     "<<caculated_day<<endl;
                r[k]++;
                break;
            }
        }
    }
    r[6]++;
}
int main()
{
    //freopen("friday.in","r",stdin);
    //freopen("friday.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n-1;i++)
    {
        if((1900+i)%4==0 && (1900+i)%100!=0)
        {
            leap++;
        }
        else if((1900+i)%400==0)
        {
            leap++;
        }
        else
        {
            continue;
        }
    }
    int allday = 366*leap +365*(n-leap)-1;
    p[0] = 0;
    p[1] = 13;
    for(int i=2;i<=100010;i++)
    {
        int numa;
        int aftera;
        yearc++;
        if(yearc == 12)
        {
            yearnow++;
            yearc=0;
        }
        if(
        (yearnow%4==0 && yearnow%100!=0)
        ||
        (yearnow%400==0)
        )
        {
            //leap
            if(i%12==0)
            {
                aftera = 12;
            }
            else if(i%12==1)
            {
                aftera = 13;
            }
            else
            {
                numa = i/12;
                aftera = i -numa*12;
            }
            p[i]=p[i-1]+b[aftera-1];
            //cout<<"i= "<<i<<"  p[i]:   "<<p[i]<<"    p[i-1]:    "<<p[i-1]<<"    b[aftera-1]:    "<<b[aftera-1]<<endl;
            saveday[i] = p[i];
        }
        else
        {
            //nonleap
            if(i%12==0)
            {
                aftera = 12;
            }
            else if(i%12==1)
            {
                aftera = 13;
            }
            else
            {
                numa = i/12;
                aftera = i -numa*12;
            }
            p[i]=p[i-1]+a[aftera-1];
            //cout<<"i= "<<i<<"  p[i]:   "<<p[i]<<"    p[i-1]:    "<<p[i-1]<<"    a[aftera-1]:    "<<a[aftera-1]<<endl;
            saveday[i] = p[i];
        }
        if( p[i]+a[aftera-1]>=allday || p[i]+b[aftera-1]>=allday )
            {
            //    cout<<"how many 13th in those years"<<i<<endl;
                sum=i;
                makesureweek();
                printtheresult();
                return 0;
            }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
