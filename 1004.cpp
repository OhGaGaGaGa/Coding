#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char c;
int ans,a[10][10]= {0},end=0;
/*inline void swap(int &a, int &b) {
	int t; t = a; a = b; b = t;
}*/
inline bool check() {
	for (int k=1; k<=4; k++) {
		if (a[k][1]==a[k][2]&&a[k][2]==a[k][3]&&a[k][3]==a[k][4]) return 1;
		if (a[1][k]==a[2][k]&&a[2][k]==a[3][k]&&a[3][k]==a[4][k]) return 1;
	}
	if (a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&a[3][3]==a[4][4]) return 1;
	if (a[1][4]==a[2][3]&&a[2][3]==a[3][2]&&a[3][2]==a[4][1]) return 1;
	return 0;
}
void dfs(int last,int cnt,int fromx,int fromy) {
	if(end)return;
	if(cnt>=ans) {
		if(check())	end=1;
		return;
	}
	int mod=((last==0)?1:0);
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++)
			if(a[i][j]==-1) {
				if(i-1>0&&i-1<5&&j>0&&j<5&&!(i-1==fromx&&j==fromy))
					if(a[i-1][j]==mod) {
						a[i][j]=mod;
						a[i-1][j]=-1;
						dfs(mod,cnt+1,i,j);
						a[i-1][j]=mod;
						a[i][j]=-1;
					}
				if(j+1>0&&j+1<5&&i>0&&i<5&&!(i==fromx&&j+1==fromy))
					if(a[i][j+1]==mod) {
						a[i][j]=mod;
						a[i][j+1]=-1;
						dfs(mod,cnt+1,i,j);
						a[i][j+1]=mod;
						a[i][j]=-1;
					}
				if(i+1>0&&i+1<5&&j>0&&j<5&&!(i+1==fromx&&j==fromy))
					if(a[i+1][j]==mod) {
						a[i][j]=mod;
						a[i+1][j]=-1;
						dfs(mod,cnt+1,i,j);
						a[i+1][j]=mod;
						a[i][j]=-1;
					}
				if(j-1>0&&j-1<5&&i<5&&i>0&&!(i==fromx&&j-1==fromy))
					if(a[i][j-1]==mod) {
						a[i][j]=mod;
						a[i][j-1]=-1;
						dfs(mod,cnt+1,i,j);
						a[i][j-1]=mod;
						a[i][j]=-1;
					}
			}
}
int main() {
	//memset(a,0x3f,sizeof(a));
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++) {
			cin>>c;
			if(c=='B')a[i][j]=1;
			if(c=='W')a[i][j]=0;
			if(c=='O')a[i][j]=-1;
			//cout<<a[i][j]<<" ";
		}
	/*for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}*/
	
	for(ans=1; !end; ans++) {
		dfs(1,0,0,0);
		if(end) {
			cout<<ans<<endl;
			return 0;
		}
		dfs(0,0,0,0);
		if(end) {
			cout<<ans<<endl;
			return 0;
		}

	}
	printf("%d\n",ans);
	return 0;
}
