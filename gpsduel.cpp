#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node {
	int to,next,v1,v2;
} e[1000010],ed[1000010];
int cnt1=0,head[1000010];
void add_edge(int u,int v,int w1,int w2) {
	cnt1++;
	e[cnt1].to=v;
	e[cnt1].v1=w1;
	e[cnt1].v2=w2;
	e[cnt1].next=head[u];
	head[u]=cnt1;
}
int pre1[1000010],pre2[1000010];
vector<int> path1,path2;
void make_path_1(int x){
	path1.push_back(x);
	if(pre1[x]!=-1)make_path_1(pre1[x]);
}
void make_path_2(int x){
	path2.push_back(x);
	if(pre2[x]!=-1)make_path_2(pre2[x]);
}
void spfa1(int s) {
	static bool vis[100010];
	static int dis[100010];
	memset(pre1,-1,sizeof(pre1));
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(int i=head1[x]; i!=-1; i=e1[i].next) {
			if(dis[e1[i].to]>dis[x]+e1[i].val) {
				dis[e1[i].to]=dis[x]+e1[i].val;
				pre1[e1[i].to]=x;
				if(!vis[e1[i].to]) {
					q.push(e1[i].to);
					vis[e1[i].to]=1;
				}
			}
		}
		vis[x]=0;
	}
	make_path_1();
}
void spfa2(int s) {
	static bool vis[100010];
	static int dis[100010];
	memset(pre2,-1,sizeof(pre2));
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(int i=head2[x]; i!=-1; i=e2[i].next) {
			if(dis[e2[i].to]>dis[x]+e2[i].val) {
				dis[e2[i].to]=dis[x]+e2[i].val;
				pre2[e2[i].to]=x;
				if(!vis[e2[i].to]) {
					q.push(e2[i].to);
					vis[e2[i].to]=1;
				}
			}
		}
		vis[x]=0;
	}
	make_path_2();
}
int ans=99999999;
void dfs(int s){
	if(){
		return ;
	}
	spfa1(s);spfa2(s);
	for(int i=path1.size()-1;i>=0;i--){
		if(path1[i]==path2[i])dfs(path1[i]);
	}
}
int main() {
	//freopen("gpsduel.in","r",stdin);
	//freopen("gpsduel.out","w",stdout);
	int n,k;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&k);
	for(int i=1,x,y,v1,v2;i<=k; i++) {
		scanf("%d%d%d%d",&x,&y,&v1,&v2);
		add_edge(x,y,v1);
		add_edge(x,y,v2);
	}
	spfa1(s);spfa2()
	printf("%d\n",ans);
}
