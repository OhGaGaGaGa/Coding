#include<iostream>
#include<cstring>
#include<set>
using namespace std;
char s[1000010];
int main() {
	scanf("%s", s);
	set<char> se;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (se.find(s[i]) != se.end())se.erase(s[i]);
		else se.insert(s[i]);
	}
	cout << se.size() << endl;
}
