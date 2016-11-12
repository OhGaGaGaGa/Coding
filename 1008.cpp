#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define D(x) cerr<<#x<<"="<<x<<" "
#define ull unsigned long long
using namespace std;
const int maxn = 59168333;
int n, k, a[maxn], prime[maxn >> 1], cnt = 0;
bool not_prime[maxn];
int ans = 0;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x*f;
}
bool pd(ull y)
{
if(y==1)return false;
for(int i=2;i<=sqrt(y)+1;i++)
if(y%i==0)return false;
return true;
}
void dfs(int x,int num,ull tot) {
	if (num == k) {
		if (py(tot))ans++;
		return;
	}
	for (int i = x + 1; i <= n; i++) 
		dfs(i,num+1,tot+a[i]);
}
ull tot=0;
void shai() {
	memset(not_prime, 0, sizeof(not_prime));
	not_prime[1] = 1;
	for (int i = 1; i <= tot; i++) {
		if (!not_prime[i])prime[++cnt] = i;
		for (int j = 1; j <= cnt; j++) {
			if (prime[j] * i > tot)break;
			not_prime[prime[j] * i] = 1;
			if (!i%prime[j])break;
		}
		
	}
}
int main() {
	n=read(),k=read();
	for (int i = 1; i <= n; i++)
		a[i]=read(),tot+=a[i];
	//cout<<tot;
	//shai();
	dfs(0,0,0);
	printf("%d\n",ans);
}
