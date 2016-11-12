#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
map<string,int> bei;
map<string,int>::iterator it;
bool vis[1000010];
int b[100010];
int main() {
	//hash
	int m,n,cnt=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		string str;
		++cnt;
		cin>>str;
		bei[str]=cnt;
		//bei.insert(pair<string,int>(str,cnt));
	}
	scanf("%d",&m);
	cnt=0;
	int tot=0;
	for(int i=1; i<=m; i++) {
		string str;
		++cnt;
		cin>>str;
		it=bei.find(str);
		b[cnt]=0;
		if(it!=bei.end()) {
			if(!vis[it->second])++tot;
			vis[it->second]=1;
			b[cnt]=(it->second);
		}
	}
	printf("%d\n",tot);

	memset(vis,0,sizeof(vis));
//	map<string,int>::iterator l,r;
	int ans=0x7fffffff,l=0,r=0;
	cnt=0;
	static int fword[100010]={0};
	while(l<=r) {
		while(r<m) {
			++r;
			if(b[r]==0) continue;
			++fword[b[r]];
			if(fword[b[r]]==1)cnt++;
			if(cnt==tot)break;
		}
		while(l<=r) {
			if(b[l]==0) {
				l++;
				continue;
			}
			if(fword[b[l]]>1)fword[b[l]]--,l++;
			if(fword[b[l]]==1)break;
		}
		ans=min(ans,r-l+1);
//??cout<<"l,r"<<l<<"?"<<r<<"?"<<ans<<endl;??
		if(r>=m)break;
	}
	printf("%d\n",ans);
}
