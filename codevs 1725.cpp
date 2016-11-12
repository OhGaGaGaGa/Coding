#include<bits/stdc++.h>
//codevs1725
using namespace std;
int n,k,f[1000010],s[1000010];
bool isOK(int x){
	int ans=0,from=1;
	for(int i=1;i<=n;i++){
		if(x<=s[i]-s[from-1])
			ans++,from=i+1;
		if(ans>=k)return true;
	}
	return ans>=k;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&f[i]),s[i]=s[i-1]+f[i];
	int l=0,r=s[n]+1;
	while(l<r){
		int mid=l+((r-l)>>1);//+1;
		//if(cheak(mid))l=mid+1;
		if(isOK(mid))l=mid+1;
		else r=mid;
	}
	printf("%d\n",l-1);
}
