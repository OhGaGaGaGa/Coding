#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 101;
int fa[maxn*maxn];
struct node{
	int a,b,val;
}e[maxn*maxn];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool unionn(int a,int b){
	int fx=find(a),fy=find(b);
	if(fx==fy)return false;
	fa[fx]=fy;
	return 1;
}
inline bool cmp(node a,node b){
	return a.val<b.val;
} 
int a[maxn][maxn];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1,a;j<=n;j++)
			cin>>a,e[++cnt]=(node){i,j,a};
	sort(e+1,e+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++)
		if(unionn(e[i].a,e[i].b))ans+=e[i].val;
	printf("%d\n", ans);
}
