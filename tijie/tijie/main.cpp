#include<cstdio>
#include<iostream>
#include<cstring>
#define re register
using namespace std;
struct node{
    int next,from,to,z;
    double diss;
}w[200001];
struct node2{
    int next,to,z;
}w2[200001];
int o[80001],head[80001],cn,low[80001],dfn[80001],stack[80001],tail;
int i,n,m,head2[80001],up,h[80001],sz[80001],num,f[80001],cnt,head3;
inline int read(){
    int x=0,p=1; char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch == '-') p=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
    return x*p;
}
void tarjan(int x){
    num++;/*-*/o[x]=1;
    low[x]=dfn[x]=num;
    up++; stack[up]=x;
    for (re int j=head[x]; j; j=w[j].next){
        if (!dfn[w[j].to]){
            tarjan(w[j].to);
            low[x]=min(low[x],low[w[j].to]);
        }
        else
          if (o[w[j].to]){
              low[x]=min(low[x],dfn[w[j].to]);
          }
    }
    if (low[x]==dfn[x]){
        o[x]=0; cn++;
        h[x]=cn;
        while (stack[up]!=x){
            h[stack[up]]=cn;
            o[stack[up]]=0;
            up--;
        }
        up--;
    }
}
inline int spfa(int e){
    head3=0; tail=1;
    int team[80001],s[80001];
    memset(s,0,sizeof(s));
    team[head3]=e;
    o[e]=1;
    s[e]=sz[e];
    while (head3<tail){
        int k=team[head3];
        for (re int j=head2[k]; j; j=w2[j].next){
            if (s[w2[j].to]<s[k]+w2[j].z+sz[w2[j].to]){
                s[w2[j].to]=s[k]+w2[j].z+sz[w2[j].to];
               
                if (!o[w2[j].to]){
                    o[w2[j].to]=1; team[tail]=w2[j].to;
                    tail++;
                }
            }
        }
        head3++; o[k]=0;
    }
    e=0;
    for (i=1; i<=cn; i++)
        e=max(e,s[i]);
    return e;
}
int main(){
    n=read(); m=read();
    int x,y,z,e;
    for (i=1; i<=m; i++){
        x=read(); y=read(); z=read();
        scanf("%lf",&w[i].diss);
        w[i].to=y; w[i].from=x;
        w[i].next=head[x];
        head[x]=i; w[i].z=z;
    }
    e=read();
    for (i=1; i<=n; i++)
      if (!dfn[i]) tarjan(i);
    for (i=1; i<=m; i++){
        if (h[w[i].from]!=h[w[i].to]){
            w2[++cnt].to=h[w[i].to];
            w2[cnt].z=w[i].z;
            w2[cnt].next=head2[h[w[i].from]];
            head2[h[w[i].from]]=cnt;
        }
        else{                    
            int x=w[i].z;
            while(x){
                sz[h[w[i].to]]+=x;
                x=x*w[i].diss;
            }
        }
    }
    e=spfa(h[e]);
    printf("%d",e);
    return 0;
}
