struct nd
{
    int id,dis;
    bool operator<(const nd&x) const// 只用更改 nd类型 e 和x
    {
        return dis>x.dis;
    }
    
};
int MAXM = 999;
nd hp[MAXM];
int u[MAXM];
void dij(int s)
{
    pushHeap(s,0);
    dis[s] = 0;
    u[s] = 1;
    while(hplen)
    {
        nd p = popHeap();
        int id = p.id;
        int ppp = p.dis;
        if(u[id]==1)continue;
        u[id] = 1;
        dis[id] = ppp;
        for(int i=h[id];i;i=e[i].next)
        {
            int to = e[i].to;
            if(u[to]==1)continue;
            push(to,dis[id])
            
        }
    }
}
int hplen = 0;
void pushHeap(int id, int dis)
{
    hplen++;
    hp[hplen].id = id;
    hp[hplen].dis = dis;
    push_heap(hp+1,hp+1+hplen);
}
nd pop_heap()
{
    pop_heap(hp+1,hp+1+hplen);
    hplen--;
    return hp[hplen+1];
}
