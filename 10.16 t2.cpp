
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1500001;//�����Խ��
int p[MAXN], n, into[MAXN];
bool vis[MAXN], aj[MAXN], die[MAXN];
struct Tqueue {
	int l, r, data[MAXN];
	void clear() {
		l = 1;
		r = 0;
	}
	bool empty() {
		return l > r;
	}
	void push(int t) {
		data[++r] = t;
	}
	int pop() {
		return data[l++];
	}
} Q;//��д����

//ȡ��Сֵ
//Q�����ǻ��ŵ��ˡ�
int getmin() {
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	memset(into, 0, sizeof(into));
	Q.clear();
	for (int i = 1; i <= n; i++) ++into[p[i]];
	for (int i = 1; i <= n; i++)
		if (into[i] == 0)
			Q.push(i), vis[i] = true;//��Щ����Ե�ã� ������
	while(!Q.empty()) {
		int x = Q.pop();//��Ȼ����������
		if (die[x]) continue;//Ŷ�� ˵�õ��Ҳ����أ�
		x = p[x];//��ô���������
		if (die[x]) continue;//Ŷ�� ���Ѿ�����
		++ans;//����������
		die[x] =true;
		vis[x] =true;//���� ���������� �ܺã� ������
		--into[p[x]];
		if (into[p[x]] == 0) Q.push(p[x]), vis[p[x]] = true;//������Ѿ��������ˣ� ��ӭ����Ӣ���
	}
	//�����ǵĿ������� ��
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			int t = p[i], len = 1;
			vis[p[i]] = true;
			while(t != i) {
				++len;
				t = p[t];
				vis[t] = true;
			}
			ans += 1 + ((len - 1) >> 1);//��С�������(len + 1) / 2
		}
	return ans;
}
int getmax() {
	int ans = n;
	memset(into, 0, sizeof(into));
	memset(vis, 0, sizeof(vis));
	memset(aj, 0, sizeof(aj));
	Q.clear();
	for (int i = 1; i <= n; i++) ++into[p[i]];
	for (int i = 1; i <= n; i++)
		if (into[i] == 0) {
			--ans;    //Ŷ�� ����������
			Q.push(i);
			vis[i] = true;
		}
	while(!Q.empty()) {
		int x = Q.pop();
		--into[p[x]];
		aj[p[x]] = true;
		if (into[p[x]] == 0) {
			Q.push(p[x]);
			vis[p[x]] = true;
		}
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) {
			//Ȼ��������ǻ���Ҫȫ�����
			int t = p[i];
			bool jc = aj[i];
			vis[i] = true;
			while(t != i) {
				vis[t] = true;
				jc |= aj[t];
				t = p[t];
			}
			if (!jc && (!(i == p[i]))) --ans;
		}
	return ans;
}
int main() {
	//freopen("kill.in", "r", stdin);
	//freopen("kill.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	printf("%d %d\n", getmax(), getmin());
}
