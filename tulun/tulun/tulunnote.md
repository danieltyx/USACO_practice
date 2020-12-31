# Defination
图论：点和线算法
## 图：{e,v} 权（点权+边权）
   有向和无向
       无向图是双向有向图
## 树：root 没有两个点有两个节
   都是无向图
   满树：N =》n-1
    二叉树
   满二叉树：每个字节点带两个字节点（除了叶）
   完全二叉树：满的，层树一样
   树的遍历
       A
     B   C
   D   E   F
       先（根左右）ABDECF
       中（左根右）DBEACF
       后（左右根）DEBFCA



## 图的存储
### 临接矩阵
        二维 int mp[2000][2000]
        mp[x][y]=0;
        x-->y
        优点✅：两点之间一条边
        缺点❌： 大量无效数据
                时间至少n**2
### 链式前向星
        head【  |  |  |  |  |  |  】
         下标     1  2  3  4  5  6...n 节点
           Next  | to |  v
           ei=n
        有向图：O（m）
        无向： O（2m）
 
```
struct edge
{
    int next,to,v;
};

edge e[maxm*2];
int ei = 0;
h[maxm];

void add(int x,int y,int v)
{
    ei++;
    e[ei].to = y;
    e[ei].v = v;
    e[ei].next = h[x];
    h[x] = ei;
}

//find
for(int i = h[x]; i!=0; i=e[i].next)
{
    int to = e[i].to;
    v= e[i].v;
}
```
        优点✅：时间空间优秀
        缺点❌： 删除不了
        重边 一般不考虑

### LR列表
    L= [ \2 \4 \ \ ]
    R= [ \3 \5 \ \ ]
          1  2  
# 图算法
### 最短路
spfa 广搜最短路/最长

x1 x2 x3
    y
dis[to] = min(dis[x1] + E1, dis[x1] + E2, dis[x3] + E3)

```
int dis[maxm]
int u[maxn] //是否在搜索池
void spfa(int f) //int f 开始 单源最短路
{
    queue<int> qu;
    memset(dis,0x3f,sizeof(dis));
    dis[f] = 0;
    qu.push(f)
    u[f] = 1;
    while(!qu.empty())
    {
        int f1 = qu.front()
        qu.pop()
        u[f1] = 0;
        for(int i = h[f1];i;i=e[i].next)
        {
            int to = e[i].to;
            if(dis[to]> disp[f1] + e[i].v)
            {
                dis[to] = disp[f1] + e[i].v;
                if(u[to]==0)
                {
                    u[to] = 1;
                    qu.push(to)
                }
            }
        }
    }
    if(dis[t] == 0x3f3f3f3f)
    {
        none
    }
}
//自学 floyed + 二维数组
```

dijskra m(longn)正权 + 堆优化
spfa m(longn) : lim-> m**2




dijstria  
堆优化logn

优点：恒定：O（nlongm）
缺点：负边
