#include<iostream>
#include<cstdio>
using namespace std;
int a[30][30],f[30][30],cnt=0;
void dfs(int x,int y){
	if(x==n){
		maxn=max(maxn,cnt%100);
	}
	dfs(x+1,y);cnt-=a[]
	dfs(x+1,y+1);cnt-=
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	/*for(int i=1;i<=n;i++)
		f[n][i]=a[n][i];
	for(int i=n-1;i;i--){
		for(int j=1;j<=i;j++){
			if((a[i][j]+f[i+1][j])%100>(a[i][j]+f[i+1][j+1])%100)
				f[i][j]=(a[i][j]+f[i+1][j])%100;
			else 
				f[i][j]=(a[i][j]+f[i+1][j+1])%100;
		}
	}
	printf("%d",f[1][1]);*/ 
}
