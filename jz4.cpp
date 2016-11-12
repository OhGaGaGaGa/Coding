#include <cstdio>
#include <iostream>
using namespace std;
int t,n,q;
void mp(int a[4],int b[4],int *c){
	c[0]=(a[0]*b[0]+a[1]*b[2])%10;
	c[1]=(a[0]*b[1]+a[1]*b[3])%10;
	c[2]=(a[2]*b[0]+a[3]*b[2])%10;
	c[3]=(a[2]*b[1]+a[3]*b[3])%10;
}
int main(){
	scanf("%d",&n);
	int a[2]={1,1},f[30][4]={0,1,1,1},b[30],s[4]={1,0,0,1},tp[4],k=0;
	n--;
	b[k++]=n%2;
	n/=2;
	while(n>0){
		mp(f[k-1],f[k-1],f[k]);
		b[k++]=n%2;
		n/=2;
	}
	for(int i=0;i<k;i++){
		if(b[i]>0){
			mp(s,f[i],tp);
			s[0]=tp[0];
			s[1]=tp[1];
			s[2]=tp[2];
			s[3]=tp[3];
		}
	}
	printf("%d\n",(s[2]+s[3])%10);
	return 0;
}
