#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int x1,x2,y1,y2,n;
	cin>>x1>>y1>>x2>>y2>>n;
	pair<long long,long long> d[100010];
	for(int i=1,x,y;i<=n;i++){
		cin>>x>>y;
		d[i].first=(x1-x)*(x1-x)+(y1-y)*(y1-y);
		d[i].second=(x2-x)*(x2-x)+(y2-y)*(y2-y);
	} 
	sort(d+1,d+n+1);
	int d1=0,d2=0;
	for(int i=1;i<=n;i++){
		if(d1>=d[i].first)continue;
		if(d[i].first-d1<d[i].second-d2)d1=d[i].first;
		else d2=d[i].second;
	}
	cout<<d1+d2<<endl;
}
/*int main(){
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	int n;
	cin>>n;
	int ans=0x7fffffff;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i],
		d1[i]=(x1-x[i])*(x1-x[i])+(y1-y[i])*(y1-y[i]),
		d2[i]=(x2-x[i])*(x2-x[i])+(y2-y[i])*(y2-y[i]);
	for(int i=1;i<=n;i++){
		int d=d1[i],_d=0;
		for(int j=1;j<=n;j++){
			if(d1[j]>d) _d=max(_d,d2[j]);
		}
		ans=min(ans,d+_d);
	}
	cout<<ans;
} */
