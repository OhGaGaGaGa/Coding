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
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int main(){
	n=read();
	string a1,a2,he;
	cin>>a1>>a2>>he;
	map<char,int> ma;
	if(a1[n-1]==he[n-1])ma[a2[n-1]]=0;
	if(a2[n-1]==he[n-1])ma[a1[n-1]]=0;
}
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//cout<<"the time used:"<<(double)(clock())/CLOCKS_PER_SEC<<endl;

