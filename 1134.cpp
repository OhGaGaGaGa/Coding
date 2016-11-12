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
const int maxn=100010;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,xx,yy;
struct node{
	int a,b,x,y;
}e[maxn];
void _read(){
	n=read();
	for(int i=1,a,b,x,y;i<=n;i++)
		a=read(),b=read(),x=read(),y=read(),e[i]=(node){a,b,x,y};
	xx=read(),yy=read();
}
void solve(){
	for(int i=n;i;i--){
		int a=e[i].a,b=e[i].b,x=e[i].x,y=e[i].y;
		if(a<=xx&&a+x>=xx&&b<=yy&&b+y>=yy){
			printf("%d\n",i);
			return;
		}
	}
	puts("-1");
}
int main(){
	_read();
	solve();
	return 0;
}
