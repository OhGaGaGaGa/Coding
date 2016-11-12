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
const int maxn=111;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
double f[maxn][maxn],d[maxn*maxn];
int n,p[maxn][maxn],t[maxn][maxn],num[maxn*maxn];
bool spfa(){
	static bool vis[maxn*maxn];
	queue<int> q;	
	memset(d,-0x3f,sizeof( d ));
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	q.push(1);
	vis[1]=1,d[1]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(num[x]>n)return 1;
		for(int i=1;i<=n;i++){
			if(p[x][i]&&d[i]<d[x]+f[x][i]){
				d[i]=d[x]+f[x][i];
				if(!vis[i])
					q.push(i),vis[i]=1,num[i]++;
				if(num[x]>n)return 1;
			}
		}
		vis[x]=0;
	}
	if(d[n]>0)return 1;
	return 0;
}
bool check(double ans){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=p[i][j]-(double)t[i][j]*ans;
	if(spfa())return 1;
	return 0;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			p[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			t[i][j]=read();
	double l=0,r=10000;
	while(r-l>=0.0001){
		double mid=l+(r-l)/2;
		if(check(mid))l=mid+0.0001;
		else r=mid;
	}
	printf("%.3lf\n",l);
}
