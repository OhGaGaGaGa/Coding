#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int a[5010],b[5010];//,d1[5002][5002],d2[5002][5002];
/*struct node {
	int to,next;
} e1[100010],e2[100010];

int head1[100010],head2[100010],cntt=0;
void add1(int u,int v) {
	e1[++cntt].to=v;
	e1[cntt].next=head1[u];
	head1[u]=cntt;
}
void add2(int u,int v) {
	e2[++cntt].to=v;
	e2[cntt].next=head2[u];
	head2[u]=cntt;
}*/ 
vector<int> d1[5010],d2[5010];
int main() {
	//freopen("formation.in","r",stdin);
	//freopen("formation.out","w",stdout);
	int n;
//	memset(head1,-1,sizeof(head1));
//	memset(head2,-1,sizeof(head2));
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		for(int j=1;j<i;j++)
			d1[a[j]].push_back(a[i]);
	}
		//,add1(a[i-1],a[i]);
	/*for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
			add(a[i],a[j]);
	cntt=0;*/
	for(int i=1; i<=n; i++){
		scanf("%d",&b[i]);
		for(int j=1;j<i;j++)
			d2[b[j]].push_back(b[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<d2[a[i]].size();j++){
			if(d1[a[i]].find(d2[j])!=d1[a[i]].end())
				
		}
	}
	/*for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
			add(b[i],b[j]);*/
	
}
