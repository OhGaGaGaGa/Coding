#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	static bool a[323];
	memset(a, 0, sizeof(a));
	for (int i = 1; i *3<= n; i++)
		a[i * 3] = 1;
	for (int i = 1; i * 5 <= n; i++)
		a[i * 5] = 1;
	for (int i = 1; i <= n; i++)
		if ((i % 10 == 3)||(i % 10 == 5)||(i % 100 >= 50 && i % 100 <= 59)||(i % 100 >= 30 && i % 100 <= 39))
			a[i] = 1;
	unsigned long long ans = 0;
	for (int i = 1; i <= n; i++)
		if (!a[i])ans += (i*i);
	cout<<ans<<endl;
}
