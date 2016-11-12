#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
#define ull unsigned long long
const int mod = 1000000007;
const int maxn = 1000 + 9;
inline ull getull() {
	ull a=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {a=a*10+c-'0';c=getchar();}
	return a*f;
}
ull f[maxn][maxn];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ull n=getull(),m=getull();
	if(n==1||m==1){
		puts("1");
		return 0;
	}
	else if(n==0&&m==0){
		puts("2");
		return 0;
	}
	else if(n<=1001&&m<=1001){
		n--,m--;
		memset(f,0,sizeof(f));
		int ljm=max(m,n);
		for(int i=0;i<=ljm;i++)f[n][i]=f[i][m]=1;
		for(int i=n-1;i>=0;i--)
			for(int j=m-1;j>=0;j--)
				f[i][j]=(f[i+1][j]%mod+f[i][j+1]%mod)%mod;
		cout<<f[0][0]%mod<<endl;
		return 0;
	}
	else{
		n--,m--;
		memset(f,0,sizeof(f));
		int lcz=max(m,n);
		for(int i=0;i<=lcz;i++)f[n][i]=f[i][m]=1;
		for(int i=n-1;i>=0;i--)
			for(int j=m-1;j>=0;j--)
				f[i%1000][j%1000]=(f[(i+1)%1000][j%1000]%mod+f[i%1000][(j+1)%1000]%mod)%mod;
		cout<<f[0][0]%mod<<endl;
		return 0;
	}
}
