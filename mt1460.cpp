#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define D(x) cerr<<#x<<"="<<x<<" "
long long ans=0,n,m,tot=0,fa[500010];
struct node{
	long long from,to,val;
}edge[500010];
int find(int x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);} 
inline bool cmp(const node a,const node b){	return a.val>b.val;}
void kruskal(){
	int cnt=0;
	sort(edge,edge+m*2,cmp);
	/*for(int i=0;i<m*2;i++){
		cout<<"i:"<<i<<" ";
		cout<<"edge:"<<edge[i].from<<" "<<edge[i].to<<" "<<edge[i].val<<" ";
		cout<<endl;
	}*/
	for(int i=0;i<m*2&&cnt<n;i++){
		int fx=find(edge[i].from),fy=find(edge[i].to);
		if(fx==fy)continue;
		fa[fx]=fy;ans+=edge[i].val;//unionn(fx,fy,edge[i].val);
		cnt++;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=0,from,to,val; i<m; i++){
		scanf("%d%d%d",&from,&to,&val);tot+=val;
		edge[(i<<1)].from=from;edge[(i<<1)].to=to;edge[(i<<1)].val=val;
		edge[(i<<1)+1].from=to;edge[(i<<1)+1].to=from;edge[(i<<1)+1].val=val;
	}
	/*for(int i=0;i<m*2;i++){
		cout<<"i:"<<i<<" ";
		cout<<"edge:"<<edge[i].from<<" "<<edge[i].to<<" "<<edge[i].val<<" ";
		cout<<endl;
	}*/
	//cout<<endl<<endl<<endl;
	kruskal();
	//cout<<endl<<endl;//debug(tot);debug(ans);
	printf("%d\n",tot-ans);
}
/*struct nod {
	int next,to,val;
} e[500010];
int head[500010],cntt=0;
void add_edge(int u,int v,int w) {
	e[++cntt].to=v;
	e[cntt].val=w;
	e[cntt].next=head[u];
	head[u]=cntt;
}
struct qnode{
	int dis,node;
	bool operator < (const qnode b) const
	{ return dis > b.dis; }
};
priority_queue<qnode> q;
bool vis[500010];
int d[500010];
void prim(int x) {
	qnode num;
	while(!q.empty()) {
		num=q.top();
		q.pop(); 
		if(vis[num.node])continue;
		int k=num.node;
		vis[k]=1;
		for(int i=head[k]; i!=-1; i=e[i].next) {
			if(d[e[i].to]<e[i].val&&!vis[e[i].to]) {
				vis[e[i].to]=1;
				q.push((qnode){d[e[i].to],e[i].to});
				d[e[i].to]=e[i].val;
			}
		}
	}
}*/
