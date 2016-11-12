#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100010],f[2016][2016];
int main(){
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=a[1];i++)
		f[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=j&&k<=a[i];k++)
				f[i][j]=(f[i][j]+f[i-1][j-k])%1000007;
//	for(int i=0;i<=m;i++)
//		ans=max(ans,f[n][i]);
	cout<<f[n][m]%1000007<<endl; 
} 
