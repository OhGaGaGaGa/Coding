#include<iostream>
#include<algorithm>
using namespace std;
int group,n,x,y,hmax;
struct node{
	int x1,x2;
	int h;
}step[50010];
bool cmp(const node *a,const node *b){
	if(a.h>b.h)return true;
	else return false;
}
void dp(){
	
}
int main(){
	cin>>group;
	while(group--){
		cin>>n>>x>>y>>hmax;
		step[0].x1=step[0].x2=x,step[0].h=y;
		for(int i=1;i<=n;i++)
			cin>>step[i].x1>>step[i].x2>>step[i].h;
		sort(step,step+n+1,cmp);
		
	}
} 
