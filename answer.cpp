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
#define ull unsigned long long
using namespace std;
const int inf=0x7fffffff;
const int maxn=30010;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,p,q;
bool s[maxn][505];
bool check(bool *str);
bool str[maxn];
bool dfs(int cnt){
	if(m==cnt){
		if(check(str)){
			for(int i=0;i<m;i++)
				if(str[i])printf("Y");
				else printf("N");
			puts("");
			return 1;
		}
		return 0;
	}
	str[cnt]=0;
	if(dfs(cnt+1))return 1;
	str[cnt]=1;
	if(dfs(cnt+1))return 1;
	return 0;
}
bool check(bool* str){
	int _1=0,_0=0;
	for(int i=1;i<=n;i++){
		int flag_true=0,flag_false=0;
		for(int j=0;j<m;j++){
			if((str[j]&&s[i][j])||((!str[j])&&(!s[i][j])))flag_true++;
			else flag_false++;
		}
		if(flag_true==m)_1++;
		if(flag_false==m)_0++;
	}
	if(_1==p&&_0==q)return 1;
	return 0;
}
int main(){
	freopen("answer.in","r",stdin);
	freopen("answer.out","w",stdout);
	memset(s,0,sizeof(s));
	n=read(),m=read(),p=read(),q=read();
	for(int i=1;i<=n;i++){
		char c[505];
		scanf("%s",c);
		for(int j=0;j<m;j++){
			if(c[j]=='Y')s[i][j]=1;
			else s[i][j]=0;
		}
	}
		
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++)
			cout<<s[i][j];
		puts("");
	}*/
	
	if(!dfs(0))puts("-1");
	return 0;
}
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//cout<<"the time used:"<<(double)(clock())/CLOCKS_PER_SEC<<endl;
/*
4 4 1 0
YNNN
YYYN
NNNY
NYNY
*/
