int dfn[maxn],low[maxn];
int belong[maxn],top,cnt,stack[maxn],comnum,num[maxn];
bool instack[maxn];
void tarjan(int x){
	dfn[x]=low[x]=++cnt;
	stack[++top]=x;
	instack[x]=1;
	for(int i=head[x];i!=-1;i=head[x].nxt){
		int j=e[i].to;
		if(!dfn[j]){
			tarjan(j);
			low[x]=min(low[x],low[j]);
		}
		else if(instack[j]&&dfn[j]==low[j]){
			low[x]=dfn[j];
			return ;
		}
	}
	if(dfn[x]==low[x]){
		int j;
		comnum++;
		do{
			j=stack[top--];
			instack[j]=false;
			belong[j]=comnum;
			num[Bcnt]++;
		}while(x!=j)
	}
}