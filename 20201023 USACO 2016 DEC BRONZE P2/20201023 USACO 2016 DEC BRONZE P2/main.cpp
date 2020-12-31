#include"bits/stdc++.h"
using namespace std;
string a[1000];
string b[1000];
int cnta[200];
int cntb[200];
int cnt[200];
int main()
{
    freopen("blocks.in","r",stdin);
    freopen("blocks.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n; i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i = 1;i <= n; i++)
    {
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        char tempa[] = "12345678900";
        char tempb[] = "12345678900";
        strncpy(tempa, a[i].c_str(), a[i].length() + 1);
        strncpy(tempb, b[i].c_str(), b[i].length() + 1);
        for(int j = 0;j < a[i].length(); j++)
        {
            cnta[(int)tempa[j]]++;
        }
        for(int j = 0;j < b[i].length(); j++)
        {
            cntb[(int)tempb[j]]++;
        }
        for(int j = 97;j <= 122;j++)
        {
            cnt[j] += max(cnta[j], cntb[j]);
        }
    }
    for(int i = 97;i <= 122;i++)
    {
        cout<<cnt[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
