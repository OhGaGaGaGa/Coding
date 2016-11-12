#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
	int n,tot=0;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i],tot+=a[i];
	int sum=(tot/n);
	//cout<<sum<<endl;
	int ans=0,num=0;
	for(int i=1; i<=n; i++) {
		if(a[i]==sum)continue;
		if(a[i]>sum) {
			ans=a[i]-sum;
			a[i]-=ans;
			a[i+1]+=ans;
			num++;
		}
		if(a[i]<sum) {
			ans=sum-a[i];
			a[i]+=ans;
			a[i+1]-=ans;
			num++;
		}
	}
	cout<<num<<endl;
}
