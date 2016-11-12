#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
#define pii pair<int,int>

struct node{
	int nxt,to,val;
}e[maxn];
int head[maxn],cntt=0;
void add_edge(int u,int v,int w){
	e[++cntt].nxt=head[u];
	e[cntt].to=v;
	e[cntt].val=w;
	head[u]=cntt;
}

void spfa(){
	queue<int> q;
	static bool vis[maxn];
	static int dis[maxn];
	q.push(1);
	vis[1]=1;dis[1]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=e[i].nxt){
			int to=e[i].to;
			if(dis[to]>dis[x]+e[i].val){
				dis[to]=dis[x]+e[i].val;
				if(!vis[to]){
					vis[to]=1;
					q.push(to);
				}
			}
		} 
		vis[x]=0;
	}
}

void dij(){
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	static bool vis[maxn];
	static int dis[maxn];
	memset(dis,0x3f,sizeof(dis));
	pq.push(make_pair(0,1));
	vis[1]=1;dis[1]=0;
	while(!pq.empty()){
		int num=pq.top().second;
		pq.pop();
		if(vis[num])continue;
		vis[num]=1;
		for(int i=head[num];i!=-1;i=e[i].nxt){
			int to=e[i].to;
			if(dis[to]>dis[num]+e[i].val&&!vis[to]){
				dis[to]=dis[num]+e[i].val;
				pq.push(make_pair(dis[to],to));
			}
		}
	}
}
void floyd(){
	//memset(a,0x3f,sizeof(f));
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[i][k]&&a[k][j]) 
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}
void prim(){
	static bool vis[maxn];
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	vis[1]=1;
	for(int i=head[1]; i!=-1; i=e[i].nxt)
		pq.push(make_pair(e[i].val,e[i].to));
	for(int k=1;k<n;k++){
		while(vis[pq.top().second]) pq.pop();
		pair<int,int> tmp=pq.top();
		vis[tmp.second]=1;
		for(int i=head[tmp.second];i!=-1;i=e[i].nxt)
			pq.push(make_pair(e[i].val,e[i].to));
	}
} 
int main(){
	
	return 0;
}
