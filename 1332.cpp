#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
//codevs 1332
using namespace std;
#define D(x) cerr<<#x<<"="<<x<<" "
#define E() puts("");
const int maxn = 200010;
const int inf = 0x7fffffff;
int head[maxn],cntt;
struct node {
	int to,nxt;
} e[maxn<<1];
void add_edge(int u,int v) {
	e[++cntt].to=v;
	e[cntt].nxt=head[u];
	head[u]=cntt;
}
/*
int DFN[maxn],LOW[maxn];
int Belong[maxn],Dindex,Stop,Stap[maxn],Bcnt,Num[maxn];
bool instack[maxn];
//Dindex:   the time of every elements
//Stop:     the num of elements in the stack 
//Belong[i]:the element "i" is belong to the Belong[i] Component
//Stap[]:   the stack
//Bcnt:     the num of Components
//Num[i]:   the element num of i is Num[i] 
set<int> se[maxn];
void tarjan(int i) {
	DFN[i]=LOW[i]=++Dindex;
	instack[i]=true;
	Stap[++Stop]=i;
	for(int x=head[i]; x!=-1; x=e[i].nxt) {
		int j=e[x].to;
		if (!DFN[j])  {
			tarjan(j);
			LOW[i]=min(LOW[i],LOW[j]);
		}
		else if (instack[j] && DFN[j]<LOW[i])
			LOW[i]=DFN[j];
	}
	if (DFN[i]==LOW[i]) {
		Bcnt++;
		int j;
		do {
			j=Stap[Stop--];
			instack[j]=false;
			Belong[j]=Bcnt;
			Num[Bcnt]++;
			se[Bcnt].insert(j);
		} while (j!=i);
	}
}
*/
set<int> se[maxn];
int dfn[maxn],low[maxn];
int belong[maxn],top,cnt,stack[maxn],comnum,num[maxn];
void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	stack[++top]=x;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int j=e[i].to;
		if(!dfn[j]){
			tarjan(j);
			low[x]=min(low[x],low[j]);
		}
		else if(!belong[j])
			low[x]=min(low[x],dfn[j]);
	}
	if(dfn[x]==low[x]){
		int j;
		comnum++;
		do{
			j=stack[top--];
			belong[j]=comnum;
			num[comnum]++;
			se[comnum].insert(j);
		}while(x!=j);
	}
}
int getint() {
	int a=0,f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)) {a=a*10+c-'0';c=getchar();}
	return a*f;
}
int n;
int main() {
	memset(dfn,0,sizeof(dfn));
	memset(head,-1,sizeof(head));
	n=getint();
	int m=getint();
	for(int i=1; i<=m; i++){
		int a=getint(),b=getint(),t=getint();
		if(t==1)add_edge(a,b);
		else{
			if(a!=b)add_edge(a,b),add_edge(b,a);
			/*else{
				Bcnt++;//DFN[];LOW[];
				Belong[a]=Bcnt;
				Num[Bcnt]=1;
				se[Bcnt].insert(a);
			}	*/
		}
	}
	for (int i=1; i<=n; i++)
		if (!dfn[i])
			tarjan(i);
	//for(int i=1;i<=n;i++)
	//	D(i),D(belong[i]),E();
	int ans=0;
	cout<<comnum<<endl;
	/*for(int i = 1; i <= comnum; i++){
		for(set<int>::iterator it=se[i].begin();it!=se[i].end();it++)
			printf("%d ",*it);
		puts("");
	}*/
	for(int i=1;i<=comnum;i++)
		ans=max(num[i],ans);
	printf("%d\n",ans);
	int front=0x7fffffff,willprint;
	for(int i=1;i<=comnum;i++)
		if(ans==num[i])
			if(front>(*se[i].begin()))
				front=(*se[i].begin()),willprint=i;
	for(set<int>::iterator it=se[willprint].begin();it!=se[willprint].end();it++)
		printf("%d ",*it);
	puts("");
	return 0;
}

