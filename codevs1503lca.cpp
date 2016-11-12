#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;//codevs 1503
struct node{
	int next,to;
}e[2000050];
int POW=20,n,head[1000010],cntt=0,p[1000010][25],d[1000010];
void add_edge(int u,int v){
	e[++cntt].to=v;
	e[cntt].next=head[u];
	head[u]=cntt; 
}
bool vis[1000010];
void dfs(int s){
	for(int i=1;i<=POW;i++)
		if(d[s]>=(1<<i))
			p[s][i]=p[p[s][i-1]][i-1];
	for(int i=head[s];i!=-1;i=e[i].next){
		if(!vis[e[i].to]){
			vis[e[i].to]=true;
			d[e[i].to]=d[s]+1;
			p[e[i].to][0]=s;
			dfs(e[i].to);
		}
	}
}
int lca(int x,int y){
	if(d[x]>d[y])x^=y,y^=x,x^=y;//swap(a,b);////upper:x;lower:y;
	if(d[x]<d[y]){
		int del=d[y]-d[x];
		for(int i=0;i<=POW;i++)
			if(del&(1<<i))y=p[y][i];
	}
	if(x!=y){
		for(int i=POW;i>=0;i--){
			if(p[x][i]!=p[y][i])x=p[x][i],y=p[y][i];
		}
		x=p[x][0];
	}
	return x;
}
int main(){
	memset(head,-1,sizeof(head));
	cin>>n;
	//cout<<n<<endl;
	int a,b;
	for(int i=1;i<=n-1;i++){
		cin>>a>>b;//cnt+=2;//cout<<a<<b<<endl;
		add_edge(a,b),add_edge(b,a);
	} 
	//cout<<cnt;
	vis[1]=true;
	dfs(1);
	int old_ship_driver1,old_ship_driver2;
	cin>>old_ship_driver1>>old_ship_driver2;
	//cout<<old_ship_driver1<<" "<<old_ship_driver2<<endl;
	cout<<lca(old_ship_driver1,old_ship_driver2);
} 
