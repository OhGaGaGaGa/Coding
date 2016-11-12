#include<iostream>//枚举最长边，然后从比他小的边里并查集，看看能不能让起点与终点联通 
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
const int maxn=555,maxm=5555;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node{
	int from,to,val;
}e[maxm];
int fa[maxn];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
} 
void unionn(int a,int b){
	int fx=find(a),fy=find(b);
	if(fx==fy)return ;
	fa[fx]=fy;
}
inline bool cmp(node a,node b){
	return a.val>b.val;
}
int n,m;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e[i]=(node){u,v,w};
	}
	int s=read(),t=read();
	sort(e+1,e+m+1,cmp);
	int maxx=inf,minn=1;bool flag=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)fa[j]=j;
		for(int j=i;j<=m;j++){
			unionn(e[j].from,e[j].to);
			if(find(s)==find(t)){
				if(((double)maxx/(double)minn)>((double)e[i].val/(double)e[j].val))
					maxx=e[i].val,minn=e[j].val;
				flag=1;
				break;
			}
		}
	}
	if(!flag){
		puts("IMPOSSIBLE");
		return 0;
	}
	int r=__gcd(maxx,minn);
    maxx/=r;
    minn/=r;
    if(minn==1) printf("%d\n",maxx);
    else printf("%d/%d\n",maxx/r,minn/r);
}
