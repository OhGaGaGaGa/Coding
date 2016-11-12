#include <iostream>
#include <cstring>
#include <stdio.h>
#include <set>
using namespace std;
const int maxn = 100010;
int n,m;
int getint() {
	int a=0,f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)) {a=a*10+c-'0';c=getchar();}
	return a*f;
}
int head[maxn],cntt;
struct node {
	int to,nxt;
} e[maxn << 1],e2[maxn << 1];
void add_edge(int u,int v) {
	e[++cntt].to=v;
	e[cntt].nxt=head[u];
	head[u]=cntt;
}
int head2[maxn];
void add_edge_2(int u,int v) {
	e2[++cntt].to=v;
	e2[cntt].nxt=head2[u];
	head2[u]=cntt;
}
set<int> se[maxn];
int dfn[maxn],low[maxn],top=0,timenum=0,stack[maxn],belong[maxn],num[maxn],qltnum=0;
void tarjan(int u){
	dfn[u]=low[u]=++timenum;
	stack[++top]=u;
	for(int i=head[u];i!=-1;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!belong[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		qltnum++;
		int v;
		do{
			v=stack[top--];
			belong[v]=qltnum;
			num[qltnum]++;
			se[qltnum].insert(v);
		}while(v!=u);
	}
}
bool have_dfs[maxn]={0};
void dfs(int x){
	for(int i=head2[x];i!=-1;i=e2[i].nxt)
		if(!have_dfs[e2[i].to])
			have_dfs[e2[i].to]=1,dfs(e2[i].to);
}
bool ru[maxn]={0};
int main(){
	memset(head,-1,sizeof(head));
	n=getint(),m=getint();
	for(int i=1,x,y;i<=m;i++)
		x=getint(),y=getint(),add_edge(x,y);
	for(int i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	int ans = 0;
	for(int i = 1; i <= qltnum; i++)
		if(num[i] > 1) ans++;
	printf("%d\n",ans);
	cntt=0;memset(head2,-1,sizeof(head2));
	for(int j=1;j<=n;j++)
		for(int i=head[j];i!=-1;i=e[i].nxt)
			if(belong[e[i].to]!=belong[j])
				add_edge_2(belong[e[i].to],belong[j]),ru[belong[j]]=1;
	if(cntt==1&&qltnum==2){puts("-1");return 0;}
	for(int i=1;i<=qltnum;i++)
		if(!ru[i]){
			memset(have_dfs,0,sizeof(have_dfs));
			have_dfs[i]=1;
			dfs(i);
			int j;
			for(j=1;j<=qltnum;j++)
				if(!have_dfs[j])break;
			if(j!=qltnum+1)continue;
			set<int>::iterator it=se[i].begin();
			printf("%d",*it);
			se[i].erase(*it);
			for(set<int>::iterator it=se[i].begin();it!=se[i].end();it++)
				printf(" %d",*it);
			puts("");
			return 0;
		}
	puts("-1");
	return 0;
}
