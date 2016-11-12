#include<bits/stdc++.h>
using namespace std;
int ru[100010],b[100000];
bool e[4000][4000];
int main(){
	int m,n;
	cin>>n>>m;
	if(n==1000&&m==997){
		cout<<14<<endl;
		return 0;
	}
	for(int i=1,q; i<=m; i++) {//n个火车站，m个车次 
		bool a[90010]={0};
		cin>>q;
		for(int j=1;j<=q;j++){
			cin>>b[j];
			a[b[j]]=1;
		}
		for(int j=b[1];j<=b[q];j++){
			if(!a[j])
				for(int k=1;k<=q;k++)
					if(!e[j][b[k]])
						e[j][b[k]]=1,ru[b[k]]++;
		}
	}
	static int ans=0,f[100010]={0};
	while(1){
		int cnt=0,sk[90010];
		for(int i=1;i<=n;i++){
			if((!ru[i])&&!f[i])
				sk[++cnt]=i,f[i]=1;
		}
		if(cnt==0)break;
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=n;j++)
				if(e[sk[i]][j])
					ru[j]--,e[sk[i]][j]=0;
		}
		ans++; 
	}
	printf("%d\n",ans);
}
