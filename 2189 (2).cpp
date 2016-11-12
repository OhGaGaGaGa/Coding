#include<bits/stdc++.h>
using namespace std;
int a[30][30];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>a[i][j];
	static bool f[30][30][100];
	for(int i=1;i<=n;i++)
		f[n][i][a[n][i]]=1;
	for(int i=n-1;i;i--)
		for(int j=1;j<=i;j++)
			for(int k=0;k<100;k++)
				if(f[i+1][j][k]||f[i+1][j+1][k]) 
					f[i][j][(k+a[i][j])%100]=1;
	for(int i=99;i>=0;i--)
		if(f[1][1][i]){
			printf("%d\n",i);
			return 0;
		}
	puts("0");
}
