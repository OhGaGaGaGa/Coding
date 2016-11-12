#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
/*
using namespace std;
const int maxn = 233;
int f[maxn][maxn]= {0};
int n, k, tot = 0, ans = 0;
void dfs(int x,int cnt) {
	if (cnt == k+1) {
		if (ans == n)tot++;
		return;
	}
	for (int i = x; i <= n - k; i++)
		ans += i,dfs(i, cnt + 1),ans -= i;
}
int main() {
	cin >> n >> k;
	dfs(1, 1);
	cout << tot << endl;
}
*/
using namespace std;
const int N = 250;
int n, k, cnt, sum;
void dfs(int step, int p) {
	if(step == k+1) {
		if(sum == n) cnt++;
		return ;
	}
	for(int i = p; i <= n-sum; i++) {
		sum += i;
		dfs(step+1, i);
		sum -= i;
	}
}
int main() {
	scanf("%d%d", &n, &k);
	dfs(1, 1);
	printf("%d\n", cnt);
	return 0;
}
