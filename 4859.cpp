#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 233;
int tot=0,c[maxn],v[maxn],f[maxn*maxn];
//f[j]：得到j的价值花的最小钱数 
int main(){
	int n,w;
	cin>>w>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i]>>v[i],tot+=v[i];
	memset(f,120,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=tot;j>=v[i];j--)
			f[j]=min(f[j],f[j-v[i]]+c[i]);
	for(int i=tot;i;i--)
		if(f[i]<=w){
			printf("%d\n",i);
			return 0;
		}
	puts("0"); 
}
