#include<iostream>
#include<cstdio>
using namespace std;
int a[100][100];
int main() {
	int n;
	scanf("%d",&n);
	a[1][(n>>1)+1]=1;
	int lastx=1,lasty=((n>>1)+1);
	for(int i=2; i<=n*n; i++) {
		if(lastx==1&&lasty!=n) {
			a[n][lasty+1]=i;
			lastx=n,lasty=lasty+1;
		} else if(lasty==n&&lastx!=1) {
			a[lastx-1][1]=i;
			lastx=lastx-1,lasty=1;
		} else if(lastx==1&&lasty==n) {
			a[2][n]=i;
			lastx=2,lasty=n;
		} else {
			if(!a[lastx-1][lasty+1]) {
				a[lastx-1][lasty+1]=i;
				lastx--;
				lasty++;
			} else {
				a[lastx+1][lasty]=i;
				lastx++;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		printf("%d",a[i][1]);
		for(int j=2; j<=n; j++)
			printf(" %d",a[i][j]);
		puts("");
	}
}
