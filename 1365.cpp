#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100010;
int fa[maxn];
int find(int x) {
	if (fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void unionn(int a, int b) {
	int fx = find(a), fy = find(b);
	if (fx == fy)return;
	fa[fx] = fy;
}
int main() {
	int x, n, m;
	cin >> x >> n >> m;
	for (int i = 1; i <= x; i++)
		fa[i] = i;
	for (int i = 1, a, b; i <= n; i++)
		cin >> a >> b, unionn(a, b);
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b))puts("Yes");
		else puts("No");
	}
	return 0;
}
