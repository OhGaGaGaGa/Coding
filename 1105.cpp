#include<bits/stdc++.h>
using namespace std;//the mark is 30
int l,minx,maxx,n,f[20010],ans=9999999,ddd,d[20010];
bool a[10011];
int main(){
	memset(f,0x3f,sizeof(f));
	scanf("%d%d%d%d",&l,&minx,&maxx,&n);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),d[i]=x,a[x]=1,ddd=max(ddd,x);
	int k=0;f[0]=0;
	for(int i=0;i<=l;i++)
		for(int j=i+minx;j<=i+maxx;j++)
			if(a[j]) f[j]=min(f[j],f[i]+1);
			//else f[j]=min(f[i],f[j]);
	for(int i=ddd+1;i<=l+maxx;i++)
		ans=min(ans,f[i]);
	printf("%d",ans);
} //codevs 1105
