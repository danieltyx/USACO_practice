#include"bits/stdc++.h"
using namespace std;
int mk[100100];
int ca[100100];
int cb[100100];
int main()
{
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    int n;
    int pt = 0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        ca[i] = t;
        mk[t] = 1;
    }
    int cbcnt = 1;
    for(int i=1;i<=2*n;i++)
    {
        if(mk[i]==0)
        {
            cb[cbcnt] = i;
            cbcnt++;
        }
    }
    sort(ca,ca+n+1);
    sort(cb,cb+n+1);
    int a = 1;
    int b = 1;
    for(int i=1;i<=n;i++)
    {
        if(a>n || b>n) break;
        if(ca[a] < cb[b])
        {
            pt++;
            a++;
            b++;
        }
        else if(ca[a] > cb[b])
        {
            b++;
        }
    }
    cout<<pt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
