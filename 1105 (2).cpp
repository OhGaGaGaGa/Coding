#include <iostream>//wa 0
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x7fffffff;
int getint() {
	int a=0,f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)) {a=a*10+c-'0';c=getchar();}
	return a*f;
}
const int maxn=233;
int stone[maxn],dp[233333];
int main(int argc, char const *argv[]){
	memset(dp,0x3f,sizeof(dp));
	int l=getint(),s=getint(),t=getint(),m=getint();
	for(int i=1;i<=m;i++)
		stone[i]=getint();
	sort(stone+1,stone+1+m);
	for(int i=1;i<=m;i++){
		if(stone[i]<=t)dp[stone[i]]=1;
		for(int j=stone[i]+s;j<=stone[i]+t;j++)
			dp[j]=min(dp[j],dp[stone[i]]+1);
	}		
	int ans=inf;
	for(int i=l;i<=l+t;i++)
		ans=min(ans,dp[i]);
	cout<<ans-2<<endl;
	return 0;
}
