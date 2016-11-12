#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,k,m,s,t,c[100010],a[1010][1010],d[1010][1010];

int main(){
	memset(d,0x3f,sizeof(d));
	cin>>n>>k>>m>>s>>t;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			cin>>a[i][j];
	for(int i=1,u,v,dis;i<=m;i++)
		cin>>u>>v>>dis,d[u][v]=dis;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(d[i][k]+d[k][j]<d[i][j]&&!a[c[i]][c[j]]&&!a[c[i]][c[k]]&&!a[c[k]][c[j]])
					d[i][j]=d[i][k]+d[k][j];
			}
	if(d[s][t]>=0x3f3f3f3f)cout<<-1<<endl;
	else cout<<d[s][t];
}
