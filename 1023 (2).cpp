#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	static double a,b[10000],c[10000],m=0,n=0;
	cin>>a;
	for(int i=1;i<=a;++i)	cin>>b[i]>>c[i]; 
	for(int i=1;i<=a;++i)	m+=b[i],n+=c[i]*b[i];
	printf("%.2f",n/m);
	return 0;
}