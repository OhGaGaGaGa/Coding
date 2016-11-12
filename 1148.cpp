#include<bits/stdc++.h>
using namespace std;
int n,m,f[2010][2010];
int dfs(int num,int cnt) { //传了cnt次到第num个人
	if(num==0)num=n;
	if(num>n)num-=n;
	if(cnt==0) {
		if(num==n)	return 1;
		return 0;
	}
	if(f[num][cnt])return f[num][cnt];
	f[num][cnt]=dfs(num-1,cnt-1)+dfs(num+1,cnt-1);
	return f[num][cnt];
}
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int dp() {
	f[0][0]=1;
	f[n][0]=1;
	for(int j=1; j<=m; j++) {
		for(int i=1; i<=n; i++) {
			int l=i-1,r=i+1;
			if(l<1) l+=n;
			if(r>n) r-=n;
			f[i][j]=f[l][j-1]+f[r][j-1];
		}
	}
	return f[n][m];
}
int main() {
	n=read();
	m=read();
	printf("%d\n",dp());
	return 0;
	/*
	f[0][0]=1;
	f[0][1]=0;
	f[0][2]=2;
	f[1][1]=1;

	f[n][m]=f[n-1][m-1]+f[n+1][m-1];//第n个人，传了m次
	*/
}
