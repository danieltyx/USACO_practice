//10ac 5 t
#include"bits/stdc++.h"
#define pp pair<int,int>
using namespace std;
vector<pp> vc;
map<pp,vector<pp> > mp;
int db[110][110];
int vn[110][110];
int hash_on[100100];
int hashcnt = 1;
int n,m;

void dfs(int x,int y)
{
    int button_size = mp[{x,y}].size();
    int x1,y1;
    for(int i=0;i<button_size;i++)
    {
        x1 = mp[{x,y}].at(i).first;
        y1 = mp[{x,y}].at(i).second;
        db[x1][y1] = 1;
    }
    if(x+1<=n)
    {
        if(db[x+1][y]==1)
        {
            vn[x+1][y]=1;
            dfs(x+1,y);
        }
    }
    if(y+1<=n)
    {
        if(db[x][y+1]==1)
        {
            vn[x][y+1]=1;
            dfs(x,y+1);
        }
    }
}
int rv(int k)
{
    for(int q = k+1 ;q<=hashcnt;q++)
    {
        int j = hash_on[q] % 101;
        int i = (hash_on[q] - j)/101;
        if(vn[i][j]==0 && db[i][j]==1)
        {
            if(i-1>0)
            {
                if(vn[i-1][j]==1)
                {
                    vn[i][j] = 1;
                    dfs(i,j);
                    return k;
                }
            }
            if(i+1<=n)
            {
                if(vn[i+1][j]==1)
                {
                    vn[i][j] = 1;
                    dfs(i,j);
                    return k;
                }
            }
            if(j-1>0)
            {
                if(vn[i][j-1]==1)
                {
                    vn[i][j] = 1;
                    dfs(i,j);
                    return k;
                }
            }
            if(j+1<=n)
            {
                if(vn[i][j+1]==1)
                {
                    vn[i][j] = 1;
                    dfs(i,j);
                    return k;
                }
            }
        }
    }
    return -1;
}
int main()
{
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        mp[{a,b}].push_back({c,d});
        hash_on[hashcnt++] = c * 101 + d;
    }
    vn[1][1] = 1;
    db[1][1] = 1;
    dfs(1,1);
    
    int finished = 1;
    while(finished!=-1)
    {
        finished = rv(finished);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(db[i][j]==1)ans++;
        }
    }
    cout<<ans<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=n;j++)
//            {
//                cout<<db[i][j]<<" ";
//            }
//            puts("");
//        }
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=n;j++)
//            {
//                cout<<vn[i][j]<<" ";
//            }
//            puts("");
//        }
//        puts("");

/*
4 6
1 1 1 2
1 2 1 3
1 3 2 1
2 1 1 4
1 4 2 2
2 2 2 4
*/

