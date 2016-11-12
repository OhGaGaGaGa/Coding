#include<bits/stdc++.h>
using namespace std;
const int bin=17;
int fa[60010][20];//f[i][j]��ʾi�Žڵ��2^j�ĸ���?
int sum[60010][20];//sum[i][j]��ʾi�Žڵ㵽2^j�ĸ��׵�·������?
bool vis[60010];//�ж��ظ���?
int deep[60010];//��¼���?
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
}//α�������������Ҳ����,���ݸ���ϲ��...��?
void dfs(int x)//Ԥ����f��sum����?
{
vis[x]=true;//��¼�ýڵ��߹�?
for(int i=1;i<=bin;i++)
{
if(deep[x]>=(1<<i))
{
fa[x][i]=fa[fa[x][i-1]][i-1];
sum[x][i]=sum[fa[x][i-1]][i-1]+sum[x][i-1];
}//������˼�� ��Ϊf[x][i-1]�Ѿ���ǰ�洦����� ���Դ�ʱ�Ϳ���ֱ����?
}
for(int i=head[x];i;i=e[i].next)
 {
if(!vis[e[i].to])//���ڵĸ��׵Ĵ���?
{
sum[e[i].to][0]=e[i].val;
fa[e[i].to][0]=x;
deep[e[i].to]=deep[x]+1;
dfs(e[i].to);
} 
}
}
int lca(int x,int y)//���������������?
{
if(deep[x]-deep[y]<0) swap(x,y);
int t1=deep[x]-deep[y]; 
for(int i=0;i<=bin;i++)
 if((t1&(1<<i))>0) x=fa[x][i];//�����߶� ? ??
if(x==y) return x; //���x y���ڸ��ӹ�ϵ����� ? ? ? ? ? ? ? ? ? ? ?
for(int i=bin;i>=0;i--)
 if(fa[x][i]!=fa[y][i]){
x=fa[x][i];
y=fa[y][i]; 
}//������������� ��Ϊ��ʱ�ҵ������������������ӽ��������ڵ� ��������֮�����fa[x][0] ? ? ? ? ? ? ? ?
return fa[x][0];}
int ask_date(int x,int f)
{
int s=0;
int t=deep[x]-deep[f];
for(int i=0;i<=bin;i++)
if((t&(1<<i))>0)
{
s+=sum[x][i];
x=fa[x][i];//Ҫ����2^i�ĸ����ϣ���Ȼ��������?
}//����x�ڵ㵽����������ȵľ���?
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
 int ans=ask_date(a,f)+ask_date(b,f);//�����ڵ������Ӽ���?
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
