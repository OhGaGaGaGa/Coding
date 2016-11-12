#include<bits/stdc++.h>
using namespace std;
char str[100010];
int main(){
	char c;
	int cnt=-1;
	while(c=getchar()){
		if(c=='E')break;
		if(c=='\n'||c=='\r'||c=='	'||c==' ')continue;
		str[++cnt]=c;
	}
	if(cnt==-1){
		printf("0:0\n\n0:0\n");
		return 0;
	}
	int win11=0,win21=0,lose11=0,lose21=0;
	for(int i=0;i<=cnt;i++){
		if(str[i]=='W'){
			win11++;
			if(win11==11){
				printf("%d:%d\n",win11,lose11);
				win11=0;lose11=0;
				continue;
			}
		}
		else {
			lose11++;
			if(lose11==11){
				printf("%d:%d\n",win11,lose11);
				win11=0;lose11=0;
				continue;
			}
		}
	}
	printf("%d:%d\n\n",win11,lose11);
	for(int i=0;i<=cnt;i++){
		if(str[i]=='W'){
			win21++;
			if(win21==21){
				printf("%d:%d\n",win21,lose21);
				win21=0;lose21=0;
				continue;
			}
		}
		else {
			lose21++;
			if(lose21==21){
				printf("%d:%d\n",win21,lose21);
				win21=0;lose21=0;
				continue;
			}
		}
	}
	printf("%d:%d\n",win21,lose21);
}
