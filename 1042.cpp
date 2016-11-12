#include <cstdio>
using namespace std;
int N, R;
bool dfs(int now, int t) {
	if(t>500000)return false;
	int i, ans;
	for(i=0; i<-R; i++) {
		if(now+i*t==N) {
			printf("%c",i<10?i+48:i-10+'A');
			return true;
		}
		if(dfs(now+i*t,t*R)) {
			printf("%c",i<10?i+48:i-10+'A');
			return true;
		}
	}
	return false;
}
int main() {
	while(~scanf("%d%d",&N,&R))
		printf("%d=",N),dfs(0,1),printf("(base%d)\n",R);
	return 0;
}
