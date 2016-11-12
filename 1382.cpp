#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[1000010],f[2000][2000],s[1000010];
int main(){
	int n;
	cin>>n;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		cin>>a[i],f[i][i]=0,s[i]=s[i-1]+a[i];
	for(int len=2;len<=n;len++)
		for(int i=1;i<=n-len+1;i++)
			for(int k=i;k<len+i-1;k++){
				int j=len+i-1;
				f[i][j]=min(f[i][k]+f[k+1][j]+s[j]-s[i-1],f[i][j]);
			}
				
	cout<<f[1][n]<<endl;
//	int c=7;
	//while(c)printf("%c",c);
}
