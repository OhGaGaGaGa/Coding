#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define D(X) cerr<<#X<<"="<<X<<" "
using namespace std;
const int maxn = 1000 + 9;
int put[maxn],a[maxn],b[maxn],lis_a[maxn],lis_b[maxn],a_lis[maxn],b_lis[maxn];
bool dfs(int x,int len,int last) {
	if(len==-1)return 1;
	//D(last);D(x);
	//cout<<endl;
	for(int i=last-1; i>=0; i--)
		if(x>=a[i]) {
			a_lis[len]=a[i];
	//		D(i),D(a[i]),D(a_lis[len]),D(len);
	//		cout<<endl;
			if(dfs(a[i],len-1,i))return 1;
		}
	return 0;
}
int main() {
	int n,len=0;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i]>>b[i];
	//for(int i=0;i<n;++i)
	//	cout<<a[i]<<" ";
	//puts("");
	//puts("");
	 
	for(int i = 0; i < n; i ++) {//最长不降 
		if(len == 0 ||a[i] > lis[len - 1]) {
			lis[len] = a[i],len ++;
		else {
			p = lower_bound(lis,lis +len,a[i]) - lis;
			lis[p] = a[i];
		}
	}
	
	for(int i=0; i<n; i++) {//最长上升子序列 
		int p=lower_bound(lis_a,lis_a+len,a[i])-lis_a;
		lis_a[p]=a[i];
		if(p==len)len++;
	}
	/*
	for(int i = 0; i < n; i ++) {
		p = lower_bound(lis,lis +len,a[i]) - lis;
		lis[p] = a[i];
		if(p == len)
			len ++;
	}
	*/
	//for(int i=0;i<10;i++)
//		printf("%d ",lis_a[i]);
//		puts("");
	//int a_lis[len]=lis_a[len];
//	D(len);
//	puts("");
//	puts("");
	len=5;
	dfs(lis_a[len-1],len-1,n);
	printf("%d",a_lis[0]);
	for(int i=1; i<len; i++)
		printf(" %d",a_lis[i]);
	puts("");
}
/*
7
1  4
3  7
5  8
10 8
8  2
4  6
10 9

5
*/
