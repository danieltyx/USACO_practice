#include"bits/stdc++.h"
using namespace std;
int epoint[100100];
int tpoint[100100];
int elose[100100];
int tlose[100100];
int main()
{
    char k;
    int ecnt=1;
    int tcnt=1;
    while(true)
    {
        cin>>k;
        if(k=='E')break;
        if(k=='W')
        {
            epoint[ecnt]++;
            tpoint[tcnt]++;
        }
        else
        {
            elose[ecnt]++;
            tlose[tcnt]++;
        }
        
        if((epoint[ecnt] >= 11 || elose[ecnt] >=11)
           &&
           abs(epoint[ecnt]-elose[ecnt])>=2 )
        {
            ecnt++;
        }
        if((tpoint[tcnt] >= 21 || tlose[tcnt] >=21)
           &&
           abs(tpoint[tcnt]-tlose[tcnt])>=2 )
        {
            tcnt++;
        }
    }
    for(int i=1;i<ecnt;i++)
    {
        cout<<epoint[i]<<":"<<elose[i]<<endl;
    }
    cout<<epoint[ecnt]<<":"<< elose[ecnt]<<endl;
    puts("");
    for(int i=1;i<tcnt;i++)
    {
        cout<<tpoint[i]<<":"<<tlose[i]<<endl;
    }
    cout<<tpoint[tcnt]<<":"<< tlose[tcnt]<<endl;
    return 0;
}
