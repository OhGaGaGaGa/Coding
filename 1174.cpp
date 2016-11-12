#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#define D(x) cerr<<#x<<"="<<x<<" "
#define ull unsigned long long
using namespace std;
const int maxn = 10;
int a[maxn][maxn], k, EveryK;
const int m[9][9] = {
{ 6,6,6,6,6,6,6,6,6 },
{ 6,7,7,7,7,7,7,7,6 },
{ 6,7,8,8,8,8,8,7,6 },
{ 6,7,8,9,9,9,8,7,6 },
{ 6,7,8,9,10,9,8,7,6 },
{ 6,7,8,9,9,9,8,7,6 },
{ 6,7,8,8,8,8,8,7,6 },
{ 6,7,7,7,7,7,7,7,6 },
{ 6,6,6,6,6,6,6,6,6 } };
multiset<int> HengXiang[maxn], ZongXiang[maxn], Qu[maxn];
ull ans = 0;
void solve() {
	ull tot = 0;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			tot += (m[i][j] * a[i][j]);
}
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void dfs(int x, int y) {
	if (x == k) {
	//	ull tot = 0;
	//	for (int i = 0; i < k; i++)
	//		for (int j = 0; j < k; j++)
	//			tot += (m[i][j] * a[i][j]);
	//	ans = max(ans, tot);
	
		for (int ii = 0; ii < k; ii++) {
			printf("%d", a[ii][0]);
			for (int jj = 1; jj < k; jj++)
				printf(" %d", a[ii][jj]);
			puts("");
		}
		exit(1);
	}
	if (a[x][y]) {
		if (y + 1<k) { dfs(x, y + 1); return; }
		else { dfs(x + 1, 0); return; }
	}
	for (int i = k; i >= 1; i--) {
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
	k = 9;  EveryK = 3;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++) {
			a[i][j]=read();
			if (a[i][j]) {
				HengXiang[i].insert(a[i][j]);
				ZongXiang[j].insert(a[i][j]);
				Qu[(i / EveryK)*EveryK + j / EveryK].insert(a[i][j]);
			}
		}
	/*
	puts("Qu:");
	for (int i = 0; i < k; i++) {
		for (multiset<int>::iterator it = Qu[i].begin(); it != Qu[i].end(); it++)
			cout << *it << " ";
		puts("");
	}
	puts("HengXiang:");
	for (int i = 0; i < k; i++) {
		for (multiset<int>::iterator it = HengXiang[i].begin(); it != HengXiang[i].end(); it++)
			cout << *it << " ";
		puts("");
	}
	puts("ZongXiang:");
	for (int i = 0; i < k; i++) {
		for (multiset<int>::iterator it = ZongXiang[i].begin(); it != ZongXiang[i].end(); it++)
			cout << *it << " ";
		puts("");
	}
	puts("");
	*/
	dfs(0, 0);
	//if(ans)cout<<ans<<endl;
	//else puts("-1");
//	cout << "the time used:" << (double)(clock()) / CLOCKS_PER_SEC << endl;
	return 0;
}
/*
 6 3 9 1 8 7 4 2 5
 1 4 7 2 5 3 8 9 6
  8 2 5 6 9 4 7 1 3
  7 8 6 5 3 2 1 4 9
  9 1 2 4 7 6 3 5 8
  3 5 4 9 1 8 2 6 7
  2 7 1 3 6 5 9 8 4
  4 6 8 7 2 9 5 3 1
  5 9 3 8 4 1 6 7 2 
  */
