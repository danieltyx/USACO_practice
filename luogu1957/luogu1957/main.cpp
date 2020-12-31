#include"bits/stdc++.h"
using namespace std;
int x[1001];
int y[1001];
int fh[1001];
int r[1001];// 1+ 2- 3*
int wx[1001];
int wy[1001];
int wr[1001];
string a;

int getwei(int k)
{
    if(k==0)return 1;
    int cnt=0;
    while(k!=0)
    {
        k/=10;
        cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a.at(0)=='a')
        {
            fh[i] = 1;
            scanf("%d%d",&x[i],&y[i]);
            wx[i]=getwei(x[i]);
            wy[i]=getwei(y[i]);
            r[i] = x[i]+y[i];
            wr[i]=getwei(r[i]);
        }
        else if(a.at(0)=='b')
        {
            fh[i] = 2;
            scanf("%d%d",&x[i],&y[i]);
            wx[i]=getwei(x[i]);
            wy[i]=getwei(y[i]);
            r[i]= x[i]-y[i];
            wr[i]=getwei(r[i]);
        }
        else if(a.at(0)=='c')
        {
            fh[i] = 3;
            scanf("%d%d",&x[i],&y[i]);
            wx[i]=getwei(x[i]);
            wy[i]=getwei(y[i]);
            r[i] =x[i]*y[i];
            wr[i]=getwei(r[i]);
        }
        else
        {
            int len= a.length();
            int numn=0;
            for(int j=len-1;j>=0;j--)
            {
                int k=(int)pow(10,len-j-1);
                numn += (a.at(j)-'0')* k;
            }
            x[i]=numn;
            scanf("%d",&y[i]);
            fh[i]=fh[i-1];
            if(fh[i]==1)r[i]=x[i]+y[i];
            else if(fh[i]==2)r[i]=x[i]-y[i];
            else if(fh[i]==3)r[i]=x[i]*y[i];
            wx[i]=len;
            wy[i]=getwei(y[i]);
            wr[i]=getwei(r[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<x[i];
        if(fh[i]==1)cout<<"+";
        else if(fh[i]==2)cout<<"-";
        else if(fh[i]==3)cout<<"*";
        cout<<y[i]<<"="<<r[i]<<endl;
        if(r[i]<0)
        {
             cout<<wx[i]+wy[i]+wr[i]+3<<endl;
        }
        else
        {
             cout<<wx[i]+wy[i]+wr[i]+2<<endl;
        }
    }
    return 0;
}


