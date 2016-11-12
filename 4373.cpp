#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000010],f[1000010];
struct node{
	int index,val;
}que[1000010];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int head=1,tail=0;//[head,tail]
	for(int i=1;tail<=n&&i<=n;i++){
		while(que[tail].val>=a[i]&&tail>=head)
			tail--;
		tail++;
		que[tail].index=i;
		que[tail].val=a[i];
		if(que[tail].index-que[head].index+1>k)head++;
		f[i]=que[head].val;
	}
	for(int i=k;i<=n;i++){
		printf("%d ",f[i]);
	}
	puts("");
	memset(que,0,sizeof(que));
	memset(f,0,sizeof(f));
	for(int i=1;tail<=n&&i<=n;i++){
		while(que[tail].val<=a[i]&&tail>=head)
			tail--;
		tail++;
		que[tail].index=i;
		que[tail].val=a[i];
		if(que[tail].index-que[head].index+1>k)head++;
		f[i]=que[head].val;
	}
	for(int i=k;i<=n;i++){
		printf("%d ",f[i]);
	}
	puts("");
}
