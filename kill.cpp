#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,kill[1000010],ru[1000010],chu[1000010];
int main() {
	//freopen("kill.in","r",stdin);
	//freopen("kill.out","w",stdout);
	cin>>n;
	for(int i=1,x; i<=n; i++) {
		scanf("%d",&x);
		e[i][x]=1;
		ru[kill[i]]++;
		chu[i]++;
	}
	static int ans=0,f[100010]={0};
	while(1){
		static int sk[100010],tot=0;
		for(int i=1;i<=n;i++){
			if(!chu[i]&&!f[i])
				sk[++tot]=i,f[i]=1;
			else if(ru[i]&&kill[i]&&ru[kill[i]]>1&&!f[i])
				ru[kill[i]]--,kill[i]=0,sk[++tot]=i,f[i]=1;
		}
		
	}
	

}
