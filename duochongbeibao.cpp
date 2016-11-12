#include<cstdio>
#include<iostream>
using std::max;
int v[6002],w[6002],s[6002],f[6002],n,m;
int main(){
	freopen("beibao.in","r",stdin);
	freopen("beibao.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&v[i],&w[i],&s[i]);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)
			for(int k=0;k<=s[i];k++){
				if(j-k*v[i]<0)break;
				f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
			}
	printf("%d",f[m])	;	
}
