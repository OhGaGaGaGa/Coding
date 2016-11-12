//codevs 2370
#include<bits/stdc++.h>
#define D(x) cerr<<#x<<"="<<x<<" "
#define E(x) cerr<<endl
using namespace std;
struct node{
	int dis,to,next;
}e[100010];
int POW,head[100010],cnt=0,d[100010],c[100010],lca[50009][20];
void add_edge(int u,int v,int w){
	e[++cnt].dis=w;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool vis[100010];
void dfs(int x,int cos){
	c[x]=cos;
	for(int i=1;i<=POW;i++){
		if(d[x]>=(1<<i))
			lca[x][i]=lca[lca[x][i-1]][i-1];
	}//倍增的思想 因为f[x][i-1]已经在前面处理过了 所以此时就可以直接用

	/*for(int i=1;i<=POW;i++)
		lca[x][i]=lca[lca[x][i-1]][i-1];*/
	for(int i=head[x];i!=-1;i=e[i].next){
		if(!vis[e[i].to])
			lca[e[i].to][0]=x,
			d[e[i].to]=d[x]+1,
			vis[e[i].to]=true,
			dfs(e[i].to,cos+e[i].dis);
	}
}
int LCA(int a,int b){//a在上 b在下 
	if(d[a]>d[b])a^=b,b^=a,a^=b;
	if(d[a]<d[b]){
		int del=d[b]-d[a];
		for(int i=0;i<=POW;i++)
			if(del&(1<<i))b=lca[b][i];
	}
	if(a!=b){
		for(int i=POW;i>=0;i--)
			if(lca[a][i]!=lca[b][i])a=lca[a][i],b=lca[b][i];
		a=lca[a][0];
	}
	return a;
}
int main(){
	memset(head,-1,sizeof(head));
	int n,m;
	cin>>n;
	for(int i=1,u,v,w;i<=n-1;i++)
		cin>>u>>v>>w,add_edge(v,u,w),add_edge(u,v,w);
	
	POW=17;//log10(n)/log10(2)+1;
	vis[0]=1;
	dfs(0,0);
	cin>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		//D(c[u]);D(c[v]);D(c[LCA(u,v)]);D(LCA(u,v));
		cout<<c[u]+c[v]-2*c[LCA(u,v)]<<endl;
	}
		
}
/*
3
1 0 1
2 0 1
3
1 0
2 0
1 2

cout<<1<<1<<2;
c[u]=3 c[v]=2 c[LCA(u,v)]=2 LCA(u,v)=0 1
c[u]=1 c[v]=2 c[LCA(u,v)]=1 LCA(u,v)=2 1
c[u]=3 c[v]=1 c[LCA(u,v)]=1 LCA(u,v)=2 2
*/ 
/*
10
0 1 570
0 2 632
0 3 229
1 4 998
4 5 565
2 6 956
3 7 21
4 8 127
0 9 727
10
9 1
4 7
8 2
4 3
5 1
0 4
0 3
7 6
2 3
4 6

> 1297> 1818> 
2327(c[u]=3149 c[v]=2086 c[LCA(u,v)]=727 LCA(u,v)=9 3781)
> 1797>
 1563>(c[u]=3587 c[v]=2024 c[LCA(u,v)]=727 LCA(u,v)=9 4157)
  1568> 229> 1838> 861> 3156
*/
