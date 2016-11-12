#include<bits/stdc++.h>
using namespace std;
const int bin=17;
int fa[60010][20];//f[i][j]表示i号节点的2^j的父亲?
int sum[60010][20];//sum[i][j]表示i号节点到2^j的父亲的路径长度?
bool vis[60010];//判断重复边?
int deep[60010];//记录深度?
int n,m;
int k=0;
int head[60010];
struct node{
int to,next,val;
}e[600010];
void add(int u,int v,int w)
{
k++;
e[k].to=v;
e[k].next=head[u];
e[k].val=w;
head[u]=k;
}//伪链表存树（链表也可以,根据个人喜好...）?
void dfs(int x)//预处理f和sum数组?
{
vis[x]=true;//记录该节点走过?
for(int i=1;i<=bin;i++)
{
if(deep[x]>=(1<<i))
{
fa[x][i]=fa[fa[x][i-1]][i-1];
sum[x][i]=sum[fa[x][i-1]][i-1]+sum[x][i-1];
}//倍增的思想 因为f[x][i-1]已经在前面处理过了 所以此时就可以直接用?
}
for(int i=head[x];i;i=e[i].next)
 {
if(!vis[e[i].to])//相邻的父亲的处理?
{
sum[e[i].to][0]=e[i].val;
fa[e[i].to][0]=x;
deep[e[i].to]=deep[x]+1;
dfs(e[i].to);
} 
}
}
int lca(int x,int y)//查找最近公共祖先?
{
if(deep[x]-deep[y]<0) swap(x,y);
int t1=deep[x]-deep[y]; 
for(int i=0;i<=bin;i++)
 if((t1&(1<<i))>0) x=fa[x][i];//调整高度 ? ??
if(x==y) return x; //如果x y存在父子关系就输出 ? ? ? ? ? ? ? ? ? ? ?
for(int i=bin;i>=0;i--)
 if(fa[x][i]!=fa[y][i]){
x=fa[x][i];
y=fa[y][i]; 
}//找最近公共祖先 因为此时找的是与最近公共祖先最接近的两个节点 所以找完之后输出fa[x][0] ? ? ? ? ? ? ? ?
return fa[x][0];}
int ask_date(int x,int f)
{
int s=0;
int t=deep[x]-deep[f];
for(int i=0;i<=bin;i++)
if((t&(1<<i))>0)
{
s+=sum[x][i];
x=fa[x][i];//要跳到2^i的父亲上，不然会计算错误?
}//计算x节点到最近公共祖先的距离?
return s;
}
void read()
{
memset(vis,false,sizeof(vis));
memset(deep,0,sizeof(deep));
scanf("%d",&n);
int x,y,z;
for(int i=1;i<n;i++)
{
 scanf("%d%d%d",&x,&y,&z);
 add(x,y,z);
 add(y,x,z);
}
for(int i=0;i<n;i++)
 if(!vis[i]) dfs(i);
int a,b;
scanf("%d",&m);
for(int i=1;i<=m;i++)
{
 scanf("%d%d",&a,&b);
 int f=lca(a,b);
 int ans=ask_date(a,f)+ask_date(b,f);//两个节点距离相加即可?
 printf("%d\n",ans);
}
}
int main()
{
freopen("lcastd.in","r",stdin);
freopen("lcastd.out","w",stdout);
read();
return 0;
}
