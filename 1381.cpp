#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	int np;
	scanf("%d", &np);
	string str[20],s;
	map<string, int> Have,Receive;
	for (int i = 1; i <= np; i++)
		cin >> str[i], Have[str[i]] = 0, Receive[str[i]] = 0;
	for(int i=1;i<=np;i++){
		cin>>s;
		int money, num;
		scanf("%d%d", &money, &num);
		if(num==0){
			Have[s]+=money;
			continue;
		}
		int MoneyForEverybody = money / num;
		Have[s] += MoneyForEverybody*num;
		while (num--) {
			string ss;
			cin >> ss;
			Receive[ss] += MoneyForEverybody;
		}
	}
	//puts("9efhi");
	for (int i = 1; i <= np; i++)
		cout << str[i] << " " << Receive[str[i]] - Have[str[i]] << endl;
}
