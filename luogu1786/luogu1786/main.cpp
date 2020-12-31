#define MAXN 1000000000
#define absolutemaxn 2147483647
#include"bits/stdc++.h"
using namespace std;
string name[10010];
string tit[10010];
int pt[10010];
int expe[10010];
int lev[10010];
int orderr[10010];
int main()
{
    //freopen("luogu1786.in","r",stdin);
    //freopen("luogu1786.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>name[i]>>tit[i]>>expe[i]>>lev[i];
        orderr[i] = i;
        if(tit[i]=="BangZhu")
        {
            pt[i] = 0;
            expe[i] = absolutemaxn;
        }
        else if(tit[i] == "FuBangZhu")
        {
            pt[i] = 1;
            expe[i] = MAXN-1;
        }
        else if(tit[i] == "HuFa")
        {
            pt[i] =2;
        }
        else if(tit[i] == "ZhangLao")
        {
            pt[i] =3;
        }
        else if(tit[i] == "TangZhu")
        {
            pt[i] =4;
        }
        else if(tit[i] == "JingYing")
        {
            pt[i]=5;
        }
        else if(tit[i] =="BangZhong")
        {
            pt[i]=6;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(expe[j] < expe[j+1])
            {
                swap(expe[j],expe[j+1]);
                swap(name[j],name[j+1]);
                swap(pt[j],pt[j+1]);
                swap(lev[j],lev[j+1]);
                swap(tit[j],tit[j+1]);
            }
            else if(expe[j]==expe[j+1])
            {
                if(pt[j]>pt[j+1])
                {
                    swap(expe[j],expe[j+1]);
                    swap(name[j],name[j+1]);
                    swap(pt[j],pt[j+1]);
                    swap(lev[j],lev[j+1]);
                    swap(tit[j],tit[j+1]);
                }
                else if(pt[j]==pt[j+1])
                {
                    if(orderr[j]>=orderr[j+1])
                    {
                        swap(expe[j],expe[j+1]);
                       swap(name[j],name[j+1]);
                       swap(pt[j],pt[j+1]);
                       swap(lev[j],lev[j+1]);
                       swap(tit[j],tit[j+1]);
                    }
                }
            }
            
        }
    }
   /* int numhf=2;
    int numzl=4;
    int numtz=7;
    int numjy=25;*/
    for(int i=4;i<=5;i++)
    {
        tit[i]  = "HuFa";
        //pt[i] = 2;
    }
    for(int i=6;i<=9;i++)
    {
        tit[i] = "ZhangLao";
        //pt[i] = 3;
    }
    for(int i=10;i<=16;i++)
    {
        tit[i] = "TangZhu";
        //pt[i] = 4;
    }
    for(int i=17;i<=41;i++)
    {
        tit[i] = "JingYing";
        //pt[i] = 5;
    }
    for(int i=42;i<=n;i++)
    {
        tit[i] = "BangZhong";
        //pt[i]=6;
    }
    for(int i=1;i<=2;i++)
    {
        for(int j=4;j<5;j++)
        {
            if(lev[j]<lev[j+1])
            {
                swap(expe[j],expe[j+1]);
                swap(name[j],name[j+1]);
                swap(pt[j],pt[j+1]);
                swap(lev[j],lev[j+1]);
                swap(tit[j],tit[j+1]);
            }
            if(lev[j]==lev[j+1])
            {
                if(pt[j]>pt[j+1])
                {
                    swap(expe[j],expe[j+1]);
                    swap(name[j],name[j+1]);
                    swap(pt[j],pt[j+1]);
                    swap(lev[j],lev[j+1]);
                    swap(tit[j],tit[j+1]);
                }
                else if(pt[j]==pt[j+1])
                {
                    if(orderr[j]>=orderr[j+1])
                    {
                        swap(expe[j],expe[j+1]);
                       swap(name[j],name[j+1]);
                       swap(pt[j],pt[j+1]);
                       swap(lev[j],lev[j+1]);
                       swap(tit[j],tit[j+1]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=6;j<9;j++)
        {
            if(lev[j]<lev[j+1])
            {
                swap(expe[j],expe[j+1]);
                swap(name[j],name[j+1]);
                swap(pt[j],pt[j+1]);
                swap(lev[j],lev[j+1]);
                swap(tit[j],tit[j+1]);
            }
            if(lev[j]==lev[j+1])
            {
                if(pt[j]>pt[j+1])
                {
                    swap(expe[j],expe[j+1]);
                    swap(name[j],name[j+1]);
                    swap(pt[j],pt[j+1]);
                    swap(lev[j],lev[j+1]);
                    swap(tit[j],tit[j+1]);
                }
                else if(pt[j]==pt[j+1])
                {
                    if(orderr[j]>=orderr[j+1])
                    {
                        swap(expe[j],expe[j+1]);
                       swap(name[j],name[j+1]);
                       swap(pt[j],pt[j+1]);
                       swap(lev[j],lev[j+1]);
                       swap(tit[j],tit[j+1]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=7;i++)
    {
        for(int j=10;j<16;j++)
        {
            if(lev[j]<lev[j+1])
            {
                swap(expe[j],expe[j+1]);
                swap(name[j],name[j+1]);
                swap(pt[j],pt[j+1]);
                swap(lev[j],lev[j+1]);
                swap(tit[j],tit[j+1]);
            }
            if(lev[j]==lev[j+1])
            {
                if(pt[j]>pt[j+1])
                {
                    swap(expe[j],expe[j+1]);
                    swap(name[j],name[j+1]);
                    swap(pt[j],pt[j+1]);
                    swap(lev[j],lev[j+1]);
                    swap(tit[j],tit[j+1]);
                }
                else if(pt[j]==pt[j+1])
                {
                    if(orderr[j]>=orderr[j+1])
                    {
                        swap(expe[j],expe[j+1]);
                       swap(name[j],name[j+1]);
                       swap(pt[j],pt[j+1]);
                       swap(lev[j],lev[j+1]);
                       swap(tit[j],tit[j+1]);
                    }
                }
            }
            
        }
    }
    for(int i=1;i<=25;i++)
    {
        for(int j=17;j<41;j++)
        {
            if(lev[j]<lev[j+1])
            {
                swap(expe[j],expe[j+1]);
                swap(name[j],name[j+1]);
                swap(pt[j],pt[j+1]);
                swap(lev[j],lev[j+1]);
                swap(tit[j],tit[j+1]);
            }
            if(lev[j]==lev[j+1])
            {
                if(pt[j]>pt[j+1])
                {
                    swap(expe[j],expe[j+1]);
                    swap(name[j],name[j+1]);
                    swap(pt[j],pt[j+1]);
                    swap(lev[j],lev[j+1]);
                    swap(tit[j],tit[j+1]);
                }
                else if(pt[j]==pt[j+1])
                {
                    if(orderr[j]>=orderr[j+1])
                    {
                        swap(expe[j],expe[j+1]);
                       swap(name[j],name[j+1]);
                       swap(pt[j],pt[j+1]);
                       swap(lev[j],lev[j+1]);
                       swap(tit[j],tit[j+1]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n-41;i++)
    {
        for(int j=42;j<n;j++)
        {
            if(lev[j]<lev[j+1])
            {
                swap(expe[j],expe[j+1]);
                swap(name[j],name[j+1]);
                swap(pt[j],pt[j+1]);
                swap(lev[j],lev[j+1]);
                swap(tit[j],tit[j+1]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<name[i]<<" "<<tit[i]<<" "<<lev[i]<<endl;
    }
    return 0;
}
