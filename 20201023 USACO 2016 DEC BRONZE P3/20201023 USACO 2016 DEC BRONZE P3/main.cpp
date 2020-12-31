#include"bits/stdc++.h"
using namespace std;
int mp[100][100];
int nmp[1000][1000];
int main()
{
    freopen("cowsignal.in","r",stdin);
    freopen("cowsignal.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        char tempa[] = "12345678900";
        strncpy(tempa, a.c_str(), a.length() + 1);
        for(int j = 0; j < m;j++)
        {
            if(tempa[j] == 'X') mp[i][j+1] = 0;
            else mp[i][j+1] = 1;
        }
    }
    int x = 1;
    int y = 1;
    for(int i = 1; i<=n ;i++)
    {
        for(int j = 1; j<= m; j++)
        {
            for(int p = 0; p < k ; p++)
            {
                for(int q = 0; q < k; q++)
                {
                    nmp[x + p][y + q] = mp[i][j];
                }
            }
            
            y += k;
        }
        y = 1;
        x += k;
    }
    for(int i = 1;i <= k * n; i++)
    {
        for(int j = 1;j <= k * m; j++)
        {
            if(nmp[i][j] == 0)
            {
                cout<<"X";
            }
            else
            {
                cout<<".";
            }
        }
        puts("");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
