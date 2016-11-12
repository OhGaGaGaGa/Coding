//codevs 3287
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int to,dis,next;
}e[50009*2*2];
struct node{
	int from,to,dis;
}a[50010*2];
int d[10009*2],c[10010*2],lca[10009*2][20],POW=16,cntt=0;
bool vis[100010*2];
int head[10009*2],n,m,Q,ans,fa[2*10010],the_end;
void add_edge(int u,int v, int w){
	e[++cntt].to=v;
	e[cntt].dis=w;
	e[cntt].next=head[u];
	head[u]=cntt;
}

bool cmp(node a,node b){return a.dis>b.dis;}
int find(int x){
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int a,int b){
	int fa_=find(a),fb_=find(b);
	if(fa_!=fb_)fa[fa_]=fb_;
}
void kruskal(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int k=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].from)!=find(a[i].to)){
			unionn(a[i].from,a[i].to); 
			k++;
			add_edge(a[i].from,a[i].to,a[i].dis);
			add_edge(a[i].to,a[i].from,a[i].dis); 
		}
		if(k==n-1)break;
	}
}
void dfs(int x){//c[x]=cos;
	for(int i=1;i<=POW;i++){
		if(d[x]>=(1<<i))
			lca[x][i]=lca[lca[x][i-1]][i-1];
	}
	for(int i=head[x];i!=-1;i=e[i].next){
		if(!vis[e[i].to])
			lca[e[i].to][0]=x,
			d[e[i].to]=d[x]+1,
			vis[e[i].to]=true,
			dfs(e[i].to);
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
int find_path(int s){
	if(s==the_end)exit(1);
	for(int i=head[s];i!=-1;i=e[i].next){
		ans=min(ans,e[i].dis);
		find_path(e[i].to);
	}
	return 0;
}
int main(){
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].dis);
	kruskal();
	vis[fa[1]]=1;
	dfs(fa[1]);
	cin>>Q;
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=0x7f7f7f7f;
		the_end=LCA(x,y);
		if(find_path(x)&&find_path(y))printf("%d\n",ans);
		else  printf("-1\n");
		
	}
}
