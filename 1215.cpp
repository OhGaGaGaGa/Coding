#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#include<cctype>
#include<cstdlib>
#define D(x) cerr<<#x<<"="<<x<<" "
using namespace std;
const int inf=0x7fffffff;
const int maxn=20;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[maxn][maxn],fromx,fromy,endx,endy;
int to_x[]={1,0,0,-1},to_y[]={0,1,-1,0};
struct node{
	int x,y;//,step;
};
bool vis[maxn][maxn];
void bfs(){
	queue<node> q;
	q.push((node){fromx,fromy});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		if(u.x==endx&&u.y==endy){
			puts("YES");
			return;
		}
		for(int i=0;i<4;i++){
			int dx=u.x+to_x[i],dy=u.y+to_y[i];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=n&&!vis[dx][dy])
				vis[dx][dy]=1,q.push((node){dx,dy});//,u.step+1});
		}
	}
	puts("NO");
}
int main(){
	int m=read();
	while(m--){
		n=read();
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				char x;
				cin>>x;
				if(x=='#')a[i][j]=0;
				else{
					a[i][j]=1;
					if(x=='s')fromx=i,fromy=j;
					if(x=='e')endx=i,endy=j;
				}
			}
		memset(vis,0,sizeof(vis));
		bfs();
	}
}
