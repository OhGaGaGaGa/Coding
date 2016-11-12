#include<bits/stdc++.h>
#define D(x) cerr<<#x<<"="<<x<<" "
#define E cerr<<endl 
using namespace std;
long long room[1000010],f[1000010],n,m,maxx;
bool isOK(int x){
	long long ans=1,cnt=0;
	for(long long i=2;i<=n;i++){
		if(x>f[i]){
			cnt+=f[i];
			if(cnt>=x)cnt=0,ans++;
		}
		if(x<=f[i])
			cnt=0,ans++;
	}
	return ans>=m;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&room[i]);
	sort(room+1,room+1+n);
	for(int i=2;i<=n;i++)
		f[i]=room[i]-room[i-1];//,D(room[i]),D(f[i]),E;
	long long l=1,r=room[n]-room[1]+1;
	while(r-l>1){
		int mid=l+((r-l)>>1);
		if(isOK(mid))l=mid;
		else r=mid;	
	}
	printf("%lld\n",l);
} 
