#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define D(x) cerr<<#x<<"="<<x<<" "
using namespace std;
const int maxn = 200010;
int n,fa[maxn],p[maxn][50]={0},log_max;
int head[maxn], cntt=0, d[maxn];
struct node {
	int nxt, to;
}e[maxn<<1];
void add_edge(int u, int v) {
	e[++cntt].to = v;
	e[cntt].nxt = head[u];
	head[u] = cntt;
}
void dfs(int num,int last) {
	d[num] = d[last] + 1;
	p[num][0] = last;
	for (int i = 1; i <= log_max; i++)
		p[num][i] = p[p[num][i - 1]][i - 1];
	for (int i = head[num]; i != -1; i = e[i].nxt)
		if (p[e[i].to][0] == 0 && p[e[i].to][1] == 0 && e[i].to!=1)
			dfs(e[i].to, num);
}
int lca(int a, int b) {
	if (d[a] > d[b])a ^= b ^= a ^= b;//a->up,b->down
	int del = d[b] - d[a];
	//D(del);
	for (int i = 0; i < log_max; i++)
		if ((1 << i) & del) b = p[b][i];
	//D(d[a]);D(d[b]);cerr<<endl;
	if ( a != b )
		for (int i = log_max; i >= 0; i--)
			if (p[a][i] != p[b][i])	a = p[a][i], b = p[b][i];
	if(a==1)return 1;
	return p[a][0]; 
}
int main() {
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	for (int i = 1, a, b; i < n; i++)
		cin >> a >> b, add_edge (a, b) , add_edge (b, a);
	log_max = (int)log2(n) + 2;
	dfs(1,-1);
	int m, pre = 0, x, ans = 0;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		//D(d[x]); D(lca(x,pre)); cerr << endl;
		if (pre != 0)
			ans += (d[x] + d[pre] - 2 * d[lca(x, pre)]);
		pre=x;
		//D(pre);
	}
	printf("%d\n", ans);
}
/*
5
1 2
1 5
3 5
4 5
4
1
3
2
5
*/
