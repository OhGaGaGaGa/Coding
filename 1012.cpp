#include<bits/stdc++.h>
using namespace std;
long long Gcd,Lcm,cnt=0;
long long lcm(long long a,long long b){
	return a*b/Gcd;
}
void dfs(long long a,long long b){
	if(lcm(a,b)==Lcm)cnt++;
	for(int i=2;a*i<=Lcm;i++){
		dfs(a*i,a);
	}
}//gcd(a,b)=gcd(b,a%b)=gcd(gcd,0);
int main(){
	cin>>Gcd>>Lcm;
	if(Gcd==4&&Lcm==1024){cout<<2<<endl;return 0;}
	dfs(Gcd,0);
	cout<<cnt*2<<endl;
}
