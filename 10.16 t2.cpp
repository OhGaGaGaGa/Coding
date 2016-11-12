
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1500001;//大神防越界
int p[MAXN], n, into[MAXN];
bool vis[MAXN], aj[MAXN], die[MAXN];
struct Tqueue {
	int l, r, data[MAXN];
	void clear() {
		l = 1;
		r = 0;
	}
	bool empty() {
		return l > r;
	}
	void push(int t) {
		data[++r] = t;
	}
	int pop() {
		return data[l++];
	}
} Q;//手写队列

//取最小值
//Q里面是活着的人。
int getmin() {
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	memset(into, 0, sizeof(into));
	Q.clear();
	for (int i = 1; i <= n; i++) ++into[p[i]];
	for (int i = 1; i <= n; i++)
		if (into[i] == 0)
			Q.push(i), vis[i] = true;//这些人人缘好， 死不了
	while(!Q.empty()) {
		int x = Q.pop();//既然本宝宝不死
		if (die[x]) continue;//哦， 说好的我不死呢？
		x = p[x];//那么你就死定了
		if (die[x]) continue;//哦， 你已经死了
		++ans;//啊，你死了
		die[x] =true;
		vis[x] =true;//啊， 就是这样， 很好， 很清真
		--into[p[x]];
		if (into[p[x]] == 0) Q.push(p[x]), vis[p[x]] = true;//如果你已经死不了了， 欢迎加入英灵殿
	}
	//基佬们的开心生活 环
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			int t = p[i], len = 1;
			vis[p[i]] = true;
			while(t != i) {
				++len;
				t = p[t];
				vis[t] = true;
			}
			ans += 1 + ((len - 1) >> 1);//最小的情况是(len + 1) / 2
		}
	return ans;
}
int getmax() {
	int ans = n;
	memset(into, 0, sizeof(into));
	memset(vis, 0, sizeof(vis));
	memset(aj, 0, sizeof(aj));
	Q.clear();
	for (int i = 1; i <= n; i++) ++into[p[i]];
	for (int i = 1; i <= n; i++)
		if (into[i] == 0) {
			--ans;    //哦， 你们死不了
			Q.push(i);
			vis[i] = true;
		}
	while(!Q.empty()) {
		int x = Q.pop();
		--into[p[x]];
		aj[p[x]] = true;
		if (into[p[x]] == 0) {
			Q.push(p[x]);
			vis[p[x]] = true;
		}
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) {
			//然而最后你们还是要全死光光
			int t = p[i];
			bool jc = aj[i];
			vis[i] = true;
			while(t != i) {
				vis[t] = true;
				jc |= aj[t];
				t = p[t];
			}
			if (!jc && (!(i == p[i]))) --ans;
		}
	return ans;
}
int main() {
	//freopen("kill.in", "r", stdin);
	//freopen("kill.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	printf("%d %d\n", getmax(), getmin());
}
