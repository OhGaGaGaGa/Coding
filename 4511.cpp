#include<iostream>
using namespace std;
const int maxn = 200010;
int getint(){
	int a=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){a=a*10+c-'0';c=getchar();}
	return a*f;
}
struct node{
	int a,b;
}t[maxn];
int ru[maxn],chu[maxn];
int main(){
	int n;
	n=getint();
	for (int x,i = 1; i < n; ++i){
		x=getint();t[i]=(node){i,x};
	}
	
}