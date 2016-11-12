#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,a[1000010],b[1000010];//n:选手数，x：得的分数
int main() {
	freopen("Olympiad.in","r",stdin);
	freopen("Olympiad.out","w",stdout);
	cin>>n>>x;
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)
		scanf("%d",&b[i]);
	printf("1 ");

	if(n<=10000) {
		sort(b+1,b+1+n);
		int tot=0,ans=0;
		do {
			tot=0;
			for(int i=1; i<=n; i++)
				if(a[i]+b[i]>=x)tot++;
			ans=max(ans,tot);
		} while(next_permutation(b+1,b+1+n));
		printf("%d\n",ans);
	} 
	else {
		sort(a+1,a+n+1,greater<int>());
		sort(b+1,b+n+1,less<int>());
		int ax=1,bx=1,ans=0;
		while(ax<=n&&bx<=n) {
			while(a[ax]+b[bx]<x) bx++;
			if(bx>n)break;
			ans++;
			++ax;
			++bx;
		}
		printf("%d",ans);
	}
	return 0;
}
