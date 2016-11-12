#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mjt(x) cerr<<#x<<"="<<x<<" "
using namespace std;
int n,f[1000010];
int dfs(int x){
	if(x==1)
		return 1;
	if(f[x]>1)return f[x];
	for(int i=x/2;i>=1;i--)
		f[x]+=dfs(i);
	return f[x]; 
}
int main(){
	scanf("%d",&n);
	f[1]=1;
	for(int i=2;i<=n;i++){
		//mjt(i);mjt(f[i]);
		for(int j=1;j<=i/2;j++)
			f[i]+=f[j];
		f[i]++;
		//mjt(f[i]); 
		//cout<<endl;
	}
	//dfs(n);
	cout<<f[n];
	return 0; 
}
//cin>>6; --> cout<<6;
//6  1,6  2,6  1,2,6  3,6  1,3,6 
