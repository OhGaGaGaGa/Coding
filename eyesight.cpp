#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#define ull unsigned long long
using namespace std;
inline int getint() {
	int a=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {a=a*10+c-'0';c=getchar();}
	return a*f;
}
const int maxn = 10000 + 9;
const int maxv = 500 + 9;
struct node{int v,val;}a[maxn << 1];
ull f[maxv][maxv];
int n,m,n2,n3;
int main(){
	freopen("eyesight.in","r",stdin);
	freopen("eyesight.out","w",stdout);
	int t=getint();
	while(t--){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		n=getint();	m=getint();
		n2=getint();n3=getint();
		for(int x,i=1;i<=n2;i++)
			x=getint(),a[i]=(node){2,x};
		for(int x,i=n2+1;i<=n3+n2;i++)
			x=getint(),a[i]=(node){3,x};
		for(int num=1;num<=n3+n2;num++){
			int co=a[num].v,val=a[num].val;
			for(int i=n;i>=co;i--)
				for(int j=m;j>=1;j--)
					f[i][j]=max(f[i][j],f[i-co][j]+val);
			for(int i=n;i>=1;i--)
				for(int j=m;j>=co;j--)
					f[i][j]=max(f[i][j],f[i][j-co]+val);
		}
		cout<<f[n][m]<<endl;
	}
}
