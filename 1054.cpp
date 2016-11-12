#include<iostream>
using namespace std;
int main() {
	int n, last = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (last == x) {
			continue;
		}
		if (last < x) {
			ans += 5;
			ans += ((x - last) * 6);
		}
		if (last > x) {
			ans += 5;
			ans += ((last - x) * 4);
		}
		last=x;
	}
	cout << ans << endl;
}
