#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int getint(){
	int a=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){a=a*10+c-'0';c=getchar();}
	return a*f;
}
int head[maxn],cntt=0;
struct node {
	int to,nxt;
} e[maxn];
void add_edge(int u,int v) {
	e[++cntt].to=v;
	e[cntt].nxt=head[u];
	head[u]=cntt;
}
int n,m,f[maxn];
bool flag[maxn];
int dfs(int x){
	if(f[x])return f[x];
	if(flag[x])return 0;
	flag[x]=1;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		f[x]=max(f[x],dfs(e[i].to));
	}
	return f[x]=max(f[x],x);
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	memset(head,-1,sizeof(head));
	memset(f,0,sizeof(f));
	n=getint(),m=getint();
	for(int x,y,i=1;i<=m;i++)
		x=getint(),y=getint(),add_edge(x,y);
	for(int i=1;i<=n;i++)
		if(!f[i]){
			memset(flag,0,sizeof(flag));
			dfs(i);
		}
	printf("%d",f[1]);
	for(int i=2;i<=n;i++)
		printf(" %d", f[i]);
	puts("");
	return 0;
}
