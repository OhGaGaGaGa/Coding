/*#include<cstdlib>
#include<stdio.h>
int main(){
	bool flag=false;
	while(!flag){
		system("gen.exe");
		system("count.exe");//baoli
		system("mod.exe");//biaocheng
		//printf("%s",system("fc count.out mod.out"));
		flag=system("fc count.out mod.out");
	}
	system("pause");
	return 0;
} */ 
#include<iostream>
#include<windows.h>
using namespace std;
int main(){
	int t=100;
	while(t--)	{
		system("data > a+b.in");
		system("count < a+b.in > 1.out");
		system("mod < a+b.in > 2.out");
		if(system("fc 1.out 2.out"))  break;
	}
	system("pause");
	return 0;
}
