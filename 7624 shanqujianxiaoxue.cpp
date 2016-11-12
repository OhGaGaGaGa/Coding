#include<iostream>
using namespace std;
int m,n,l[1010][1000],r[1000][1000],w[100010],s[100010];
int main(){
	cin>>m>>n;
	for(int i=1;i<=m-1;i++)
		cin>>w[i],s[i]=s[i-1]+w[i];
	for(int i=1;i<=m-1;i++)
		l[i][1]=s[i-1],r[i][1]=s[m-1]-s[i];
	for(int k=2;k<=n;k++)
		for(int i=1;i<=m-1;i++)
			for(int j=i+1;j<=m-2;j++){
				l[j][k]=s[j]
			}
	return 0;
}
