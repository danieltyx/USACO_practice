#include"bits/stdc++.h"
using namespace std;
const int MAXN = 100100;
int a[MAXN];
// H P S
// 1 2 3
// H>S  1>3
// S>P  3>2
// P>H  2>1

int fs_h[MAXN];
int fs_p[MAXN];
int fs_s[MAXN];

int bs_h[MAXN];
int bs_p[MAXN];
int bs_s[MAXN];

int main()
{
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char t;
        cin>>t;
        if(t=='H')a[i]=1;
        if(t=='P')a[i]=2;
        if(t=='S')a[i]=3;
    }
    if(a[1]==1)fs_h[1]=1;
    if(a[1]==2)fs_p[1]=1;
    if(a[1]==3)fs_s[1]=1;
    for(int i =2; i<=n ;i++)
    {
        if(a[i]==1) fs_h[i] = fs_h[i-1] + 1;
        else fs_h[i] = fs_h[i-1];
    }
    for(int i =2; i<=n ;i++)
    {
        if(a[i]==2) fs_p[i] = fs_p[i-1] + 1;
        else fs_p[i] = fs_p[i-1];
    }
    for(int i =2; i<=n ;i++)
    {
        if(a[i]==3) fs_s[i] = fs_s[i-1] + 1;
        else fs_s[i] = fs_s[i-1];
    }
    
    if(a[n]==1)bs_h[n]=1;
    if(a[n]==2)bs_p[n]=1;
    if(a[n]==3)bs_s[n]=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]==1) bs_h[i] = bs_h[i+1] + 1;
        else bs_h[i] = bs_h[i+1];
    }
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]==2) bs_p[i] = bs_p[i+1] + 1;
        else bs_p[i] = bs_p[i+1];
    }
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]==3) bs_s[i] = bs_s[i+1] + 1;
        else bs_s[i] = bs_s[i+1];
    }
    int ans = -1;
    for(int i=0;i<=n;i++)
    {
        int maxscore_a = max(fs_h[i],fs_p[i]);
        maxscore_a = max(maxscore_a,fs_s[i]);
        
        int maxscore_b = max(bs_h[i+1],bs_p[i+1]);
        maxscore_b = max(maxscore_b,bs_s[i+1]);
        
        ans = max(ans,maxscore_a+maxscore_b);
    }
    cout<<ans<<endl;
}
/*
 7
 S
 P
 H
 H
 P
 P
 S
 */
/*
 for(int i=1;i<=n;i++)cout<<fs_h[i];
 puts("");
 for(int i=1;i<=n;i++)cout<<fs_p[i];
 puts("");
 for(int i=1;i<=n;i++)cout<<fs_s[i];
 puts("");
 for(int i=1;i<=n;i++)cout<<bs_h[i];
 puts("");
 for(int i=1;i<=n;i++)cout<<bs_p[i];
 puts("");
 for(int i=1;i<=n;i++)cout<<bs_s[i];
 puts("");
 */
