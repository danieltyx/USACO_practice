#include"bits/stdc++.h"
using namespace std;
int g[5] = {0,1,3,7,9};
 int n,m;
bool checkprime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
void makeh()
{
    int a;
    for(int i=1;i<=4;i++)
    {
        a=g[i];
        if(checkprime(a)==true && a>=n&&a<=m)
        {
            printf("%d\n",a);
        }
    }
    for(int i=1;i<=4;i++)
    {

        a=g[i]+10*g[i];
    if(checkprime(a)==true && a>=n&&a<=m)
    {
        printf("%d\n",a);
    }
        
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<=9;j++)
        {
            a = g[i]+j*10+g[i]*100;
            if(checkprime(a)==true&& a>=n&&a<=m)
            {
                printf("%d\n",a);
            }
        }
    }
    
    
    
    
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                a=g[i]+j*10+k*100+
                j*1000+g[i]*10000;
                if(checkprime(a)==true&& a>=n&&a<=m)
                {
                    printf("%d\n",a);
                }
            }
            
        }
        
    }

    
for(int i=1;i<=4;i++)
{
   for(int j=0;j<=9;j++)
   {
       for(int k=0;k<=9;k++)
       {
           for(int l=0;l<=9;l++)
           {
                a=g[i]+j*10+k*100+l*1000+k*10000+j*100000+g[i]*1000000;
               if(checkprime(a)==true&& a>=n&&a<=m)
               {
                   printf("%d\n",a);
               }
           }
       }
   }
}
}
  

int main()
{
    cin>>n>>m;
    if(n<=5)
    {
        cout<<5<<endl;
    }
    makeh();
    return 0;
}
