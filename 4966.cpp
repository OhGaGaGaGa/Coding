#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#define D(x) cerr<<#x<<"="<<x<<" "
using namespace std;
const int maxn = 10;
int a[maxn][maxn], k, EveryK;
multiset<int> HengXiang[maxn], ZongXiang[maxn], Qu[maxn];
bool dfs(int x, int y) {
	if(a[k-1][k-1]||x==k){
		for (int ii = 0; ii < k; ii++) {
				printf("%d", a[ii][0]);
				for (int jj = 1; jj < k; jj++)
					printf(" %d", a[ii][jj]);
				puts("");
			}
		return 1;
	}
	if(a[x][y]){
		if (y + 1 < k) {if (dfs(x, y + 1))	return 1;}
		else {if (dfs(x + 1, 0)) return 1;}
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		if(HengXiang[x].count(i)||ZongXiang[y].count(i)||Qu[(x/EveryK)*EveryK+(y)/EveryK].count(i))
				continue;
		HengXiang[x].insert(i);
		ZongXiang[y].insert(i);
		Qu[(x / EveryK) * EveryK + (y) / EveryK].insert(i);
		a[x][y]=i;
		if (y + 1 < k) {if (dfs(x, y + 1))	return 1;}
		else {if (dfs(x + 1, 0)) return 1;}
		HengXiang[x].erase(i);
		ZongXiang[y].erase(i);
		Qu[(x / EveryK) * EveryK + (y) / EveryK].erase(i);
		a[x][y]=0;
	}
	return false;
}
int main() {
	k=4;
	EveryK = (int)sqrt(k);
	//D(EveryK);	cout << endl;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			cin >> a[i][j];
			if (a[i][j]) {
				HengXiang[i].insert(a[i][j]);
				ZongXiang[j].insert(a[i][j]);
				Qu[(i / EveryK)*EveryK + j / EveryK].insert(a[i][j]);
			}
		}
	dfs(0,0);
	return 0;
}
