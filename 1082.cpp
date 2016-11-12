#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long

using namespace std;
const ll maxn = 200010;
struct node {
	ll l, r, mid;
	ll sum, tag;
}tree[maxn<<2];
void build(ll num,ll l, ll r) {
	ll mid = l + ((r - l) >> 1);
	tree[num].l = l;
	tree[num].r=r;
	tree[num].mid= mid;
	if (l < r) {
		build(num * 2, l, mid);
		build(num * 2 + 1, mid + 1, r);
	}
}
void update(ll num) {
	tree[num].sum = tree[num << 1].sum + tree[num << 1].tag*(tree[num << 1].r - tree[num << 1].l + 1) +
		tree[num * 2 + 1].sum + tree[num * 2 + 1].tag*(tree[num * 2 + 1].r - tree[num * 2 + 1].l + 1);
}
void push_down(ll num) {
	tree[num].sum += (tree[num].tag*(tree[num].r - tree[num].l + 1));
	tree[num << 1].tag += tree[num].tag;
	tree[num * 2 + 1].tag += tree[num].tag;
	tree[num].tag = 0;
}
void llerval_update(ll l, ll r, ll num, ll delta) {
	if (l <= tree[num].l&&r >= tree[num].r) {
		tree[num].tag += delta;
		return;
	}
	if (tree[num].mid >= l)llerval_update(l, r, num * 2, delta);
	if (tree[num].mid < r) llerval_update(l, r, num * 2, delta);
	update(num);
}
void _1_llerval_update(ll num,ll l,ll r,ll delta){//l,r区间改变数值delta
    if (l<=tree[num].l&&tree[num].r<=r)tree[num].tag+=delta;
    else{
    	if (l<=tree[num].mid)_1_llerval_update(2*num,l,r,delta);
    	if (r>tree[num].mid) _1_llerval_update(2*num+1,l,r,delta); 
		tree[num].sum=
		tree[2*num].sum+
		(tree[2*num].r-tree[2*num].l+1)*tree[2*num].tag+
		tree[2*num+1].sum+
		(tree[2*num+1].r-tree[2*num+1].l+1)*tree[2*num+1].tag;   
	}//向下打标记，向上更新父节点 
 } 

ll llerval_find(ll num, ll l, ll r) {
	ll ans = 0;
	if (l <= tree[num].l&&r >= tree[num].r) 
		return tree[num].sum + tree[num].tag*(tree[num].r - tree[num].l + 1);
	if(tree[num].tag)push_down(num);
	if (l <= tree[num].mid)ans += llerval_find(num << 1, l, r);
	if (r > tree[num].mid)ans += llerval_find(num * 2 + 1, l, r);
	return ans;
}
int main() {
    ll a,b,c,d,m,n;
	memset(tree,0,sizeof(tree));
	cin>>n;
	build(1,1,n);
	for(ll i=1;i<=n;i++){	
		cin>>a;
		_1_llerval_update(1,i,i,a);
		//llerval_update(i,i,1,a);
	}
	cin>>m;
	for(ll i=1;i<=m;i++){
		cin>>a>>b>>c;
		if (a==1){
			cin>>d;
			_1_llerval_update(1,b,c,d);
			//llerval_update(b,c,1,d);
		}
		else cout<<llerval_find(1,b,c)<<endl;
	}
	return 0;
}
