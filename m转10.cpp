#include<bits/stdc++.h>
using namespace std;
int main() {
	int m;
	char n[20];
	scanf("%s%d",n,&m);
	int ans=0;
	int len=strlen(n);
	for(int i=len-1,k=1; i>=0; i--,k*=m) {
		int j;
		if(isdigit(n[i])) j=(n[i]-'0');
		else {
			j=(n[i]-'A'+10);
		}
		j*=k;ans+=j;
	}
	cout<<ans;
	//while(1);
}
/*

#include <stdio.h>
#include <string.h>
int main() {
	int n,i,j,k,m,sum=0;
	char a[10];
	scanf("%s",a);
	scanf("%d",&n);
	m=strlen(a);
	for(i=m-1,k=1; i>=0; i--,k*=n) {
		if(a[i]>='0'&&a[i]<='9')
			j=a[i]-'0';
		if(a[i]>='A'&&a[i]<='G')
			j=a[i]-'A'+10;
		if(a[i]>='a'&&a[i]<='g')
			j=a[i]-'a'+10;
		j*=k;
		sum+=j;
	}
	printf("%d",sum);
	return 0;
}*/
