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
#define pii pair<int,int>
#define D(x) cerr<<#x<<"="<<x<<" "
using namespace std;
const int inf=0x7fffffff;
const int maxn=100100;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k,v[maxn],x,c[maxn];
bool flag[maxn];
int main(){
	double doub;
	n=read(),k=read();
	scanf("%lf",&doub);
	set<int> num;
	map<int,int> ma;
	x=(int)(doub*10.0);
	for(int i=1;i<=n;i++)
		scanf("%lf",&doub),c[i]=(int)(doub*10);
	for(int i=1;i<=n;i++)	
		v[i]=read();
	for(int t,i=1;i<=n;i++){
		t=read();
		if(num.find(t)==num.end())
			num.insert(t),ma[t]=i;
	}
	int tot=0;
	for(int t,i=1;i<=k;i++){
		t=read(),flag[t]=1,x-=c[ma[t]],tot+=v[ma[t]];//,D(t),D(ma[t]),cout<<endl;
	}
	static int f[233]={0};
	memset(f,0,sizeof(f));
	for(set<int>::iterator it=num.begin();it!=num.end();it++)
		if(!flag[*it])
			for(int V=x;V>=c[ma[*it]];V--)
				f[V]=max(f[V],f[V-c[ma[*it]]]+v[ma[*it]]);
	printf("%d\n",f[x]+tot);
}
