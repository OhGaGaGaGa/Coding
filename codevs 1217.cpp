#include<bits/stdc++.h>
//codevs 1217 jiejiaoshi xianduanshu/erfen
using namespace std;
/*erfen:
int n,m,tot,f[1000010],a[1000010],d[1000010],s[10000010],t[1000010];
bool isOK(int x){
	memset(f,0,sizeof(f));
	for(int i(1);i<=x;++i){
		f[s[i]]+=d[i],f[t[i]+1]-=d[i];
	}
	tot=0;
	for(int i(1);i<=n;i++){
		tot+=f[i];
		if(tot>a[i])return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)//{
		scanf("%d%d%d",&d[i],&s[i],&t[i]);
		//f[s[i]]+=d[i],f[t[i]+1]-=d[i];
	//}
	int l=1,r=m;
	while(l<r){
		int mid=l+((r-l)>>1);
		if(isOK(mid))l=mid+1;
		else r=mid;
	}
	if(l<m)printf("-1\n%d\n",l);
	else printf("0\n");
}*/
//xianduanshu:
struct node{
	int mid,l,r,sum,tag;
}tree[1000010];
void build_tree(int num,int l,int r){
	tree[num].l=l;
	tree[num].r=r;
	tree[num].mid=(l+r)>>1;
	if(l==r)tree[num].s
	if(l<r){
		build_tree(num*2,l,tree[num].mid);
		build_tree(num*2+1,tree[num].mid+1,r);
	}
}
void single_update(int num,int x,int delta){//x jiedian jia delta
	if(tree[num].l==tree[num].r)tree[num].sum+=delta;
	else{
		if(x<=tree[num].mid)single_update(num*2,x,delta);
		else single_update(num*2+1,x,delta);
		tree[num].sum=tree[num*2].sum+tree[num*2+1].sum;
	}
}
void intervel_update(int num,int l,int r,int delta){
	if(l<=tree[num].l&&r>=tree[num].r)tree[num].tag-=a[l];
	
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	build_tree(1,1,n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
}
