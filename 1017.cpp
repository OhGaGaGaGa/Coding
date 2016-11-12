#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[50];
long long a[50],f[50][10],cheng[100][100];
int main() {
	int n,k;
	cin>>n>>k>>str;
	for(int i=0; i<n; i++)
		a[i+1]=str[i]-'0';
	for(int i=1; i<=n; i++) cheng[i][i]=a[i];
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
			cheng[i][j]=cheng[i][j-1]*10+a[j];
	f[0][0]=0;
	for(int i=1; i<=n; i++)
		f[i][0]=f[i-1][0]*10+a[i];
	for(int i=1; i<=n; i++)
		for(int k=1; k<i; k++)
			for(int j=1; j<i; j++)
				f[i][k]=max(f[i][k],f[j][k-1]*cheng[j+1][i]);
	cout<<f[n][k];
}
/*
4 2 1231
cout<<62;
*/
