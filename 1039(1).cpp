#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 233;
int main() {
	int n, K;
	cin >> n >> K;
	static int f[maxn][maxn][10];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			f[i][j][0]=1;
	for (int len = 1; len <= n; len++)
		for (int start = 1; start <= n - len + 1; start++)
			for (int p = 0; p <= len - 1; p++)
				for (int k = start + 1; k < len + start - 1; k++)
					for (int a = 0; a <= min(p - 1, k - 1); a++)
						f[start][len + start - 1][p] = f[start][k][a] + f[k + 1][len + start - 1][p - a - 1];
	//f[from][end][p] = f[from][k][a] + f[k + 1][end][p - a - 1];
	//a from 1 to p-1//from from 1 to n//end from from to n//k from from+1 to end-1
	cout << f[1][n][K] << endl;
}
