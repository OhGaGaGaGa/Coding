#include<bits/stdc++.h>
#define pii pair<int,int>
#define maxn 100010
using namespace std;
int n,m;
struct node{
	int nxt,to,val;
}e[maxn];
int head[maxn],cntt=0;
void add_edge(int u,int v,int w){
	e[++cntt].to=v;
	e[cntt].val=w;
	e[cntt].nxt=head[u];
	head[u]=cntt;
}
bool vis[maxn];long long tot=0;
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
void prim(){
	//static int dis[maxn];
	//memset(vis,0,sizeof(vis));
	//memset(dis,0x3f,sizeof(dis));
//	pq.push(make_pair(0,1));
	vis[1]=1;//dis[1]=0;
	for(int i=head[1]; i>=0; i=e[i].nxt) {
		pq.push(make_pair(e[i].val,e[i].to));
	}
	for(int k=1;k<n;k++){
		while(vis[pq.top().second]) pq.pop();
		pair<int,int> tmp=pq.top();
		vis[tmp.second]=1;
		tot+=(long long)tmp.first;
		for(int i=head[tmp.second];i!=-1;i=e[i].nxt)//{
			//int to=e[i].to;
			//if(dis[to]>e[i].val){
			//	dis[to]=e[i].val;
			//	if(!vis[to])
				pq.push(make_pair(e[i].val,e[i].to));
			//}
		//}
	}
/*	for(int i=1;i<=n;i++)
		tot+=dis[i];
*/	cout<<tot<<endl;
}

int main(){
	memset(head,-1,sizeof(head));
	memset(vis,false,sizeof(vis));
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,add_edge(u,v,w),add_edge(v,u,w);
	prim();
	return 0;
}
