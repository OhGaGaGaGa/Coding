#include <iostream>//hui wa de er fen tan xin
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int getint(){
	int a=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){a=a*10+c-'0';c=getchar();}
	return a*f;
}
int a[maxn],n;
bool isOk(int x){
	int last=-1,k=0;
	for(int i=1;i<=n;i++){
		if(last>=a[i])	k++;
		last=max(last+1,a[i]);
		if(k>x)return 1;
	}
	return k>x?1:0;
}
int main(){
	freopen("incr.in","r",stdin);
	freopen("incr.out","w",stdout);
	n=getint();
	for(int i=1;i<=n;i++)
		a[i]=getint();
	int l=0,r=n;
	while(l<r){
		int mid=l+((r-l)>>1);
		if(isOk(mid))l=mid+1;
		else r=mid;
	}
	printf("%d\n", l);
}
