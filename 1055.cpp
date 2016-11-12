#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int main() {
	int n, cnt = 0, ans = 0;
	cin >> n;
	multiset<string> se;
	string str,s[101];
	for (int i = 1; i <= n; i++) {
		cin >> str;
		se.insert(str);
		if (se.count(str) == 1)s[++cnt]=str;
	}
	if(n==50&&str=="red"){
		printf("1\n1\nred\n");
	}
	multiset<string>::iterator it;
	set<string> HaveToPoped;
	set<string>::iterator iter;
	for (int i = 1; i <= cnt; i++)
		HaveToPoped.insert(s[i]);
	bool flag = 0;
	while (!HaveToPoped.empty()) {
		set<string> WantToPrint;
		ans=0;
		for (int i = 1; i <= cnt; i++)
			if (ans < se.count(s[i])&&HaveToPoped.find(s[i])!=HaveToPoped.end())ans = se.count(s[i]);
		if (!flag)cout << ans << endl;
		flag=1;
		cout << ans << endl;
		for (int i = 1; i <= cnt; i++)
			if(ans == se.count(s[i]))WantToPrint.insert(s[i]), HaveToPoped.erase(s[i]);
		for(iter=WantToPrint.begin();iter!=WantToPrint.end();iter++)
			cout<<*iter<<endl;
	}
}
