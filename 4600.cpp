#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<cmath>
#include<cctype>
#include<cstdlib>
#define D(x) cerr<<#x<<"="<<x<<" "

using namespace std;
const int inf=0x7fffffff;
const int maxn=100010;

inline long long read(){
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int fa[1000010],n;

long long find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void unionn(int a,int b){
	int fx=find(a),fy=find(b);
	if(fx==fy)return ;
	fa[fx]=fy;
}

void init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
}

struct node{
	int x,y;
}f[1000010];

int main(){
	int t;
	t=read();
	while(t--){
		map<int,int> m;
		map<int,int>::iterator it1,it2;
		n=read();init();
		int cnt=0,tot=0;
		for(int i=1;i<=n;i++){
			int x=read(),y=read(),e=read();
			if(e){
				it1=m.find(x);
				if(it1==m.end()){
					++tot;
					m[x]=tot;
					it1=m.find(x);
				}
				it2=m.find(y);
				if(it2==m.end()){
					++tot;
					m[y]=tot;
					it2=m.find(y);
				}
				unionn(it1->second,it2->second);
			}
			else f[++cnt]=(node){x,y};
		}
		int i;
		for(i=1;i<=cnt;i++){
			it1=m.find(f[i].x),it2=m.find(f[i].y);
			int x=find(it1->second),y=find(it2->second);
			if(x==y){
				puts("NO");
				break;
			}
		}
		if(i==cnt+1)puts("YES");
	}

}
//Sro orZ
//rp++,rp++,rp++
//cout<<"the time used:"<<(double)(clock())/CLOCKS_PER_SEC<<endl;

/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,f[50000001]= {0},t,k,e1=0,e2=0;
struct re {
	int x,y;
} a[10000001],b[10000001];
int find(int x) {
	if (f[x] == x) return f[x];
	f[x] = find(f[x]);
	return f[x];
}
int hash(int x) {
	return x%9999997;
}
inline long long get_num(){
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=10000001; i++) f[i]=i;
		e1=0;
		e2=0;
		for(int i=1; i<=n; i++) {
			int q,w,e;
			q=get_num();
			w=get_num();
			e=get_num();
			q=hash(q);
			w=hash(w);
			e=hash(e);
			if(e) {
				e1++;
				//a[e1].x=q;
				//a[e1].y=w;
				f[find(q)]=find(w);
			} else {
				e2++;
				b[e2].x=q;
				b[e2].y=w;
			}
		}
		bool v=1;
		for(int i=1; i<=e2; i++)
			if(find(b[i].x)==find(b[i].y))		v=0;
		if(!v)	cout<<"NO\n";
		else	cout<<"YES\n";
	}
}
*/
