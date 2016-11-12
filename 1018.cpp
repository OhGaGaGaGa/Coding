/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
bool a[50][50];
int r,c;
struct name{
	int x,y;
};
bool vis[50][50]={0};
int x_to[]={1,1,1,0,0,-1,-1,-1},y_to[]={-1,0,1,-1,1,-1,0,1};
void bfs(int i,int j){
	queue<name> q;
	q.push((name){i,j});
	while(!q.empty()){
		name u=q.front();q.pop();
		for(int i=0;i<8;i++){
			int dx=u.x+x_to[i],dy=u.y+y_to[i];
			if(dx>=0&&dx<r&&dy>=0&&dy<c&&a[dx][dy]==1&&!vis[dx][dy])
				vis[dx][dy]=1,q.push((name){dx,dy});
		}
	}
}
int main(){
	char s[50];
	cin>>r>>c;
	for(int i=0;i<r;i++){
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;j++){
			if(s[j]=='.')a[i][j]=0;
			else a[i][j]=1;
		}
	}
	int cnt=0;
	for (int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			if(a[i][j]&&!vis[i][j])bfs(i,j),cnt++;
	printf("%d\n", cnt);
	return 0;
}

*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100000
int xx[8]= {0,0,1,1,1,-1,-1,-1},yy[8]= {1,-1,0,1,-1,0,1,-1};
int n,m,q[1005][1005],dad[maxn],cnt,ans,sum;
bool map[1005][1005];
struct node {
	int x,y,v;
} e[maxn];
bool cmp(node a,node b) {
	return a.v<b.v;
}
int getdad(int x) {
	return x==dad[x]?x:dad[x]=getdad(dad[x]);
}
bool input(int x1,int y1,int x2,int y2,int t) {
	if(x2<1||x2>n||y2<1||y2>m||!q[x2][y2])return 1;
	if(q[x1][y1]==q[x2][y2])return 0;
	cnt++;
	e[cnt].x=q[x1][y1];
	e[cnt].y=q[x2][y2];
	e[cnt].v=t-1;
	return 1;
}
void dfs(int x,int y) {
	q[x][y]=ans;
	for(int i=0; i<8; i++) {
		int x0=x+xx[i],y0=y+yy[i];
		if(map[x0][y0]&&!q[x0][y0])dfs(x0,y0);
	}
}
void build(int x,int y) {
	for(int i=x+1; i<=n; i++)
		if(!input(x,y,i,y,i-x)||!input(x,y,i,y+1,i-x)||!input(x,y,i,y-1,i-x))break;
	for(int i=x-1; i>0; i--)
		if(!input(x,y,i,y,x-i)||!input(x,y,i,y+1,x-i)||!input(x,y,i,y-1,x-i))break;
	for(int i=y+1; i<=m; i++)
		if(!input(x,y,x,i,i-y)||!input(x,y,x+1,i,i-y)||!input(x,y,x-1,i,i-y))break;
	for(int i=y-1; i>0; i--)
		if(!input(x,y,x,i,y-1)||!input(x,y,x+1,i,y-i)||!input(x,y,x-1,i,y-i))break;
}
void work1() {
	ans=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(map[i][j]&&!q[i][j]) {
				ans++;
				dfs(i,j);
			}
	cout<<ans<<endl;
}
void work2() {

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(map[i][j])build(i,j);
	sort(e+1,e+cnt+1,cmp);
	for(int i=1; i<=ans; i++)dad[i]=i;
	ans=0;
	for(int i=1; i<=cnt; i++) {
		int k=getdad(e[i].x);
		int l=getdad(e[i].y);
		if(k!=l) {
			dad[k]=l;
			ans++;
			sum+=e[i].v;
		}
	}
	cout<<ans<<' '<<sum;
}

int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		char a[maxn];
		cin>>a;
		for(int j=1; j<=m; j++)
			if(a[j-1]=='#')map[i][j]=1;
	}
	work1();
	work2();
	return 0;
}
