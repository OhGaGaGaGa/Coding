#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<set>
#define D(x) cerr<<#x<<"="<<x<<" "
#define ull unsigned long long
using namespace std;
const int maxn = 20, k=9, EveryK=3;
int a[maxn][maxn];
multiset<int> HengXiang[maxn], ZongXiang[maxn], Qu[maxn];
ull ans = 0, tot;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void dfs(int x, int y) {
	if (x == k) {
		for (int ii = 0; ii < k; ii++) {
			printf("%d", a[ii][0]);
			for (int jj = 1; jj < k; jj++)
				printf(" %d", a[ii][jj]);
			puts("");
		}
		return;
	}
	if (a[x][y]) {
		if (y + 1<k) { dfs(x, y + 1); return; }
		else { dfs(x + 1, 0); return; }
	}
	for (int i = k; i >=1; i--) {
		if (HengXiang[x].count(i) || ZongXiang[y].count(i) || Qu[(x / EveryK)*EveryK + (y) / EveryK].count(i))
			continue;
		HengXiang[x].insert(i);
		ZongXiang[y].insert(i);
		Qu[(x / EveryK) * EveryK + (y) / EveryK].insert(i);
		a[x][y] = i;
		if (y + 1 < k)dfs(x, y + 1);
		else  dfs(x + 1, 0);
		HengXiang[x].erase(i);
		ZongXiang[y].erase(i);
		Qu[(x / EveryK) * EveryK + (y) / EveryK].erase(i);
		a[x][y] = 0;
	}
}
int main() { 
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			a[i][j]=read();
			if (a[i][j]) {
				HengXiang[i].insert(a[i][j]);
				ZongXiang[j].insert(a[i][j]);
				Qu[(i / EveryK)*EveryK + j / EveryK].insert(a[i][j]);
			}
		}
	dfs(0, 0);
	
	return 0;
}
