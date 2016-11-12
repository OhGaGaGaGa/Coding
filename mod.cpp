#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#define D(x) cerr<<#x<<"="<<x<<" "
using namespace std;
const int inf=0x7fffffff;
const int maxn=100010;
inline int getint(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int mod = 1000000007;
int f[1010][1010];
int main(){
//	freopen("count.in","r",stdin);
//	freopen("mod.out","w",stdout);
	int n=getint(),m=getint();
		n--,m--;
		memset(f,0,sizeof(f));
		int lcz=max(m,n);
		for(int i=0;i<=lcz;i++)f[n][i]=f[i][m]=1;
		for(int i=n-1;i>=0;i--){
			for(int j=m-1;j>=0;j--){
				f[i%1000][j%1000]=(f[(i+1)%1000][j%1000]%mod+f[i%1000][(j+1)%1000]%mod)%mod;
			}
		}
	cout<<f[0][0]%mod<<endl;
}
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//cout<<"the time used:"<<(double)(clock())/CLOCKS_PER_SEC<<endl;

