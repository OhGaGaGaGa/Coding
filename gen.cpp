#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	freopen("count.in","w",stdout);
	srand(time(NULL));
	cout<<rand()%1000+1000<<" "<<rand()%1000+1000<<endl;
}
