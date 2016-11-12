#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int getint(){
	int a=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){a=a*10+c-'0';c=getchar();}
	return a*f;
}
int a[233],n,k;
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=getint();
	k=getint();
	for(int i=1;i<=n;i++)	a[i]=i;
	int ans=0,last,cnt;
	do{
		last=a[1],cnt=0;
		for(int i=2;i<=n;++i){
			if(a[i]>last)++cnt;
			last=a[i];
		}
		if(cnt==k)++ans;
	}while(next_permutation(a+1,a+1+n));
	printf("%d\n",ans);
}