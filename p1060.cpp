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
int n,m,f[maxn],v[maxn],c[maxn];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		v[i]=x*y,c[i]=x;
	}
	for(int i=1;i<=m;i++)
		for(int j=n;j>=c[i];j--)
			f[j]=max(f[j],f[j-c[i]]+v[i]);
	cout<<f[n];
}
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//cout<<"the time used:"<<(double)(clock())/CLOCKS_PER_SEC<<endl;

