#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define mjt(x) cerr<<#x<<"="<<x<<" "
using namespace std;
int f[10110][1000];
int main(){
	int m,s,t;
	cin>>m>>s>>t;
	for(int i=0;i<t;i++){
		for(int k=0;k<=m;k++){
			//mjt(i);mjt(k);mjt(f[i][k]);
			f[i+1][k]=max(f[i+1][k],f[i][k]+17);//mjt(f[i+1][k]);
			f[i+1][k+10]=max(f[i+1][k+10],f[i][k]+60);//mjt(f[i+1][k+10]);
			if(k>=4)f[i+1][k-4]=max(f[i+1][k-4],f[i][k]);//,mjt(f[i+1][k-4]);
			//mjt(f[i][k]);
			//cout<<endl;
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++)
		ans=max(ans,f[t][i]);
	if(ans>=s){
		cout<<"Yes"<<endl;//<<ans<<endl;
		int i,k; 
		for(i=1;i<=t;i++)
			for(k=m;k>=0;k--){
				//mjt(i);mjt(k);mjt(f[i][k]);
				//cout<<endl;
				if(f[i][k]>=s){
					cout<<i<<endl;
					return 0;
				}
			}
	}
	else {
		cout<<"No"<<endl<<ans<<endl;
	}
}
