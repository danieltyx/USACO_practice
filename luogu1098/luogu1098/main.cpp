#include"bits/stdc++.h"
#include"string.h"
using namespace std;
vector<int> vc;
string a;
int main()
{
    int n,m,q;//n: upper/lower letter ;m times; q order
    int dif;
    cin>>n>>m>>q;
    cin>>a;
    int al = a.length();
    for(int i=0;i<al;i++)
    {
        if(a.at(i)=='-')
        {
            vc.push_back(1);
        }
        else
        {
            vc.push_back(0);
        }
    }
    
    //cout<<vclength<<endl;
    //vc.at(0);
    //cout<<vc.at(vclength-1);
    for(int i=1;i<vc.size()-1;i++)
    {
        int nows = vc.at(i);
        if(nows == 1)
        {
            string x,y;
            x = a.at(i-1);
            y = a.at(i+1);
            if(x.at(0)=='-'||y.at(0)=='-')continue;
            if(x>=y)continue;
            if(x.at(0)>='0'&&x.at(0)<='9'&&y.at(0)>'9')continue;
            a.erase(i,1);
            dif = int(y.at(0))-int(x.at(0));
            if(dif==1)
            {
                vc.erase(vc.begin()+i);
                continue;
            }
            if(q==1)
            {
                for(int j=dif-1;j>=1;j--)
                {
                    string z;
                    z = x;
                    int tempz = int(z.at(0));
                    tempz = tempz+j;
                    if(n==1)
                    {
                        if(tempz>=65&&tempz<=90)
                        {
                            tempz+=32;
                        }
                    }
                    else if(n==2)
                    {
                        if(tempz>=97 && tempz<=122)
                        {
                            tempz-=32;
                        }
                    }
                    else if(n==3)
                    {
                        tempz = 42;
                    }
                    z = char(tempz);
                    for(int k=1;k<=m;k++)
                    {
                       a.insert(i,z);
                    }
                    //cout<<a<<endl;
                }
                vc.insert(vc.begin()+i+1,(dif-1)*m-1,0);
            }
            else
            {
                for(int j=1;j<=dif-1;j++)
                    {
                        string z;
                        z = x;
                        int tempz = int(z.at(0));
                        tempz = tempz+j;
                        if(n==1)
                        {
                            if(tempz>=65&&tempz<=90)
                            {
                                tempz+=32;
                            }
                        }
                        else if(n==2)
                        {
                            if(tempz>=97 && tempz<=122)
                            {
                                tempz-=32;
                            }
                        }
                        else if(n==3)
                        {
                            tempz = 42;
                        }
                        z = char(tempz);
                        for(int k=1;k<=m;k++)
                        {
                           a.insert(i,z);
                        }
                        //cout<<a<<endl;
                    }
                    vc.insert(vc.begin()+i+1,(dif-1)*m-1,0);
                }
            }
        }
    cout<<a<<endl;
    return 0;
}
