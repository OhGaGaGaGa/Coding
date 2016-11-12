#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1010];
int main(){
	//freopen("password.in","r",stdin);
	//freopen("password.out","w",stdout);
	int n,key;
	scanf("%d%d",&n,&key);
//	printf("%d\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	unsigned long long tot=(1<<n);
	long long ans=0;
	for(int i=1;i<tot;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				cnt+=a[j];
			}
		}
		if(cnt==key)ans++;
	}
	cout<<ans<<endl;
}
