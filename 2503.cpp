#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#define lcz(x) cerr<<#x<<"="<<x<<" "
using namespace std;
int w[100010],c[100010],cnt=0,f[100010];
void add_bag(int waste,int val,int num) {
	for(int i=(int)floor(log2(num))+1; i>=0; i--) {
		int x=(1<<i);
		if(num>=x) {
			num-=x;
			w[++cnt]=val*x;
			c[cnt]=waste*x;
			/*lcz(w[cnt]);
			lcz(c[cnt]);
			lcz(cnt);
			lcz(x);
			cout<<endl;*/
		}
	}
}
int main() {
	int n,m;
	cin>>m>>n;
	for(int i=1,p,W,h; i<=n; i++) {
		cin>>p>>W>>h;
		add_bag(p,W,h);
	}
	for(int i=1; i<=cnt; i++)
		for(int v=m; v>=c[i]; v--)
			f[v]=max(f[v],f[v-c[i]]+w[i]);
	int ans=0;
	for(int i=1;i<=m;i++)
		ans=max(ans,f[i]);
	cout<<ans<<endl; 
}
/*
1000 30
134 5 30
101 6 12
13 1 1
546 10 34
6554 1 1
145 2 3
134 5 30
101 6 12
13 1 1
546 10 34
6554 1 1
145 2 3
134 5 30
101 6 12
13 1 1
546 10 34
6554 1 1
145 2 3
134 5 30
101 6 12
13 1 1
546 10 34
6554 1 1
145 2 3
134 5 30
101 6 12
13 1 1
546 10 34
6554 1 1
145 2 3
*/
//cout<<59;
