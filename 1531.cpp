#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
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
int n,a[23333],stack[23333];
int main(){
	n=read();
	int top=0,ans=0;
	a[1]=read();
	stack[++top]=a[1];
	for(int i=2;i<=n;i++){
		a[i]=read();
		ans+=top;
		while(top&&a[i]>=stack[top])top--;
		stack[++top]=a[i];
	}
	cout<<ans<<endl;
}
