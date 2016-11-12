#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int from,to,dis;
}e[100010];
int fa[100010];
bool cmp(const node &a,const node &b){
	return a.dis>b.dis;
}
int getf(int x){
	if(fa[x]==x)return x;
	return fa[x]=getf(fa[x]);
}
int unionn(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy)return 0;
	fa[fx]=fy;
	return 1;
}
int main(){
	
	int T;
	scanf("%d",&T);
	while(T--){
		//memset(fa,-1,sizeof(fa));
		int m,n,r;
		scanf("%d%d%d",&n,&m,&r);
		for(int i=0,x,y,v;i<r;i++){
			scanf("%d%d%d",&x,&y,&v);
			e[i].from=x;e[i].to=y+n;e[i].dis=v;
			//e[i*2+1].from=x;e[1+2*i].to=y+n;e[i*2+1].dis=v;
		} 
		sort(e,e+r,cmp);
		int ans=0;
		for(int i=0;i<n+m;i++)
			fa[i]=i;
		for(int i=0;i<m+n;i++){
			if(unionn(e[i].from,e[i].to))
				ans+=e[i].dis;
		}
		printf("%d\n",(n+m)*10000-ans);
	}
}
