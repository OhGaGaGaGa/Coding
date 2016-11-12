#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100;
struct node{
	int a,b;
}d[maxn];
inline bool cmp(node a,node b){
	//if(a.a!=b.a)return a.a<b.a;
	return a.b<b.b;
}
int main(){
	int n,last=-1000;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if(x>y)x^=y^=x^=y;
		d[i]=(node){x,y};
	}
	sort(d+1,d+1+n,cmp);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(d[i].a<last){
			cnt++;
			continue;
		}
		last=d[i].b;
	}
	printf("%d\n", n-cnt);
}
/*
3
6 3
1 3
2 5
*/
